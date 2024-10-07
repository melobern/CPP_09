/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:19:44 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/01 09:56:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

Span::Span(void) : _size(0) {
    return;
}

Span::Span(const int n)
            : _size(n) {
    return;
}

Span::Span(const Span &src)
            : _size(src._size) {
    *this = src;
    return;
}

Span& Span::operator=(Span const &src) {
    if (this != &src) {
        this->_arr.assign(src._arr.begin(), src._arr.end());
    }
    return (*this);
}

Span::~Span() {
    return;
}

void              Span::addNumber(const int n) {
  if (this->_arr.size() == static_cast<unsigned int>(this->_size))
    throw spanFullException();
  this->_arr.push_back(n);
}

unsigned int      Span::shortestSpan(void) {
  if (this->_arr.size() == 0)
    throw noNumberException();
  if (this->_arr.size() == 1)
    throw oneNumberException();

  std::vector<int> copy = this->_arr;
  std::sort(copy.begin(), copy.end());
  unsigned int shortest = copy.at(1) - copy.at(0);

  for (size_t i = 0; i < copy.size() - 1; ++i) {
    unsigned int tmp = copy.at(i + 1) - copy.at(i);
    if (tmp < shortest)
      shortest = tmp;
    if (shortest == 0) {
      throw sameNumberException();
    }
  }
  return(shortest);
}

unsigned int Span::longestSpan(void) {
  if (this->_arr.size() == 0)
    throw noNumberException();
  if (this->_arr.size() == 1)
    throw oneNumberException();
  int min = *std::min_element(this->_arr.begin(), this->_arr.end());
  int max = *std::max_element(this->_arr.begin(), this->_arr.end());
  if (min == max)
    throw sameNumberException();
  return (max - min);
}

const char* Span::spanFullException::what() const throw() {
  return (RED "Error : span is full" RESET);
}

const char* Span::noNumberException::what() const throw() {
  return (RED "Error : span is empty" RESET);
}

const char* Span::oneNumberException::what() const throw() {
  return (RED "Error : only one number in the span" RESET);
}

const char* Span::sameNumberException::what() const throw() {
  return (RED "Error : numbers are equal in the span" RESET);
}

  void Span::printSpan(void) {
    for (size_t i = 0; i < this->_arr.size(); ++i) {
      std::cout << this->_arr.at(i) << "\t";
      if (i % 10 == 9 && i != this->_arr.size() - 1)
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }


