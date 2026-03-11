#include <exception>
#include <iostream>
#include <ostream>
#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	// try {
		Intern guy;
		AForm *rrf;

		rrf = guy.makeForm("spresidental pardon", "target");
		guy.makeForm("robotomy request", "target");
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << "Exception " << e.what() << std::endl;
	// }
	// std::cout <<  << std::endl;
}