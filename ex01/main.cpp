#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main() {
	//assiging form's toSign grade with value too low
	try {
		std::cout << "==================================\n" << "assigment with grade to sign too low"
		<< std::endl;
		Form("name", 160, 1);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	//assiging form's toExec grade with value too low
	try {
		std::cout << "==================================\n" << "assigment with grade to execute too low"
		<< std::endl;
		Form("name", 58, 155);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	//assiging form's toSign grade with value too high
	try {
		std::cout << "==================================\n" << "assigment with grade to sign too high"
		<< std::endl;
		Form("name", 0, 1);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	//assiging form's toExec grade with value too high
	try {
		std::cout << "==================================\n" << "assigment with grade to execute too high"
		<< std::endl;
		Form("name", 58, 0);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}

	std::cout << "==================================" << std::endl;
	std::cout << "\033[35m* orthodox canonical form tests for Form class *\033[0m" << std::endl;
	
	Form f("divorce papers", 1 ,1);
	Bureaucrat b("adam", 2);
	std::cout << "Form f: " << f << std::endl;
	std::cout << "Bureacrat b: " << b << std::endl ;
	Form m("birth certificate", 150 ,150);

	std::cout << "m before assigment constructor: "<< m << std::endl;
	m = f;
	std::cout << "m after assigment constructor: "<< m << std::endl;
	//as u see the name and grades will remain the same bc they r constant

	Form copy = f;
	std::cout << "Form f: " << f << std::endl;
	std::cout << "Form copy: " << copy << std::endl;

	std::cout << "==================================" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "\033[35m* tests for signing the papers *\033[0m" << std::endl;
	
	b.signForm(f);
	b.incrementGrade();
	b.signForm(f);
	//try to sign already signed form
	b.signForm(f);
	Bureaucrat b2("The Guy who knows everything", 1);
	b2.signForm(f);
}