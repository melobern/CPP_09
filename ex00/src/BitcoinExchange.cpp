/* Copyright 2024 <mbernard>************************************************  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:19:44 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 19:05:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "../includes/Colors.hpp"

BitcoinExchange::BitcoinExchange(void) {
    return;
}

BitcoinExchange::BitcoinExchange(const std::string inputFile)
            : _inputFile(inputFile) {
    return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
            : _inputFile(src._inputFile) {
    *this = src;
    return;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &src) {
    if (this != &src) {
        this->_inputFile = src._inputFile;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
    return;
}

const char* BitcoinExchange::cantOpenFileException::what() const throw() {
  return (RED "Error : the file can't be open." RESET);
}

