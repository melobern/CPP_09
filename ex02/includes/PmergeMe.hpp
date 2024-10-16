/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:02:43 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 21:40:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_PMERGEME_HPP_
#define EX02_INCLUDES_PMERGEME_HPP_
#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <string>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
 private:
  std::vector<int> _arr;
  std::vector<int> _smalls;
  std::vector<int> _larges;

  // std::list<int> _list;
  // std::list<int> _smallsList;
  // std::list<int> _largesList;

  char      **_av;

  PmergeMe(void);
  PmergeMe& operator=(const PmergeMe& src);
  PmergeMe(const PmergeMe& src);

  void insertLastNumbers(int oddOneOut);
  void buildPairs(std::vector<std::pair<int, int> >& pairs);
  void putInSmallAndLarge(std::vector<std::pair<int, int> > &pairs);
  void printPairs(std::vector<std::pair<int, int> > pairs);bool isSorted(std::vector<int> arr);
 public:
  explicit PmergeMe(char **av);
  ~PmergeMe(void);
  void fillArray(void);
  void fordJohnsonSortVector(void);
  void printArray(const std::string str);
  void checkIfSorted(void);
};

#endif  //  EX02_INCLUDES_PMERGEME_HPP_
