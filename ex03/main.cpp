#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	Intern someRandomIntern;

	AForm *form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		delete form;
	}

	form = someRandomIntern.makeForm("unknown form", "test");
	if (form)
		delete form;

	return 0;
}
