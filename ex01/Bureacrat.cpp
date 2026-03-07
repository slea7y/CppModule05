#include "Bureacrat.hpp"

Bureaucrat::Bureaucrat() : _name("SomeGuy"), _grade(150) {
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name) , _grade(obj._grade) {
	std::cout << "* copy constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj)
		this->_grade = obj._grade;
	std::cout << "* assignment operator *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
	return *this;
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(int grade) {
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "* set grade *\n" << _name << ", bureaucrat's new grade " << _grade << std::endl;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade < 1)
		throw GradeTooHighException();
	std::cout << "incrementing this grade from " << this->_grade << " to " << this->_grade - 1 << "!" << std::endl;
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "decrementing this grade from " << this->_grade << " to " << this->_grade + 1 << "!" << std::endl;
	this->_grade += 1;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "garde too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "garde too high";
}
