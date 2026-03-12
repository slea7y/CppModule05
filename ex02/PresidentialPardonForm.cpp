#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() {
	std::cout << "\033[35m* Presidental Pardon Form default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

PresidentalPardonForm::PresidentalPardonForm(std::string target) : AForm("Presidental Pardon", 25,5) {
	std::cout << "\033[35m* Presidental Pardon Form parameterized constructor called *\033[0m" << std::endl;
	this->_target = target;
}

PresidentalPardonForm::PresidentalPardonForm( const PresidentalPardonForm &obj ) : AForm(obj) {
	this->_target = obj._target;
	std::cout << "\033[35m* Presidental Pardon Form copy constructor *\033[0m" << std::endl;
}

PresidentalPardonForm &PresidentalPardonForm::operator=( const PresidentalPardonForm &obj ) {
	std::cout << "\033[35m* Presidental Pardon Form assigment operator *\033[0m" << std::endl;
	if (this != &obj){
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	return *this;
}

PresidentalPardonForm::~PresidentalPardonForm() {
	std::cout << "\033[35m* Presidental Pardon Form default *\033[0m" << std::endl;
}

void PresidentalPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getFormStatus())
		throw FormNotSignedException();
	if (this->getGradeExec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "\033[1;32m" << executor << " executed " << this->getName() << "\033[0m" << std::endl ;
	std::cout << "I inform you that " << this->_target << " has been pardoned by Zaphod Beeblebrox, slay !" << std::endl ;
}

std::string PresidentalPardonForm::getTarget() {
	return this->_target;
}