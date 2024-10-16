/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:02:43 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 21:34:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include "../includes/Colors.hpp"

PmergeMe::PmergeMe(void) { return; }

PmergeMe::PmergeMe(char **av) : _av(av) {
  std::cout << "Before:\t";
  for (size_t i = 0; av[i]; ++i) {
    std::cout << av[i] << " ";
  }
  std::cout << std::endl;
  return;
}

PmergeMe::PmergeMe(const PmergeMe& src) : _av(src._av) {
  *this = src;
  return;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& src) {
  if (this != &src) {
    this->_av = src._av;
  }
  return (*this);
}

PmergeMe::~PmergeMe() { return; }

static bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.second < b.second);
}

void PmergeMe::insertNumber(std::vector<int>& array, int number) {
    std::vector<int>::iterator it = std::upper_bound(array.begin(), array.end(), number);
    array.insert(it, number);
}

void PmergeMe::buildPairs(std::vector<std::pair<int, int> >& pairs) {
  for (size_t i = 0; i + 1 < _arr.size(); i += 2) {
    if (_arr[i] < _arr[i + 1]) {
      pairs.push_back(std::make_pair(_arr[i], _arr[i + 1]));
    } else {
      pairs.push_back(std::make_pair(_arr[i + 1], _arr[i]));
    }
  }
}

void PmergeMe::putInSmallAndLarge(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
      _smalls.push_back(pairs[i].first);
      _larges.push_back(pairs[i].second);
    }
}



void PmergeMe::fordJohnsonSortVector(void) {
    std::vector<std::pair<int, int> > pairs;
    int                               oddOneOut = -1;

    buildPairs(pairs);
    if (_arr.size() % 2 != 0)
        oddOneOut = _arr.back();

    std::sort(pairs.begin(), pairs.end(), comparePairs);
    putInSmallAndLarge(pairs);

    for (size_t i = 0; i < _smalls.size(); ++i)
        insertNumber(_larges, _smalls[i]);

    if (oddOneOut != -1)
        insertNumber(_larges, oddOneOut);

    _arr = _larges;
}



void PmergeMe::fillArray(void) {
  for (size_t i = 0; _av[i]; ++i) {
    std::string arg(_av[i]);
    _arr.push_back(atoi(arg.c_str()));
  }
}

void PmergeMe::buildPairsList(std::list<std::pair<int, int> >& pairs) {
  std::list<int>::iterator it = _list.begin();
  while (it != _list.end()) {
    int first = *it;
    ++it;
    if (it == _list.end())
      break;
    int second = *it;
    if (first < second)
      pairs.push_back(std::make_pair(first, second));
    else
      pairs.push_back(std::make_pair(second, first));
    ++it;
  }
}

void PmergeMe::putInSmallAndLargeList(std::list<std::pair<int, int> >& pairs) {
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    _smallsList.push_back(it->first);
    _largesList.push_back(it->second);
  }
}

void insertNumberList(std::list<int>& list, int number) {
  std::list<int>::iterator it = std::upper_bound(list.begin(), list.end(), number);
  list.insert(it, number);
}

void PmergeMe::fordJohnsonSortList(void) {
  std::list<std::pair<int, int> > pairs;
  int                             oddOneOut = -1;

  buildPairsList(pairs);
  if (_list.size() % 2 != 0)
    oddOneOut = _list.back();

  pairs.sort(comparePairs);
  putInSmallAndLargeList(pairs);

  std::list<int>::iterator it = _smallsList.begin();
  while (it != _smallsList.end()) {
      int number = *it;
      insertNumberList(_largesList, number);
      ++it;
  }
  if (oddOneOut != -1)
      insertNumberList(_largesList, oddOneOut);

  _list = _largesList;
}

bool PmergeMe::isSorted(std::vector<int> arr) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] > arr[i + 1])
            return (false);
    }
    return (true);
}

void PmergeMe::checkIfSorted(void) {
  if (isSorted(_arr))
            std::cout << GREEN "The array is sorted !" RESET << std::endl;
        else
            std::cout << RED "The array is not sorted !" RESET << std::endl;
}

void PmergeMe::printArray(const std::string str) {
  std::cout << str << ":\t";
  for (size_t i = 0; i < _arr.size(); ++i) {
    std::cout << _arr[i] << " ";
  }
  std::cout << std::endl;
}

bool PmergeMe::isSortedList(std::list<int> list) {
  std::list<int>::iterator it = list.begin();
  while (it != list.end()) {
    std::list<int>::iterator it2 = it;
    ++it2;
    if (it2 == list.end())
      break;
    if (*it > *it2)
      return (false);
    ++it;
    ++it;
  }
  return (true);
}

void PmergeMe::checkIfSortedList(void) {
  if (isSortedList(_list))
    std::cout << GREEN "The list is sorted !" RESET << std::endl;
  else
    std::cout << RED "The list is not sorted !" RESET << std::endl;
}

void PmergeMe::printList(void) {
  for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::fillList(char **av) {
  for (size_t i = 0; av[i]; ++i) {
    std::string arg(av[i]);
    _list.push_back(atoi(arg.c_str()));
  }
}

void PmergeMe::printThisList(std::string name, std::list<int> list) {
  std::cout << BRIGHT_YELLOW << name << "\t" << RESET << std::endl;
  for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << "\t ";
  }
  std::cout << std::endl;
}

void PmergeMe::printPairs(std::vector<std::pair<int, int> > pairs) {
  std::cout << BRIGHT_YELLOW << "PAIRS" << "\t" << RESET << std::endl;
  for (size_t i = 0; i < pairs.size(); ++i) {
    std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
  }
  std::cout << BRIGHT_YELLOW << "END OF PAIRS" << RESET << std::endl;
}

void PmergeMe::printPairsList(std::list<std::pair<int, int> > pairs) {
  std::cout << BRIGHT_YELLOW << "PAIRS" << "\t" << RESET << std::endl;
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << BRIGHT_YELLOW << "END OF PAIRS" << RESET << std::endl;
}
