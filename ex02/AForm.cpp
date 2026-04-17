#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int grade_for_sign, int grade_for_execute) : _name(name),
																				   _is_signed(false),
																				   _grade_for_sign(grade_for_sign),
																				   _grade_for_execute(grade_for_execute)
{
}

AForm::~AForm() {}

const char *AForm::NotSignedException ::what() const throw()
{
	return "Form not signed";
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