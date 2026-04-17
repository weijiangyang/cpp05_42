#include "RobotoMyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotoMyRequestForm::RobotoMyRequestForm(const std::string &target) : AForm("shrubbery Creation", 72, 45),
																	  _target(target)
{
}
RobotoMyRequestForm::~RobotoMyRequestForm() {}
void RobotoMyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::cout << "Bzzzzzz... drilling noise...\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}