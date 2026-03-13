#pragma once
#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeExec;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm() ;
		const std::string getName() const ;
		bool getFormStatus() const ; //_signed
		int getGradeToSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat& b);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
