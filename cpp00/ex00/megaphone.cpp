/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:12:43 by vnilprap          #+#    #+#             */
/*   Updated: 2023/02/15 21:12:45 by vnilprap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        std::string input;
        for (int i = 1; i < argc; i++)
        {
            input = argv[i];
            for (int j = 0; j < (int)input.length(); j++)
                std::cout << (char) std::toupper(input[j]);
        }
    }
    std::cout << std::endl;
    return (0);
}
