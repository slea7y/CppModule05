#include "Bureacrat.hpp"
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
	std::cout << "orthodox canonical form tests for Form class" << std::endl;
	
	Form f("divorce papers", 1 ,1);
	Bureaucrat b("adam", 2);
	std::cout << f << std::endl;
	std::cout << b << std::endl ;
	
	//adam tries to sign the papers but hes grade is too low
	try {
		b.signForm(f);
	} catch(std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}

	//lets increment grade now
	try {
		b.incrementGrade();
		b.signForm(f);
	} catch(std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
		
}