/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:13:21 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:22 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Phonebook is constructed" << std::endl;
    this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "Phonebook is destroyed" << std::endl;
}

std::string PhoneBook::getInput( std::string input )
{
    std::string output;

    while (true)
    {
        std::cout << input << " : ";
        if (!std::getline (std::cin, output))
            exit(0);
        if (!output.empty())
            return (output);
    }
    return (0);
}

void PhoneBook::rearrange( void )
{
    if (this->index < 8)
        return ;
    for (int i = 0; i < 7; i++)
        contact[i] = contact[i + 1];
    this->index--;
}

void PhoneBook::addContact( void )
{
    std::cout << "Please type your detail as following : " << std::endl;
    std::string fname = this->getInput("First Name");
    std::string lname = this->getInput("Last Name");
    std::string nname = this->getInput("Nick Name");
    std::string pnumber = this->getInput("Phone Number");
    std::string dsecret = this->getInput("Darkest Secret");
    this->rearrange();
    contact[this->index].addContact(fname, lname, nname, pnumber, dsecret);
    this->index++;
}

void PhoneBook::pCell( std::string input )
{
    if (input.length() > 10)
    {
        for (int i = 0; i < 9; i++)
            std::cout << input[i];
        std::cout << ".";
    }
    else
        std::cout << std::setw(10) << input;
    std::cout << "|";
}

bool PhoneBook::isNumber( std::string input )
{
    for (int i = 0; i < (int) input.length(); i++)
    {
        if (isdigit(input[i]) == 0)
            return (false);
    }
    return (true);
}

void PhoneBook::searchContact ( void )
{
    // if no contact
    if (this->index == 0)
    {
        std::cout << "There is no contact" << std::endl;
        return ;
    }

    std::cout << "|==========|==========|==========|==========|" << std::endl;
    std::cout << "|";
    pCell("index");
    pCell("First Name");
    pCell("Last Name");
    pCell("Nick Name");
    std::cout << "\n";
    std::cout << "|==========|==========|==========|==========|" << std::endl;

    // loop each contacth to show
    for (int i = 0; i < this->index; i++)
    {
        std::cout << "|";
        pCell(std::to_string(i + 1));
        pCell(contact[i].getFirstName());
        pCell(contact[i].getLastName());
        pCell(contact[i].getNickName());
        std::cout << "\n";
    }
    std::cout << "|==========|==========|==========|==========|" << std::endl;

    // select the index for more detail
    std::string input;

    std::cout << "type the index for more detail : " << std::flush;
    if (!std::getline (std::cin, input))
        exit(0);
    if (input.empty() || !this->isNumber(input) || std::stoi(input) <= 0 || std::stoi(input) > index)
        std::cout << "Invalid number" << std::endl;
    else
        contact[std::stoi(input) - 1].displayContact();
}
