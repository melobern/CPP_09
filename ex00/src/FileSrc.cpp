/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSrc.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:15:50 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/13 09:10:09 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileSrc.hpp"
#include "../includes/BitcoinExchange.hpp"


FileSrc::FileSrc(std::string filename) {
    this->_filename = filename;
    return;
}

FileSrc::~FileSrc() {
    return;
}

bool FileSrc::open_in(const std::string name) {
        this->file_src.open(name.c_str(), std::ios::in);
        if (!this->file_src.is_open()) {
            std::cout << "Error: "<< std::endl;
            std::perror(name.c_str());
            return (0);
        }
        return (1);
}

void FileSrc::convertFileToStream(const std::string s1, const std::string s2) {
    std::stringstream datafile;
    std::stringstream filename;
    BitcoinExchange   btc;

    if (!this->open_in(this->_datafile))
        throw std::runtime_error("Error: file not found");
    datafile << this->file_src.rdbuf();
    this->file_src.close();
    if (content.str().empty())
      throw std::runtime_error("File is empty");
    else
        std::cerr << RED "This file is empty" RESET << std::endl;
}
