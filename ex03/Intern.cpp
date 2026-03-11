#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() : formPointer(NULL) {
	std::cout << "* Intern's default constructor *"<< std::endl ;
}

Intern::Intern( const Intern &obj ) : formPointer(obj.formPointer) {
	std::cout << "* Intern's parameterized constructor *"<< std::endl ;
}

Intern &Intern::operator=( const Intern &other ) {
	if (this != &other)
		this->formPointer = other.formPointer;
	return  *this;
}

Intern::~Intern() {
	if (this->formPointer != NULL) {
		delete this->formPointer;
	}
}

AForm *Intern::makeForm( std::string name, std::string target ) {
	std::string names[] = {"shrubbery creation",
		"presidental pardon", "robotomy request"};
	
	typedef AForm* (*fp)(std::string target);

	fp functions[] = { 
		ShrubberyCreationForm::createForm,
		PresidentalPardonForm::createForm,
		RobotomyRequestForm::createForm
	};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl; 
			return ((functions[i])(target)); 
		}
	}
	// throw AForm::GradeTooLowException();
	std::cout << "[" << name << "] this name doesnt match any avilable forms name" << std::endl; 
	return (NULL);
}
