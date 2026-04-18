#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("shrubbery Creation", 72, 45),
																	  _target(target)
{
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