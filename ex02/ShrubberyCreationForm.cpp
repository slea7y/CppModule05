#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shruberry Creation", 145, 137) {
	std::cout << "\033[35m* ShrubberyCreationForm default constructor called *\033[0m" << std::endl;
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry Creation", 145, 137) {
	std::cout << "\033[35m* Shrubbery Creation Form parameterized constructor *\033[0m" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	this->_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	std::cout << "\033[35m* Shrubbery Creation Form copy constructor *\033[0m" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[35m* Shrubbery Creation Form's destructor called *\033[0m" << std::endl;
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
}


std::string ShrubberyCreationForm::getTarget() {
	return (this->_target);
}

// std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &obj) {
// 	os << 
// }
