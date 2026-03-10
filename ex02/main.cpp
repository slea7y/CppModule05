#include <exception>
#include <iostream>
#include <ostream>
#include "Bureacrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	Bureaucrat b("Adam", 140);
	// ShrubberyCreationForm a("home");  
	// try {
	// 	b.signForm(a);
	// 	a.execute(b);
	// } catch (std::exception &e) {
	// 	std::cerr << "\033[1;31mException: " << e.what() << std::endl;
	// }
	// ShrubberyCreationForm c = a;
	// std::cout <<"show me " << c.getTarget() << std::endl ;
	PresidentalPardonForm r("kkkkkk");
	// std::cout <<"show me2 " << r.getName() << std::endl ;

	try {
		b.executeForm(r);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
