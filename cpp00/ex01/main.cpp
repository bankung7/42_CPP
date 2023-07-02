/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:13:45 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:47 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    // let build Phonebook
    PhoneBook pBook;
    std::cout << "Welcome to Phonebook" << std::endl;

    // loop for command
    std::string input;

    std::cout << "Command List : [ADD] [SEARCH] or [EXIT]" << std::endl;
    std::cout << "type your command : " << std::flush;

    while (std::getline(std::cin, input))
    {
        // check the input
        if (input.compare("ADD") == 0)
            pBook.addContact();
        else if (input.compare("SEARCH") == 0)
            pBook.searchContact();
        else if (input.compare("EXIT") == 0)
            break;
        else
            std::cout << "Invalid Command, try again" << std::endl;
            
        std::cout << "Command List : [ADD] [SEARCH] or [EXIT]" << std::endl;
        std::cout << "type your command : " << std::flush;
    }
    std::cout << "Bye from Phonebook" << std::endl;
    return (0);
}
