#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_for_sign;
	const int _grade_for_execute;

public:
	// constructor / destructor
	AForm();
	AForm(const std::string &name, int grade_for_sign, int grade_for_execute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	// Exceptions
	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	// core functions
	virtual void execute(const Bureaucrat &bureaucrat) const = 0;
	void beSigned(const Bureaucrat &bureaucrat);
	void checkExecute(const Bureaucrat &bureaucrat) const;

	// getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeForSign() const;
	int getGradeForExecute() const;
};

#endif