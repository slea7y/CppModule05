#pragma once

#include "AForm.hpp"
class Intern {
	private:
		AForm *formPointer;
	public:
		Intern();
		// Intern( std::string name, std::string target );
		Intern( const Intern &obj );
		Intern &operator=( const Intern &other );
		~Intern();
		AForm *makeForm( std::string name, std::string target );
};
