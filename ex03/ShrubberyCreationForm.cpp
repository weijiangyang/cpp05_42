#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	AForm("shrubbery Creation", 145, 137),
	_target(target)
	{
	}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::ofstream file((_target + "_shrubbery").c_str());
	
	file << "   ^   \n";
    file << "  ^^^  \n";
    file << " ^^^^^ \n";
    file << "   |   \n";

    file.close();
}