/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:02:43 by mbernard          #+#    #+#             */
/*   Updated: 2024/10/13 22:06:47 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
      std::cerr << RED "Error: wrong number of arguments" RESET << std::endl;
      std::cerr << "Usage : ./PMERGEME [filename]" << std::endl;
      return (1);
  }

  const std::string s1 = av[1];

  if (s1.empty()) {
      std::cerr << RED "Error: arg[1] is empty" RESET << std::endl;
      return (1);
  }

  PmergeMe rpn(s1);
  try {
    rpn.calculate();
  } catch (std::exception& e) {
    std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    return (1);
  }
  return (0);
}
