#include "AForm.hpp"

class PresidentalPardonForm : public AForm {
	private:
		std::string _target;
		PresidentalPardonForm();
	public:
		PresidentalPardonForm(std::string target);
		PresidentalPardonForm( const PresidentalPardonForm &obj );
		PresidentalPardonForm &operator=( const PresidentalPardonForm &obj );
		~PresidentalPardonForm();
		void execute(const Bureaucrat &executor) const override;
		std::string getTarget();
};