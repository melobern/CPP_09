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

static bool isValidNumber(const std::string arg) {
  size_t size = arg.size();

  if (arg.empty() || arg[0] == '-') {
    std::cerr << RED "Error: invalid argument :" << std::endl;
    if (arg.empty())
      std::cerr << "Empty string !" RESET << std::endl;
    else
      std::cerr << arg << " is not a positive int number !" RESET << std::endl;
    return (false);
  }
  for (size_t len = 0; len < size; len++) {
    if (!isdigit(arg[len])) {
      std::cerr << RED "Error: invalid argument :" << std::endl;
      std::cerr << arg << " is not composed of digits only !";
      std::cerr << RESET << std::endl;
      return (false);
    }
  }
  if (std::atoll(arg.c_str()) > INT_MAX) {
    std::cerr << RED "Error: invalid argument :" << std::endl;
    std::cerr << arg << " is bigger than INT_MAX !" RESET << std::endl;
    std::cerr << "Reminder : INT_MAX == " << INT_MAX << std::endl;
    return (false);
  }
  return (true);
}

static bool checkArgs(int ac, char **av) {
  if (ac < 3) {
      std::cerr << RED << "Error: wrong number of arguments : ";
      std::cerr << "you must give, at least, two arguments.";
      std::cerr << RESET << std::endl;
      std::cerr << "Usage : ./PmergeMe < int numbers >..." << std::endl;
      return (false);
  }
  for (int i = 1; i < ac; i++) {
    if (!isValidNumber(av[i]))
      return (false);
  }
  return (true);
}

int main(int ac, char **av) {
    if (!checkArgs(ac, av))
      return (1);

    PmergeMe pm(av + 1);
    try {
        clock_t start = clock();
        pm.fillArray();
        pm.fordJohnsonSortVector();
        clock_t end = clock();

        pm.printArray("After");
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC / 1000 * 1e6;
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << ac - 1 << " numbers: " << elapsed_time << " us" << std::endl;

        start = clock();
        pm.fillList(av + 1);
        pm.fordJohnsonSortList();
        end = clock();

        elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC / 1000 * 1e6;
        std::cout << "Time to process a range of " << ac - 1 << " numbers: " << elapsed_time << " us" << std::endl;
        // CHECK IF SORTED : COMMENTED FOR THE SUBJECT
        // pm.checkIfSorted();
        // pm.checkIfSortedList();
    } catch (std::exception& e) {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
