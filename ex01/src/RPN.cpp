/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:02:43 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 21:34:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(void) { return; }

RPN::RPN(const std::string inputMath) : _line(inputMath) { return; }

RPN::RPN(const RPN& src) : _line(src._line) {
  *this = src;
  return;
}

RPN& RPN::operator=(RPN const& src) {
  if (this != &src) {
    this->_line = src._line;
  }
  return (*this);
}

RPN::~RPN() { return; }

bool RPN::isOperator(const std::string token) {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string token) {
  size_t len = 0;
  size_t size = token.size();

  if (token[0] == '-')
    len++;
  while (len < size) {
    if (!isdigit(token[len]))
      return (false);
    len++;
  }
  if (!isdigit(token[len - 1]))
    return (false);

  long value = strtol(token.c_str(), NULL, 10);
  if (value > 9 || value < -9) {
    return (false);
  }
  return (true);
}

long RPN::applyOperator(const std::string& op, long a, long b) {
  switch (op[0]) {
    case '+':
      return (a + b);
    case '-':
      return (a - b);
    case '*':
      return (a * b);
    case '/':
      if (b == 0) {
        throw DivisionByZeroException();
      }
      return (a / b);
    default:
      throw invalidValueException();
  }
}

void RPN::calculate(void) {
  std::string token;
  std::istringstream iss(_line);

  while (iss >> token) {
    if (isOperator(token)) {
      if (_datas.size() < 2) {
        throw TooFewOperandsException();
      }
      long a = _datas.top();
      _datas.pop();
      long b = _datas.top();
      _datas.pop();
      long result = applyOperator(token, b, a);
      _datas.push(result);
    } else if (isValidNumber(token)) {
      _datas.push(strtol(token.c_str(), NULL, 10));
    } else {
      throw invalidValueException();
    }
  }
  if (_datas.size() != 1) {
    throw TooManyOperandsException();
  }
  std::cout << _datas.top() << std::endl;
}

const char* RPN::invalidValueException::what() const throw() {
  return ("Invalid value.");
}

const char* RPN::TooManyOperandsException::what() const throw() {
  return ("Too many operands.");
}

const char* RPN::TooFewOperandsException::what() const throw() {
  return ("Too few operands.");
}

const char* RPN::DivisionByZeroException::what() const throw() {
  return ("Division by zero.");
}
