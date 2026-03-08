#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		// const std::string	_name;
		// bool				_signed;
		const int			_gradeToSign;
		const int			_gradeExec;
		std::string			_target;	
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};