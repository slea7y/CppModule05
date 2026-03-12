#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Form;
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

		//new 
		void signForm(Form &f);
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