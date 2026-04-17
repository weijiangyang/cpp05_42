#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm(const std::string& target);
		virtual ~ShrubberyCreationForm();

		virtual void execute(const Bureaucrat &bureaucrat) const;
};

#endif 