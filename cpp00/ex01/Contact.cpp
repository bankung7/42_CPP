/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:12:59 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:03 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {

}

Contact::~Contact( void ) {

}

void Contact::addContact( std::string fname, std::string lname, std::string nname, \
    std::string pnumber, std::string dsecret )
{
    this->fName = fname;
    this->lName = lname;
    this->nName = nname;
    this->pNumber = pnumber;
    this->dSecret = dsecret;
}

void Contact::displayContact( void )
{
    std::cout << "First Name : " << this->fName << std::endl;
    std::cout << "Last Name : " << this->lName << std::endl;
    std::cout << "Nick Name : " << this->nName << std::endl;
    std::cout << "Phone Number : " << this->pNumber << std::endl;
    std::cout << "Darkest Secret : " << this->dSecret << std::endl;
}

std::string Contact::getFirstName( void )
{
    return (this->fName);
}

std::string Contact::getLastName( void )
{
    return (this->lName);
}

std::string Contact::getNickName( void )
{
    return (this->nName);
}
std::string Contact::getPhoneNumber( void )
{
    return (this->pNumber);
}
std::string Contact::getDarkestSecret( void )
{
    return (this->dSecret);
}
