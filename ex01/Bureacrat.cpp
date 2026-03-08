#include "Bureacrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("SomeGuy"), _grade(150) {
	std::cout << "* default constructor called *" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
	std::cout << "* parameterized constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name) , _grade(obj._grade) {
	std::cout << "* copy constructor *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj)
		this->_grade = obj._grade;
	std::cout << "* assignment operator *\n" << _name << ", bureaucrat grade " << _grade << std::endl;
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
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade > 150)
		throw GradeTooLowException();
	std::cout << "decrementing this grade from " << this->_grade << " to " << this->_grade + 1 << "!" << std::endl;
	setGrade(this->_grade += 1);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "garde too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "garde too high";
}

void Bureaucrat::signForm(Form &f) {
	f.beSigned(*this);		
}
// std::ostream& operator<<(std::ostream& os, const Fixed& obj)

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName();
	return os;
}
