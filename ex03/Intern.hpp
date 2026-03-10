#include "AForm.hpp"

class Intern {
	private:
		Intern();
	public:
		Intern( std::string name, std::string target );
		Intern( const Intern &obj );
		Intern &operator=( const Intern &other );
		~Intern();
		AForm *makeForm( std::string name, std::string target );
};