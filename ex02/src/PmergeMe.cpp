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

PmergeMe::PmergeMe(char **av) : _av(av) { return; }

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

void PmergeMe::insertLastNumbers(int oddOneOut) {
  std::vector<int>::iterator it = std::upper_bound(_larges.begin(), _larges.end(), oddOneOut);
  if (it == _larges.end() || *it != oddOneOut) {
      _larges.insert(it, oddOneOut);
  }
}

void insertNumber(std::vector<int>& array, int number) {
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

bool PmergeMe::isSorted(std::vector<int> arr) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] > arr[i + 1])
            return (false);
    }
    return (true);
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

void PmergeMe::printArray(const std::string str) {
  std::cout << str << ":\t";
  for (size_t i = 0; i < _arr.size(); ++i) {
    std::cout << _arr[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::fillArray(void) {
  for (size_t i = 0; _av[i]; ++i) {
    std::string arg(_av[i]);
    _arr.push_back(atoi(arg.c_str()));
  }
}

void PmergeMe::printPairs(std::vector<std::pair<int, int> > pairs) {
  std::cout << BRIGHT_YELLOW << "PAIRS" << "\t" << RESET << std::endl;
  for (size_t i = 0; i < pairs.size(); ++i) {
    std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
  }
  std::cout << BRIGHT_YELLOW << "END OF PAIRS" << RESET << std::endl;
}

void PmergeMe::checkIfSorted(void) {
  if (isSorted(_arr))
            std::cout << GREEN "The array is sorted !" RESET << std::endl;
        else
            std::cout << RED "The array is not sorted !" RESET << std::endl;
}