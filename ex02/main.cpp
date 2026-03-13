#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(0));

	//orthodox canonical form for all the classes of forms
	std::cout << std::endl << "~~~test orthodox canonical form~~~" << std::endl;
	ShrubberyCreationForm scForm("home");
	PresidentialPardonForm ppForm("moon");
	RobotomyRequestForm rrForm("factory");

	std::cout << std::endl << "~~~test shrubbery creation~~~" << std::endl;
	ShrubberyCreationForm scCopy(scForm);
	ShrubberyCreationForm scAssign("farm");

	scAssign = scCopy;

	std::cout << "print copy: " << scCopy << " with target " << scCopy.getTarget() << std::endl;
	std::cout << "print assign: " << scAssign << " with target " << scAssign.getTarget() << std::endl;

	std::cout << std::endl << "~~~test shrubbery creation~~~" << std::endl;
	PresidentialPardonForm ppCopy(ppForm);
	PresidentialPardonForm ppAssign("farm");

	// ppAssign = ppCopy; uncomment to call for assigment operator

	std::cout << "print copy: " << ppCopy << " with target " << ppCopy.getTarget() << std::endl;
	std::cout << "print assign: " << ppAssign << " with target " << ppAssign.getTarget() << std::endl;

	std::cout << std::endl << "~~~robotomy request creation~~~" << std::endl;
	RobotomyRequestForm rrCopy(rrForm);
	RobotomyRequestForm rrAssign("farm");

	std::cout << "print copy: " << rrCopy << " with target " << rrCopy.getTarget() << std::endl;
	std::cout << "print assign: " << rrAssign << " with target " << rrAssign.getTarget() << std::endl;

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
	b.executeForm(ppForm); 
	Bureaucrat bw("the writer", 25);
	bw.signForm(ppForm);
	bw.executeForm(ppForm);
	Bureaucrat be("the executor", 5);
	be.executeForm(ppForm);

	std::cout << std::endl << "~~~~~~~ sign and execute rr ~~~~~~~" << std::endl;

	be.signForm(rrForm);
	bw.executeForm(rrForm);
	be.executeForm(rrForm);
	bw.executeForm(rrForm);
	be.executeForm(rrForm);
	b.executeForm(rrForm);
}