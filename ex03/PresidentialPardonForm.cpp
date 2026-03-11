#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() {
	std::cout << "\033[35m* Presidental Pardon Form default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

PresidentalPardonForm::PresidentalPardonForm(std::string target) : AForm("presidental pardon", 25,5) {
	std::cout << "\033[35m* Presidental Pardon Form parameterized constructor called *\033[0m" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm( const PresidentalPardonForm &obj ) {
	std::cout << "\033[35m* Presidental Pardon Form copy constructor *\033[0m" << std::endl;
}

PresidentalPardonForm &PresidentalPardonForm::operator=( const PresidentalPardonForm &obj ) {
	std::cout << "\033[35m* Presidental Pardon Form assigment operator *\033[0m" << std::endl;
	return *this;
}

PresidentalPardonForm::~PresidentalPardonForm() {
	std::cout << "\033[35m* Presidental Pardon Form default *\033[0m" << std::endl;
}

void PresidentalPardonForm::execute(const Bureaucrat &executor) const {
	std::cout << "I inform you that " << this->_target << "has been pardoned by Zaphod Beeblebrox, slay !" << std::endl ;
}

std::string PresidentalPardonForm::getTarget() {
	return this->_target;
}

AForm *PresidentalPardonForm::createForm(std::string target) {
	return new PresidentalPardonForm(target);
}
