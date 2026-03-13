#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "* Intern's default constructor *"<< std::endl ;
}

Intern::Intern( const Intern &obj ) {
	std::cout << "* Intern's copy constructor *"<< std::endl ;
	(void)obj;		
}

Intern &Intern::operator=( const Intern &other ) {
	std::cout << "* Intern's assigment operator *"<< std::endl ;
	(void)other;		
	return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm( std::string name, std::string target ) {
	const std::string names[] = {"shrubbery creation",
		"presidential pardon", "robotomy request"};
	
	typedef AForm* (*fp)(std::string target);

	fp functions[] = { 
		ShrubberyCreationForm::createForm,
		PresidentialPardonForm::createForm,
		RobotomyRequestForm::createForm
	};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl; 
			return ((functions[i])(target)); 
		}
	}
	std::cout << "[" << name << "] this name doesnt match any available forms name" << std::endl; 
	return nullptr;
}
