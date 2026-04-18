#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137),
																		  _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
																				   _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	checkExecute(bureaucrat);
	std::ofstream file((_target + "_shrubbery").c_str());
	// 💡 增加一个健壮性检查
	if (!file.is_open())
	{
		// 如果文件打不开，可以打印错误或抛出异常
		std::cerr << "Error: Could not open file for writing: " << _target << "_shrubbery" << std::endl;
		return;
	}
	file << "   ^   \n";
	file << "  ^^^  \n";
	file << " ^^^^^ \n";
	file << "   |   \n";
	file.close();
}