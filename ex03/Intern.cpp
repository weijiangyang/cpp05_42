#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotoMyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other)
{
	*this = other;
}
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern() {}
AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotoMyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

/**
 * Intern 类核心函数：根据字符串名创建对应的表单
 * @param name   表单的名字（如 "robotomy request"）
 * @param target 表单的目标（如 "Bender"）
 * @return AForm* 指向新创建表单的指针，若未找到则返回 NULL
 */
AForm* Intern::makeForm(std::string name, std::string target)
{
    // 1. 定义已知表单的名字数组，用于匹配
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // 2. 使用之前 typedef 定义的函数指针类型，创建一个函数查找表（Jump Table）
    // 这里的函数地址必须加 &，且必须是 Intern 类的成员函数
    FormCreator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    // 3. 遍历数组进行匹配
    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            // 4. 关键点：使用 (this->*指针)(参数) 的语法来调用成员函数
            // 这里的 creators[i] 存储的是具体创建函数的地址
            return (this->*creators[i])(target);
        }
    }

    // 5. 如果循环结束仍未匹配，打印错误信息并按照 42 惯例返回 NULL
    std::cout << "Error: Form \"" << name << "\" not found" << std::endl;
    return (NULL);
}