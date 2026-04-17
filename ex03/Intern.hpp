#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);			  // 补上拷贝构造
	Intern &operator=(const Intern &other); // 补上赋值运算符
	~Intern();
	AForm *makeForm(std::string name, std::string target);

private:
	typedef AForm *(Intern::*FormCreator)(const std::string &);

	AForm *createShrubbery(const std::string &target);
	AForm *createRobotomy(const std::string &target);
	AForm *createPresidential(const std::string &target);
};

#endif