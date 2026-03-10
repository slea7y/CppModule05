#include "AForm.hpp"

class PresidentalPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentalPardonForm(std::string target);
		PresidentalPardonForm( const PresidentalPardonForm &obj );
		PresidentalPardonForm &operator=( const PresidentalPardonForm &obj );
		~PresidentalPardonForm();
		
};