/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/09 22:06:47 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Calendar.hpp"
#include "../includes/BitcoinExchange.hpp"


int main(int ac, char **av) {
  if (ac != 2) {
      std::cerr << RED "Error: wrong number of arguments" RESET << std::endl;
      std::cerr << "Usage : ./btc [filename]" << std::endl;
      return (1);
  }

  const std::string s1 = av[1];

  if (s1.empty()) {
      std::cerr << RED "Error: s1 is empty" RESET << std::endl;
      return (1);
  }
  BitcoinExchange file(s1);
  file.searchBitcoinValue();

  return (0);
}
