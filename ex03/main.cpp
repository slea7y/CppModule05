#include <exception>
#include <iostream>
#include <ostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(0));

	std::cout << "~~~ Intern form creation test ~~~" << std::endl;

	Intern someRandomIntern;

	AForm* scForm = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* rrForm = someRandomIntern.makeForm("robotomy request", "factory");
	AForm* ppForm = someRandomIntern.makeForm("presidential pardon", "andrei duda");

	// invalid form
	AForm* wrongForm = someRandomIntern.makeForm("coffee request", "kitchen");

	std::cout << std::endl << "~~~ wrong form ~~~" << std::endl;

	if (wrongForm) {
		std::cout << "never gets called🔥🔥🔥🔥" << std::endl;
	}

	std::cout << std::endl << "~~~ Bureaucrats ~~~" << std::endl;

	Bureaucrat low("low", 146);
	Bureaucrat mid("mid", 40);
	Bureaucrat high("high", 1);

	std::cout << std::endl << "~~~ Test shrubbery ~~~" << std::endl;
	if (scForm) {
		low.signForm(*scForm);
		mid.signForm(*scForm);
		mid.executeForm(*scForm);
	}

	std::cout << std::endl << "~~~ Test robotomy ~~~" << std::endl;
	if (rrForm) {
		mid.signForm(*rrForm);
		mid.executeForm(*rrForm);
		high.executeForm(*rrForm);
	}

	std::cout << std::endl << "~~~ Test presidential pardon ~~~" << std::endl;
	if (ppForm) {
		high.signForm(*ppForm);
		high.executeForm(*ppForm);
	}

	delete scForm;
	delete rrForm;
	delete ppForm;

	return 0;
}