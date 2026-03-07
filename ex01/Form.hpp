#include <iostream>
#include <ostream>
#include <string>

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
		std::string getName() const ;
		void beSigned();
		
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
//  {
	// os << obj.getName(); 
// }
