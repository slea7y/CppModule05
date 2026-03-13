#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137) {
	std::cout << "\033[33m* Shrubbery Creation Form's default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137) {
	std::cout << "\033[33m* Shrubbery Creation Form's parameterized constructor *\033[0m" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	std::cout << "\033[33m* Shrubbery Creation Form's copy constructor *\033[0m" << std::endl;
	this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "\033[33m* Shrubbery Creation Form's assigment operator *\033[0m" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[33m* Shrubbery Creation Form's destructor called *\033[0m" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getFormStatus())
		throw FormNotSignedException();
	std::ofstream file;	
	std::string filename = this->_target + "_shrubbery";
	file.open(filename);
	if (!file.is_open()){
		throw std::runtime_error("filed to create a file");
	}
	for (int i = 0; i < 4; i ++)
	{
			file << "                      &&& &&  & &&\n"
			"                  && &\\/&\\|& ()|/ @, &&\n"
			"                  &\\/(/&/&||/& /_/)_&/_&\n"
			"               &() &\\/&|()|/&\\/ % & ()\n"
			"              &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			"           &&   && & &| &| /& & % ()& /&&\n"
			"            ()&_---()&\\&\\|&&-&&--%---()~\n"
			"                &&     \\|||\n"
			"                        |||\n"
			"                        |||\n"
			"                        |||\n"
			"                  , -=-~  .-^- _\n\n";}
	file.close();
	std::cout << "\033[1;32m" << executor << " executed " << this->getName() << "\033[0m" << std::endl ;
}


std::string ShrubberyCreationForm::getTarget() {
	return (this->_target);
}

AForm *ShrubberyCreationForm::createForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
