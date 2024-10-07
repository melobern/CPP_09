/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 21:22:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "../includes/Colors.hpp"
#include "../includes/Calendar.hpp"
#include "../includes/BitcoinExchange.hpp"

static void calendarTests(int ac, char **av) {
  Calendar calendar;

  if (ac == 3) {
    int minYY = std::atoi(av[1]);
    int maxYY = std::atoi(av[2]);
    if (minYY > maxYY)
      std::swap(maxYY, minYY);
    calendar.printLeapYears(minYY, maxYY);
    return ;
  }

  if (ac == 5) {
    int day = std::atoi(av[1]);
    int month = std::atoi(av[2]);
    int year = std::atoi(av[3]);
    int add = std::atoi(av[4]);
    if (calendar.dateIsWrong(day, month, year))
      return;
    calendar.add_days_to_date(month, day, year, add);
  }
}

int main(int ac, char **av) {
  calendarTests(ac, av);

  if (ac != 2) {
      std::cerr << RED "Error: wrong number of arguments" RESET << std::endl;
      std::cerr << "Usage : ./btc [filename]" << std::endl;
      return (1);
  }

  const std::string s1 = av[1];

  if (s1.empty()) {
      std::cerr << RED "Error: s1 or s2 is empty" RESET << std::endl;
      return (1);
  }
  BitcoinExchange file(s1);
  return (0);
}

