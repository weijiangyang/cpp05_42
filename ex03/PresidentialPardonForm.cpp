#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("shrubbery Creation", 72, 45),
																			_target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm() {}
void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox\n";
}