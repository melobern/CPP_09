/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calendar.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:07:06 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 21:55:32 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_CALENDAR_HPP_
#define EX00_INCLUDES_CALENDAR_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <map>
#include <climits>

class Calendar {
 private:
  static const int                       _daysInMonth[13];
  int                                    _currentYear;
  int                                    _minYear;

  Calendar &operator=(const Calendar &src);
  Calendar(const Calendar &src);

  bool        isLeap(const int year);
  int         initCurrentYear(void);

 public:
  Calendar(void);
  ~Calendar(void);

  int         dateToInt(const std::string date);
  std::string findClosestDate(const std::string date,
                              const std::map<std::string, float> map);
  bool        dateIsWrong(const int dd, const int mm, const int yy);
  void        assignMinYear(int year);
  int         getCurrentYear(void) const;
  int         getMinYear(void) const;
  class InvalidDate : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

#endif  // EX00_INCLUDES_CALENDAR_HPP_
