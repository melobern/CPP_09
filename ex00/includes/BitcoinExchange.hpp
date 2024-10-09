/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:25:30 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 19:10:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_BITCOINEXCHANGE_HPP_
#define EX01_INCLUDES_BITCOINEXCHANGE_HPP_
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstring>
# include <string>
# include <map>
# include <exception>
# include "Calendar.hpp"

class BitcoinExchange {
 private:
   std::map<std::string, float> _datas;
   static const std::string     _dataFile;
   std::string                  _inputFile;
   Calendar                     _calendar;

   BitcoinExchange(void);
   BitcoinExchange &operator=(const BitcoinExchange &src);
   BitcoinExchange(const BitcoinExchange &src);
   void fillMap(std::stringstream *dataFile);
   void dataLineValidation(const std::string &line, char sep);
   void printBitcoinValue(std::string line, std::map<std::string, float> map);
   class InvalidDataLine : public std::exception {
    public:
     virtual const char *what() const throw();
   };
   class InvalidDate : public std::exception {
    public:
     virtual const char *what() const throw();
   };
   class notAPositiveNumber : public std::exception {
    public:
     virtual const char *what() const throw();
   };
    class numberHigherThan1000 : public std::exception {
      public:
      virtual const char *what() const throw();
    };

 public:
   BitcoinExchange(const std::string inputFile);
   ~BitcoinExchange(void);
   void searchBitcoinValue(void);

};

#endif  //  EX01_INCLUDES_BITCOINEXCHANGE_HPP_
