/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:02:43 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 21:40:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_RPN_HPP_
#define EX01_INCLUDES_RPN_HPP_
#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <string>
#include <cstdlib>

class RPN {
 private:
  std::stack<long> _datas;
  std::string      _line;

  RPN(void);
  RPN& operator=(const RPN& src);
  RPN(const RPN& src);
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
  explicit RPN(const std::string inputMath);
  ~RPN(void);
  void calculate(void);
};

#endif  //  EX01_INCLUDES_RPN_HPP_
