#pragma once

#include "AForm.hpp"
class Intern {
	public:
		Intern();
		Intern( const Intern &obj );
		Intern &operator=( const Intern &other );
		~Intern();
		AForm *makeForm( std::string name, std::string target );
};
