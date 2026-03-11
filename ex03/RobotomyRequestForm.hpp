#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &obj );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &obj );
		~RobotomyRequestForm();
		void execute(const Bureaucrat &executor) const override;
		std::string getTarget() const;
		static AForm *createForm( std::string target );
};
