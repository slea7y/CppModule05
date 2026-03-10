#include <exception>
#include <iostream>
// #include "AForm.hpp"
#include "Bureacrat.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	Bureaucrat b("Adam", 1);
	ShrubberyCreationForm a("home");
	try {
		b.signForm(a);
		a.execute(b);
	} catch (std::exception &e) {
		std::cerr << "\033[1;31mException: " << e.what() << std::endl;
	}

}
