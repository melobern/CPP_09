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
#include "../includes/Colors.hpp"

RPN::RPN(void) {
  return;
}

RPN::RPN(const std::string inputMath) : _inputMath(inputMath) {
  return;
}

RPN::RPN(const RPN& src) : _inputMath(src._inputMath) {
  *this = src;
  return;
}

RPN& RPN::operator=(RPN const& src) {
  if (this != &src) {
    this->_inputMath = src._inputMath;
  }
  return (*this);
}

RPN::~RPN() {
  return;
}

static bool containsLetters(std::string line) {
  unsigned int i = 0;

  while (line[i] != '\0') {
    if (std::isalpha(line[i])) {
      return (true);
    }
    ++i;
  }
  return (false);
}

void RPN::fillStack(std::stringstream* dataFile) {
  std::string line;

  while (std::getline(*dataFile, line)) {
    std::istringstream iss(line);
    std::string date;
    float value;
    if (line.empty() || line == "\n" || containsLetters(line))
      continue;
    std::getline(iss, date, ',');
    iss >> value;
    _datas[date] = value;
  }
}

void RPN::verifyToken(const std::string line) {
    std::string token;
    std::istringstream iss(line);

    while (iss >> token) {
        if (isOperator(token)) {
          try {

          } catch (const std::exception& e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            return;
          }
        } else if isValidNumber(token) {
            _datas.push(strtol(token.c_str())); // why ???
        } else {
          throw invalidValueException();
        }
    }
}

void RPN::calculate(void) {}

const char* RPN::invalidValueException::what() const throw() {
  return ("Invalid value.");
}

const char* RPN::EmptyInputException::what() const throw() {
  return ("Empty input.");
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
