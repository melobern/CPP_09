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
#include <ctime>
#include <sys/time.h>

class PmergeMe {
 private:
  std::vector<int> _arr;
  std::vector<int> _sorted;

  char      **_av;

  PmergeMe(void);
  PmergeMe& operator=(const PmergeMe& src);
  PmergeMe(const PmergeMe& src);
  bool isValidNumber(const std::string token);

  class invalidValueException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 public:
  explicit PmergeMe(char **av);
  ~PmergeMe(void);
  void fillArray(void);
  void fordJohnsonSort(void);
  void printArray(void);
};

#endif  //  EX02_INCLUDES_PMERGEME_HPP_
