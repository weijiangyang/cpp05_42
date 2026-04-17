#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("charle", 150);
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}