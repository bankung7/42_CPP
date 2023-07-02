/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:13:35 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:13:37 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {

private:
    std::string fName;
    std::string lName;
    std::string nName;
    std::string pNumber;
    std::string dSecret;

public:
    Contact( void );
    ~Contact( void );
    void addContact( std::string fname, std::string lname, std::string nname, \
        std::string pnumber, std::string dsecret );
    void displayContact( void );
    std::string getFirstName( void );
    std::string getLastName( void );
    std::string getNickName( void );
    std::string getPhoneNumber( void );
    std::string getDarkestSecret( void );
};

#endif
