/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calendar.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:07:06 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 20:53:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Calendar.hpp"

const int Calendar::_daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31};

Calendar::Calendar(void) {
    return;
}

Calendar::Calendar(const Calendar &src) {
    *this = src;
    return;
}

Calendar& Calendar::operator=(Calendar const &src) {
    static_cast<void>(src);
    return (*this);
}

Calendar::~Calendar() {
    return;
}

bool Calendar::isLeap(const int year) {
  if (year == 0 || year < -44)
    return (false);

  int abs_year = std::abs(year);

  if (abs_year % 4 == 0) {
    if (year < 1582 || abs_year % 100 != 0 || abs_year % 400 == 0)
      return (true);
  }

  return (false);
}

int        Calendar::getCurrentYear(void) {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    return currentYear;
}

int         Calendar::dateToInt(const std::string date) {
  char dash;
  std::istringstream iss(date);
  int year, month, day;
  int result;
  int currentYear = getCurrentYear();

  iss >> year >> dash >> month >> dash >> day;
  if (year * 10000 <  year)
     year = currentYear + 1;
  result = (year * 10000) + (month * 100) + day;
  return (result);
}

std::string Calendar::findClosestDate(const std::string date,
                                      const std::map<std::string, float> map) {
  std::string closestDate;
  int closestDateDiff = INT_MAX;
  int dateToInt = this->dateToInt(date);
  int dateDiff;

  for (std::map<std::string, float>::const_iterator it = map.begin();
       it != map.end(); ++it) {
    dateDiff = dateToInt - this->dateToInt(it->first);
    if (dateDiff < closestDateDiff && dateDiff > 0) {
      closestDateDiff = dateDiff;
      closestDate = it->first;
    }
    if (dateDiff < 0)
        break;
  }
  return (closestDate);
}

bool Calendar::dateIsWrong(const int dd, const int mm, const int yy) {
  if (yy == 0 || mm <= 0 || mm > 12 || dd <= 0 || dd > 31)
    return (true);
  if (mm != 2 && mm > 0 && mm < 13 && dd > this->_daysInMonth[mm])
    return (true);
  if (mm == 2 && dd > 28 && !isLeap(yy))
    return (true);
  if (mm == 2 && dd > 29)
    return (true);
  return (false);
}

