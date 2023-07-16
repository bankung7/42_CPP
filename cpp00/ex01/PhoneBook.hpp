/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:13:27 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:29 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {

private:
    int index;
    Contact contact[8];
    std::string getInput( std::string input );
    void pCell( std::string input );
    void rearrange( void );
    bool isNumber( std::string input );

public:
    PhoneBook( void );
    ~PhoneBook( void );
    void addContact( void );
    void searchContact( void );
};

#endif
