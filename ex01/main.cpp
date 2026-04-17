
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{

    try
    {
        std::cout << "===== Create Bureaucrats =====" << std::endl;
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        Bureaucrat tom("Tom", 150);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << tom << std::endl;

        std::cout << "\n===== Create Forms =====" << std::endl;
        Form formA("FormA", 100, 50);
        Form formB("FormB", 1, 1);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n===== Test Signing =====" << std::endl;

        // ❌ Bob grade 50, formA requires 100 → should succeed
        bob.signForm(formA);
        std::cout << formA << std::endl;

        // ❌ Tom grade 150, cannot sign formA
        tom.signForm(formA);

        // ✅ Alice can sign everything
        alice.signForm(formB);
        std::cout << formB << std::endl;

        std::cout << "\n===== Test Direct beSigned =====" << std::endl;

        Form formC("FormC", 75, 50);

        formC.beSigned(bob);   // OK
        std::cout << formC << std::endl;

        formC.beSigned(tom);   // should fail (exception)

    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test Grade Exceptions =====" << std::endl;

    try
    {
        Bureaucrat bad("BadGuy", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad2("BadGuy2", 200);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Test Increment/Decrement =====" << std::endl;

    try
    {
        Bureaucrat test("Test", 2);
        std::cout << test << std::endl;

        test.incrementGrade();
        std::cout << test << std::endl;

        test.incrementGrade(); // should throw
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}



