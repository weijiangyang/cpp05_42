#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotoMyRequestForm : public AForm
{
	private:
		std::string _target;
	
	public:
		RobotoMyRequestForm(const std::string& target);
		virtual ~RobotoMyRequestForm();

		virtual void execute(const Bureaucrat &bureaucrat) const;
};

#endif 