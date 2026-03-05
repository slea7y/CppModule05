#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void setGrade(int grade);

		void incrementGrade();
		void decrementGrade();

};
		// exeptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};