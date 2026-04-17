#include "AForm.hpp"
#include "Bureaucrat.hpp"

// 1. Default Constructor (规范要求)
AForm::AForm() : _name("default"), _is_signed(false), _grade_for_sign(150), _grade_for_execute(150)
{
}

// 2. 有参构造函数
AForm::AForm(const std::string &name, int grade_for_sign, int grade_for_execute) : 
    _name(name),
    _is_signed(false),
    _grade_for_sign(grade_for_sign),
    _grade_for_execute(grade_for_execute)
{
    if (grade_for_sign < 1 || grade_for_execute < 1)
		throw GradeTooHighException();
	if (grade_for_sign > 150 || grade_for_execute > 150)
		throw GradeTooLowException();
}

// 3. Copy Constructor
AForm::AForm(const AForm &other) : 
    _name(other._name),
    _is_signed(other._is_signed),
    _grade_for_sign(other._grade_for_sign),
    _grade_for_execute(other._grade_for_execute)
{
    // 拷贝构造是通过初始化列表完成的，这里不需要额外操作
}

// 4. Copy Assignment Operator
AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        // 关键：const 成员无法被重新赋值，所以这里只拷贝布尔值
        this->_is_signed = other._is_signed;
    }
    return (*this);
}

// 5. Destructor
AForm::~AForm()
{
}

const char *AForm::NotSignedException ::what() const throw()
{
	return "Form not signed";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
		return;

	if (bureaucrat.getGrade() > _grade_for_sign)
		throw GradeTooLowException();

	_is_signed = true;
}

void AForm::checkExecute(const Bureaucrat &bureaucrat) const
{
	if (!_is_signed)
		throw NotSignedException();

	if (bureaucrat.getGrade() > _grade_for_execute)
		throw GradeTooLowException();
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_is_signed);
}

int AForm::getGradeForSign() const
{
	return (_grade_for_sign);
}

int AForm::getGradeForExecute() const
{
	return (_grade_for_execute);
}