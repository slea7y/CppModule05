#include "Bureaucrat.hpp"
// #include "stdio.h"

Bureaucrat::Bureaucrat() : _name("someGuy13"), _grade(150) {
	std::cout << "* default constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade > 150){
		throw GradeTooLowException();
	}
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
	std::cout << "* parameterized constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name) , _grade(obj._grade) {
	std::cout << "* copy constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "* assignment operator *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "* destructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
	std::cout << "* set grade *\n" << _name << ", bureaucrat's new grade " << _grade << std::endl;

}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
};
	
void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	std::cout << "incrementing this grade from " << this->_grade << " to " << this->_grade - 1 << "!" << std::endl;
	setGrade(this->_grade -= 1);
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << this->_grade << " decrementing this grade !" << std::endl;
	setGrade(this->_grade += 1);
}