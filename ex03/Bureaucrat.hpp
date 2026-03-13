#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
// #include "Form.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		const std::string getName() const ;
		int getGrade() const ;
		void setGrade(int grade);
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &f);
		void executeForm(AForm const & form);
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);