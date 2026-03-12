#include <exception>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	//orthodox canonical form for all the classes of forms
	std::cout << std::endl << "~~~test orthodox canonical form~~~" << std::endl;
	ShrubberyCreationForm scForm("home");
	PresidentalPardonForm ppForm("moon");
	RobotomyRequestForm rrForm("factory");

	std::cout << std::endl << "~~~test shrubbery creation~~~" << std::endl;
	ShrubberyCreationForm scCopy(scForm);
	ShrubberyCreationForm scAssign("farm");

	scAssign = scCopy;
	std::cout << "print copy: " << scCopy << " with target " << scCopy.getTarget() << std::endl;
	std::cout << "print assign: " << scAssign << " with target " << scAssign.getTarget() << std::endl;

	std::cout << std::endl << "~~~test shrubbery creation~~~" << std::endl;
	PresidentalPardonForm ppCopy(ppForm);
	PresidentalPardonForm ppAssign = ppCopy;

	std::cout << "print copy: " << ppCopy << " with target " << ppCopy.getTarget() << std::endl;
	std::cout << "print assign: " << ppAssign << " with target " << ppAssign.getTarget() << std::endl;

	std::cout << std::endl << "~~~robotomy request creation~~~" << std::endl;
	RobotomyRequestForm rrCopy(rrForm);
	RobotomyRequestForm rrAssign("farm");

	std::cout << "print copy: " << rrCopy << " with target " << rrCopy.getTarget() << std::endl;
	std::cout << "print assign: " << rrAssign << " with target " << rrCopy.getTarget() << std::endl;

	//execute all the classes correctlly
	std::cout << std::endl << "~~~~~~~ sign and execute sc ~~~~~~~" << std::endl;

	Bureaucrat b("tester", 146);
	//try to sign a form with a low grade
	b.signForm(scForm);
	b.incrementGrade();
	b.signForm(scForm);
	b.executeForm(scForm);
	//see a new file should pop up

	std::cout << std::endl << "~~~~~~~ sign and execute pp ~~~~~~~" << std::endl;
	//try to exeute a form thats not signed
	b.executeForm(ppAssign); 
}