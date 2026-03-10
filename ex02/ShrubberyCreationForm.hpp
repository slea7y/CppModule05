#include "AForm.hpp"
#include <iterator>

class ShrubberyCreationForm : public AForm {
	private:
		std::string			_target;	
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat &executor) const override;
		std::string getTarget();
	};

// std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &obj);