// #include "Bureacrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeExec;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();
		const std::string getName() const ;
		bool getFormStatus() const ; //_signed
		int getGradeToSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat& b);
		
		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Form& obj);
//  {
	// os << obj.getName(); 
// }
