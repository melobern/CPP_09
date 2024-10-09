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
#include "../includes/FileSrc.hpp"
#include "../includes/Colors.hpp"

const std::string BitcoinExchange::_dataFile = "data.csv";
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


void BitcoinExchange::searchBitcoinValue(void) {
    FileSrc file;
    std::stringstream *dataFile = NULL;
    std::stringstream *inFile = NULL;
    
    try {
        inFile = file.convertFileToStream(this->_inputFile);
        dataFile = file.convertFileToStream(this->_dataFile);
    } catch (std::exception &e) {
        if (inFile != NULL)
            delete inFile;
        std::cerr << RED "Error: " RESET << e.what() << std::endl;
        return;
    }
    std::cout << inFile->str() << std::endl;
    std::cout << dataFile->str() << std::endl;
    delete dataFile;
    delete inFile;

    // std::ifstream file;
    // std::string line;
    // std::string date_file;
    // std::string value;
    // std::string date_value;
    // std::string value_value;
    // std::string::size_type pos;

    // file.open(this->_inputFile);
    // if (!file.is_open()) {
    //     std::cerr << RED "Error: " RESET << "Can't open file" << std::endl;
    //     return;
    // }
    // while (std::getline(file, line)) {
    //     pos = line.find(" ");
    //     date_file = line.substr(0, pos);
    //     if (date_file == date) {
    //         value = line.substr(pos + 1);
    //         pos = value.find(" ");
    //         date_value = value.substr(0, pos);
    //         value_value = value.substr(pos + 1);
    //         std::cout << "Date: " << date_value << " Value: " << value_value << std::endl;
    //         return;
    //     }
    // }
    // std::cerr << RED "Error: " RESET << "Date not found" << std::endl;
    return;
}
