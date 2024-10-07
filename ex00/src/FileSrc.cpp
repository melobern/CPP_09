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

FileSrc::FileSrc(std::string filename) {
    this->filename = filename;
    this->file_replace = filename + ".replace";
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

bool FileSrc::open_out(const std::string name) {
        this->file_dest.open(name.c_str(), std::ios::out);
        if (!this->file_dest.is_open()) {
            std::cout << "Error: "<< std::endl;
            std::perror(name.c_str());
            return (0);
        }
        return (1);
}

void FileSrc::create_new_file(const std::string s1, const std::string s2) {
    Replacer replacer(s1, s2);
    std::stringstream content;

    if (!this->open_in(this->filename))
        return;
    content << this->file_src.rdbuf();
    this->file_src.close();
    if (!this->open_out(this->file_replace))
        return;
    if (!content.str().empty())
        replacer.replace(content.str(), this->file_dest);
    else
        std::cout << "This file is empty" << std::endl;
    this->file_dest.close();
}
