#include "AForm.hpp"
#include "Bureaucrat.hpp"

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
};