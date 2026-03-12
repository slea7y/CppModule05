#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeExec(150) {
	std::cout << "* default constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeExec(gradeToExec) {
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

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), 
	_gradeExec(other._gradeExec) {
}

AForm &AForm::operator=(const AForm& other) {
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "* Form's destructor called *" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "form not signed";
}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getFormStatus() const {
	return this->_signed;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeExec() const {
	return this->_gradeExec;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->getFormStatus() == true) {
		std::cout << b.getName() << " tries to sign [" << this->getName() << "] but this form was already signed " << std::endl ;
		return ;
	}
	this->_signed = true;
	std::cout << b.getName() << " signed " << this->_name << std::endl ;
}


void AForm::execute(Bureaucrat const &executor) const {
	(void)executor;
}


std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << " " << obj.getFormStatus() << " " << obj.getGradeToSign() << " " << obj.getGradeExec();
	return os;
}
