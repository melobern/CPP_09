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
Il y a 5 étapes je vais essayer de t expliquer et de les illustrer avec un exemple :
Tu as cette entrée : 33 2 15 8 99 4

    -faire des paires avec le plus grand d un coté et le plus petit de l autre  : 33 2 15 8 99 4 = >  2 33 8 15 4 99
    -trier les paires par leur plus grand nombre par récursion : 2 33 8 15 4 99 = > 8 15 2 33 4 99
    -Mettre les plus petits dans un tableau et les plus grands dans un autre : 8 2 4 | 15 33 99
    -Vu que les paires étaient triées le tableau des grands est trié, tu ajoutes le petit de la première paire 8 au premier index du tableau des grands : 2 4 | 8 15 33 99
    Tu ajoutes les petits dans la tableau des grands avec un binary search (recherche dichotomique)
    Pour optimiser la dernière étape tu utilises la suite de Jacobsthal (https://fr.wikipedia.org/wiki/Suite_de_Jacobsthal)

33 15 2 8 99 4
15 33 2 8 4 99
15 2 4 | 8 33 99
2 4 | 15 8 33 99

int main(int ac, char **av) {
  if (ac < 2) {
      std::cerr << RED "Error: wrong number of arguments" RESET << std::endl;
      std::cerr << "Usage : ./PmergeMe [Num] [Num]..." << std::endl;
      return (1);
  }


  return (0);
}
