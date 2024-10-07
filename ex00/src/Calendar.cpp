/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calendar.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:07:06 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 15:39:59 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Calendar.hpp"

// TO PUT IN THE CALENDAR.HPP STRUCT/CLASS
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static bool isLeap(const int year) {
//  if (year == 0)
//    throw NotExisingYearException();
  int abs_year = std::abs(year); 

  if (((abs_year % 4 == 0) && (abs_year % 100 != 0)) || (abs_year % 400 == 0)) {
    return (true);
  }
  return (false);
}

void add_days_to_date(int mm, int dd, int yy, int days_left_to_add) {
  int days_left_in_month = days_in_month[mm]-dd;
  if (days_left_to_add < days_left_in_month)
    dd += days_left_to_add;
  else {
    while (days_left_to_add > days_left_in_month) {
      if (mm == 12) {
        ++yy;
        mm = 0;
      }
      if (mm == 2 && isLeap(yy))
        ++days_left_in_month;
      ++mm;
      days_left_to_add -= days_left_in_month;
      days_left_in_month = days_in_month[mm];
    }
    dd = days_left_to_add;
  }
  std::cout << "The new date is " << dd << " " << mm << " " << yy;
}

bool dateIsWrong(const int dd, const int mm, const int yy) {
  if (yy == 0) {
    std::cerr << "Error: year 0 doesn't exist" << std::endl;
    return (true);
  }
  if (mm <= 0 || mm > 12) {
    std::cerr << "Error: month should be between 1 and 12" << std::endl;
    return (true);
  }
  if (dd <= 0 || dd > 31) {
    std::cerr << "Error: day should be between 1 and 31" << std::endl;
    return (true);
  }
  if (mm != 2 && mm > 0 && mm < 13 && dd > days_in_month[mm]) {
    std::cerr << "Error: the month " << mm << " has only " << days_in_month[mm];
    std::cerr << " days" << std::endl;
    return (true);
  }
  if (mm == 2 && dd > 28 && !isLeap(yy)) {
    std::cerr << "Error: the year "<< yy << " isn't leap : ";
    std::cerr << "february can't have more than 28 days" << std::endl;
    return (true);
  }
  if (mm == 2 && dd > 29) {
    std::cerr << "Error: february can't have more than 29 days" << std::endl;
    return (true);
  }
  return (false);
}

void printLeapYears(const int min, const int max) {
    int yearFounds = 0;

    for (int x = min; x < max; x++) {
      if (isLeap(x)) {
        yearFounds++;
        std::cout << x << "\t";
        if (yearFounds % 11 == 0)
          std::cout << std::endl;
        }
    }
}

