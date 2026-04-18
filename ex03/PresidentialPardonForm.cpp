#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 25, 5),
																			_target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
																					  _target(other._target)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm() {}
void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox\n";
}