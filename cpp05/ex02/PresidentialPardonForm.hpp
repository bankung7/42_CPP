#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{

private:
    std::string _target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& c);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& c);
    ~PresidentialPardonForm(void);

    void execute(Bureaucrat const & executor) const;

};

#endif

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox