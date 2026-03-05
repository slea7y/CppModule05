#include "Bureaucrat.hpp"
// #include <cstdio>
#include <iostream>

int main() {
	Bureaucrat *Adam = new Bureaucrat("Adam", 1);

	try {
		Adam->incrementGrade();
	} catch ( GradeTooHighException& e ) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "alless gute\n";
}