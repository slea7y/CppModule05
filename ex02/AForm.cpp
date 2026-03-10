#include "AForm.hpp"
#include "Bureacrat.hpp"
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
	std::cout << "* parameterized constructor *\n" << _name << ", form grade to sign: " << _gradeToSign << std::endl;
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

const char *AForm::FileNotCreatedException::what() const throw() {
	return "file count not be created :_(";
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
	std::cout << "check out: " << b.getGrade() << " " << this->_gradeToSign << std::endl;
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


void AForm::execute(Bureaucrat const &executor) const {
	std::cout << "heey it should never happen ya" << std::endl;

	// if (!this->_signed)
	// 	throw FormNotSignedException();
	// else if (executor.getGrade() < this->_gradeExec)
	// 	throw GradeTooLowException();	
	// else {
	// 	// std::co
	// }
}


std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << " " << obj.getFormStatus() << " " << obj.getGradeToSign() << " " << obj.getGradeExec();
	// os << obj.getName();
	
	return os;
}
