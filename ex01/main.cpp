#include "Bureacrat.hpp"
#include "Form.hpp"
#include <cstddef>
#include <exception>
#include <ostream>
#include <stdio.h>

int main() {
	try {
		std::cout << "==================================\n" << "assigment with grade to sign too low"
		<< std::endl;
		Form("name", 160, 1);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	// if (f != nullptr)
	//assiging form with wrong grade value for Form
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
	// Form f;
	//assiging form's toExec grade with value too high
	try {
		std::cout << "==================================\n" << "assigment with grade to execute too high"
		<< std::endl;
		Form("name", 58, 0);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}

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