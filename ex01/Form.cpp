#include "Form.hpp"
#include "Bureacrat.hpp"
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
	std::cout << "* parameterized constructor *\n" << _name << ", formgrade to sign: " << _gradeToSign << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), 
	_gradeExec(other._gradeExec) {
}

Form &Form::operator=(const Form& other) {
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "* Form's destructor called *\ninfo:" << std::endl;
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
	if (b.getGrade() > this->_gradeToSign) {
		std::cout << b.getName() << " couldn’t sign " << this->_name << " because " << "hes grade is too low" << std::endl ;
		// throw GradeTooLowException();	
	}
	// else if (b.getGrade() < this->_gradeToSign) {
	// 	std::cout << b.getName() << " couldn’t sign " << this->_name << " because " << std::endl;
	// 	// throw GradeTooHighException();
	// }
	else
	{
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->_name << std::endl ;
	}
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << " " << obj.getFormStatus() << " " << obj.getGradeToSign() << " " << obj.getGradeExec();
	// os << obj.getName();
	
	return os;
}
