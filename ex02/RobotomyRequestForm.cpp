#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "\033[34m* Robotomy Request Form default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy Request", 72, 45) {
	std::cout << "\033[34m* Robotomy Request Form parameterized constructor *\033[0m" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &obj ) : AForm(obj) {
	std::cout << "\033[34m* Robotomy Request Form copy constructor *\033[0m" << std::endl;
	this->_target = obj._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &obj ) {
	std::cout << "\033[34m* Robotomy Request Form assigment operator *\033[0m" << std::endl;
	if (this != &obj){
		AForm::operator=(obj);
		this->_target = obj._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\033[34m* Robotomy Request Form destructor *\033[0m" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getFormStatus())
		throw FormNotSignedException();
	if (this->getGradeExec() > executor.getGrade())
		throw GradeTooLowException();
	std::cout << "\033[1;32m" << executor << " executed " << this->getName() << "\033[0m" << std::endl ;
	srand(time(0));
	int random = rand() % 2;
	std::cout << "\033[34m~~~%* Makes some drilling noises *%~~~\033[0m" << std::endl ;
	if (random == 0)
		std::cout << this->_target << " filed to robotomy" << std::endl ;
	else
		std::cout << this->_target << " has beedn robotomized succesfully" << std::endl ;
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
}
