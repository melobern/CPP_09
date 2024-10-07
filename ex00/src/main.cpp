/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 15:38:45 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "../includes/Colors.hpp"
#include "../includes/Calendar.hpp"

static void calendarTests(int ac, char **av) {
  if (ac == 3) {
    int minYY = std::atoi(av[1]);
    int maxYY = std::atoi(av[2]);
    if (minYY > maxYY)
      std::swap(maxYY, minYY);
    printLeapYears(minYY, maxYY);
    return ;
  }

  if (ac == 5) {
    int day = std::atoi(av[1]);
    int month = std::atoi(av[2]);
    int year = std::atoi(av[3]);
    int add = std::atoi(av[4]);
    if (dateIsWrong(day, month, year))
      return;
    add_days_to_date(month, day, year, add);
  }
}

int main(int ac, char **av) {
  calendarTests(ac, av);
  return (0);
}
