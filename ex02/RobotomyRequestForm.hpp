#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

	virtual void execute(const Bureaucrat &bureaucrat) const;
};

#endif