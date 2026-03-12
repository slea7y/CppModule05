#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat() : _name("SomeGuy"), _grade(150) {
	std::cout << "*  Bureaucrat's default constructor called *" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
	std::cout << "* Bureaucrat's parameterized constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name) , _grade(obj._grade) {
	std::cout << "* Bureaucrat's copy constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj)
		this->_grade = obj._grade;
	std::cout << "* Bureaucrat's assignment operator *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "* Bureaucrat's destructor called *" << std::endl;
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
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "decrementing this grade from " << this->_grade << " to " << this->_grade + 1 << "!" << std::endl;
	_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "garde too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "garde too high";
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this); 
	}
	catch (std::exception &e) {
		std::cerr << "\033[1;31mException: \033[0m" << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl ;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << " with grade: " << obj.getGrade();
	return os;
}
