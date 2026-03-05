#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) , _grade(grade) {

}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name) , _grade(obj._grade) {
	
}

Bureaucrat::~Bureaucrat() {}

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
		throw GradeTooLowException();
	this->_grade = grade;
}

// const char *Bureaucrat::GradeTooHighException::what() const throw() {
const char *GradeTooHighException::what() const throw() {
	return "Exception: Grade too high";
};

// const char *Bureaucrat::GradeTooLowException::what() const throw() {
const char *GradeTooLowException::what() const throw() {
	return "Exception: Grade too low";
};
	
void Bureaucrat::incrementGrade() {
	try {
		this->_grade -= 1;
	}
	catch (GradeTooHighException& e) {
		GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	this->_grade += 1;
}