#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeExec(150) {
	std::cout << "* Form's default constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeExec(gradeToExec) {
	if (gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToExec > 150)
		throw GradeTooLowException();
	else if (gradeToExec < 1)
		throw GradeTooHighException();
	_signed = false;
	std::cout << "* Form's parameterized constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), 
	_gradeExec(other._gradeExec) {
	std::cout << "* Form's copy constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
}

Form &Form::operator=(const Form& other) {
	std::cout << "* Form's assigment constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "* Form's destructor called " << this->_name << " *" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "grade too low";
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getFormStatus() const {
	return this->_signed;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeExec() const {
	return this->_gradeExec;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->getFormStatus() == true) {
		std::cout << b.getName() << " tries to sign [" << this->getName() << "] but this form was already signed " << std::endl ;
		return ;
	}
	this->_signed = true;
	std::cout << b.getName() << " signed " << this->_name << std::endl ;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << " status: " << obj.getFormStatus() << " to sign: " << obj.getGradeToSign() << " to exec: " << obj.getGradeExec();
	return os;
}
