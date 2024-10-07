/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calendar.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:07:06 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/07 15:42:28 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_CALENDAR_HPP_
#define EX00_INCLUDES_CALENDAR_HPP_

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <utility>
#include "../includes/Colors.hpp"

// TO PUT IN THE STRUCT/CLASS
// int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// bool isLeap(const int year);
void add_days_to_date(int mm, int dd, int yy, int days_left_to_add);
bool dateIsWrong(const int dd, const int mm, const int yy);
void printLeapYears(const int min, const int max);

#endif  // EX00_INCLUDES_CALENDAR_HPP_
