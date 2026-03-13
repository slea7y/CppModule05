#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "\033[35m* Presidential Pardon Form default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25,5) {
	std::cout << "\033[35m* Presidential Pardon Form parameterized constructor called *\033[0m" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &obj ) {
	std::cout << "\033[35m* Presidential Pardon Form copy constructor *\033[0m" << std::endl;
	this->_target = obj._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &obj ) {
	std::cout << "\033[35m* Presidential Pardon Form assigment operator *\033[0m" << std::endl;
	if (this != &obj){
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\033[35m* Presidential Pardon Form default destructor*\033[0m" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getFormStatus())
		throw FormNotSignedException();
	if (this->getGradeExec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "I inform you that " << this->_target << " has been pardoned by Zaphod Beeblebrox, slay !" << std::endl ;
	std::cout << "\033[1;32m" << executor << " executed " << this->getName() << "\033[0m" << std::endl ;
}

std::string PresidentialPardonForm::getTarget() {
	return this->_target;
}

AForm *PresidentialPardonForm::createForm(std::string target) {
	return new PresidentialPardonForm(target);
}
