#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string			_target;	
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat &executor) const;
		std::string getTarget();
};
