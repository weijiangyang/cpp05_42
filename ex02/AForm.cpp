#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// 在 .cpp 中添加一个私有的辅助检查函数（或者直接在初始化列表里写逻辑）
AForm::AForm(const std::string &name, int grade_for_sign, int grade_for_execute) : _name(name),
																				   _is_signed(false),
																				   _grade_for_sign(grade_for_sign),
																				   _grade_for_execute(grade_for_execute)
{
	// 即使已经初始化了，也要在构造函数体里检查，确保对象创建合法
	if (grade_for_sign < 1 || grade_for_execute < 1)
		throw AForm::GradeTooHighException(); // 假设你定义了这个异常
	if (grade_for_sign > 150 || grade_for_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name),
								   _is_signed(other._is_signed),
								   _grade_for_sign(other._grade_for_sign),
								   _grade_for_execute(other._grade_for_execute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return (*this);
}

AForm::~AForm() {}

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

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form: " << f.getName()
	   << ", Sign Grade: " << f.getGradeForSign()
	   << ", Exec Grade: " << f.getGradeForExecute()
	   << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
	return os;
}