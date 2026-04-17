#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		// Exceptions
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		//Constructor & assignment operator
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		//getter
		const std::string& getName() const;
		int getGrade() const;

		//Member functions
		void incrementGrade();
		void decrementGrade();

		//sign form
		void signForm(Form& form);
};
//overload <<
std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);

#endif