#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotoMyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Bureaucrat bob("Bob", 1);

    ShrubberyCreationForm s("home");
    RobotoMyRequestForm r("Bender");
    PresidentialPardonForm p("Alice");

    bob.signForm(s);
    bob.executeForm(s);

    bob.signForm(r);
    bob.executeForm(r);

    bob.signForm(p);
    bob.executeForm(p);

    return 0;
}