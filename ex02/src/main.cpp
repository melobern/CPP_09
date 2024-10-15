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
// Il y a 5 étapes je vais essayer de t expliquer et de les illustrer avec un exemple :
// Tu as cette entrée : 33 2 15 8 99 4

//     -faire des paires avec le plus grand d un coté et le plus petit de l autre  : 33 2 15 8 99 4 = >  2 33 8 15 4 99
//     -trier les paires par leur plus grand nombre par récursion : 2 33 8 15 4 99 = > 8 15 2 33 4 99
//     -Mettre les plus petits dans un tableau et les plus grands dans un autre : 8 2 4 | 15 33 99
//     -Vu que les paires étaient triées le tableau des grands est trié, tu ajoutes le petit de la première paire 8 au premier index du tableau des grands : 2 4 | 8 15 33 99
//     Tu ajoutes les petits dans la tableau des grands avec un binary search (recherche dichotomique)
//     Pour optimiser la dernière étape tu utilises la suite de Jacobsthal (https://fr.wikipedia.org/wiki/Suite_de_Jacobsthal)

// 33 15 2 8 99 4
// 15 33 2 8 4 99
// 15 2 4 | 8 33 99
// 2 4 | 15 8 33 99

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
  if (ac < 2) {
      std::cerr << RED "Error: wrong number of arguments" RESET << std::endl;
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
        std::cout << "Before:\t";
        pm.printArray();
        pm.fordJohnsonSort();
        std::cout << "After:\t";
        pm.printArray();
        clock_t end = clock();
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC / 1000 * 1e6;
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << ac - 1 << " numbers: " << elapsed_time << " us" << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
