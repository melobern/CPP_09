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

bool PmergeMe::isValidNumber(const std::string arg) {
  size_t size = arg.size();

  if (arg.empty() || arg[0] == '-')
    return (false);
  for (size_t len = 0; len < size; len++) {
    if (!isdigit(arg[len]))
      return (false);
  }
  if (std::atoll(arg.c_str()) > INT_MAX) {
    return (false);
  }
  return (true);
}

void PmergeMe::fillArray(void) {
  for (size_t i = 0; _av[i]; ++i) {
    std::string arg(_av[i]);
    _arr.push_back(atoi(arg.c_str()));
  }
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void PmergeMe::fordJohnsonSort(void) {
  // Étape 1 : Faire des paires
  std::vector<std::pair<int, int> > pairs;

  for (size_t i = 0; i + 1 < _arr.size(); i += 2) {
    if (_arr[i] < _arr[i + 1]) {
      pairs.push_back(std::make_pair(_arr[i], _arr[i + 1]));
    } else {
      pairs.push_back(std::make_pair(_arr[i + 1], _arr[i]));
    }
  }

  if (_arr.size() % 2 != 0) {
    pairs.push_back(std::make_pair(_arr.back(), _arr.back()));
  }

  // Étape 2 : Trier les paires par leur plus grand nombre
  std::sort(pairs.begin(), pairs.end(), comparePairs);

  // Étape 3 : Séparer les petits et les grands éléments
  std::vector<int> smalls, larges;
  for (size_t i = 0; i < pairs.size(); ++i) {
    smalls.push_back(pairs[i].first);
    larges.push_back(pairs[i].second);
  }

  // Étape 4 : Insérer le plus petit élément dans le tableau des grands

  _sorted.push_back(larges[0]);

  for (size_t i = 1; i < larges.size(); ++i) {
    _sorted.insert(std::upper_bound(_sorted.begin(), _sorted.end(), larges[i]),
                  larges[i]);
  }
  printArray();
// Étape 5 : Insérer les autres petits éléments avec une recherche dichotomique
for (size_t i = 0; i < smalls.size(); ++i) {
    // Trouver la position d'insertion
    std::vector<int>::iterator it = std::upper_bound(_sorted.begin(), _sorted.end(), smalls[i]);
    
    // Insérer l'élément seulement s'il n'est pas déjà présent
    if (it == _sorted.end() || *it != smalls[i]) {
        _sorted.insert(it, smalls[i]);
    }
}
  // Étape 5 : Insérer les autres petits éléments avec une recherche
  // dichotomique
  // for (size_t i = 0; i < smalls.size(); ++i) {
  //   _sorted.insert(std::upper_bound(_sorted.begin(), _sorted.end(), smalls[i]),
  //                 smalls[i]);
  // }
  printArray();

  // Copier le résultat trié dans le tableau original
  _arr = _sorted;
}

const char* PmergeMe::invalidValueException::what() const throw() {
  return ("Invalid value.");
}

void PmergeMe::printArray(void) {
  std::cout << std::endl << RED << "_arr " << RESET << " : " << std::endl;
  for (size_t i = 0; i < _arr.size(); ++i) {
    std::cout << _arr[i] << " ";
  }
  std::cout << std::endl << RED << "_sorted " << RESET << " : " << std::endl;
for (size_t i = 0; i < _sorted.size(); ++i) {
    std::cout << _sorted[i] << " ";
  }
  std::cout << std::endl << std::endl;
}
