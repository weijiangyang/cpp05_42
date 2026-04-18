#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45),
																	  _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
																			 _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::cout << "Bzzzzzz... drilling noise...\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}