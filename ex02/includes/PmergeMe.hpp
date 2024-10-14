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
#include <sstream>
#include <exception>
#include <string>
#include <cstdlib>

class PmergeMe {
 private:
  std::stack<long> _datas;
  std::string      _line;

  PmergeMe(void);
  PmergeMe& operator=(const PmergeMe& src);
  PmergeMe(const PmergeMe& src);
  bool isOperator(const std::string token);
  bool isValidNumber(const std::string token);
  long applyOperator(const std::string& op, long a, long b);

  class invalidValueException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class TooManyOperandsException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class TooFewOperandsException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class DivisionByZeroException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 public:
  explicit PmergeMe(const std::string inputMath);
  ~PmergeMe(void);
  void calculate(void);
};

#endif  //  EX02_INCLUDES_PMERGEME_HPP_
