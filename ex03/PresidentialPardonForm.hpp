#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( const PresidentialPardonForm &obj );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &obj );
		~PresidentialPardonForm();
		void execute(const Bureaucrat &executor) const;
		std::string getTarget();
		static AForm *createForm(std::string target);
};