#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main() {
	// assigment with grade too high //u can see here that no bureaucrat was created
	try {
		std::cout << "==================================\n" << "assigment with grade too high"
		<< std::endl;
		Bureaucrat("Adam", 0);
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cout << "==================================\n";
	// assigment with grade too low
	try {
		std::cout << "==================================\n" << "assigment with grade too low"
		<< std::endl;
		Bureaucrat("Adam", 151);
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cout << "==================================\n";
	// correct assigment
	try {
		std::cout << "==================================\n" << "grade in correct ratio ;)"
		<< std::endl;
		Bureaucrat("Adam", 1);
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cerr << "\033[1;32mno exception\033[0m everything okay 👍"<< std::endl;
	std::cout << "==================================\n";
	// correct increment
		try {
		std::cout << "==================================\n" << "increment grade correctlly"
		<< std::endl;
		Bureaucrat *Adam = new Bureaucrat("Adam", 2);
		Adam->incrementGrade();
		delete Adam;
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cerr << "\033[1;32mno exception\033[0m everything okay 👍"<< std::endl;
	std::cout << "==================================\n";
	// incorrect increment
		try {
		std::cout << "==================================\n" << "increment grade incorrectlly"
		<< std::endl;
		Bureaucrat Adam = Bureaucrat("Adam", 1);
		Adam.incrementGrade();
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cout << "==================================\n";

	// correct decrement
		try {
		std::cout << "==================================\n" << "decrement grade correctlly"
		<< std::endl;
		Bureaucrat *Adam = new Bureaucrat("Adam", 1);
		Adam->decrementGrade();
		delete Adam;
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cerr << "\033[1;32mno exception\033[0m everything okay 👍"<< std::endl;
	std::cout << "==================================\n";
	// incorrect decrement
		try {
		std::cout << "==================================\n" << "decrement grade incorrectlly"
		<< std::endl;
		Bureaucrat Adam = Bureaucrat("Adam", 150);
		Adam.decrementGrade();
	} catch (std::exception& e ) {
		std::cerr << "\033[1;31mException: \033[0m" << e.what() << std::endl;
	}
	std::cout << "==================================\n";

	//tests for orthodox canonical form
	std::cout << "==================================\n";
	std::cout << "* orthodox canonical form test *" << std::endl;
	Bureaucrat a;
	Bureaucrat b("name", 15);
	a = b;
	Bureaucrat c(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}