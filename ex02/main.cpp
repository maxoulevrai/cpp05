#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void testForm(AForm &form, Bureaucrat &signer, Bureaucrat &executor) {
	std::cout << "\n" << form << std::endl;
	signer.signForm(form);
	executor.executeForm(form);
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Bureaucrat junior("Junior", 150);
	Bureaucrat manager("Manager", 50);
	Bureaucrat executive("Executive", 1);
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "--- Unsigned execution ---" << std::endl;
	junior.executeForm(shrubbery);

	std::cout << "--- Shrubbery ---" << std::endl;
	testForm(shrubbery, executive, executive);

	std::cout << "--- Robotomy ---" << std::endl;
	testForm(robotomy, manager, executive);

	std::cout << "--- Presidential pardon ---" << std::endl;
	testForm(pardon, executive, executive);

	std::cout << "--- Execution grade failure ---" << std::endl;
	Bureaucrat lowExecutive("Low executive", 140);
	lowExecutive.executeForm(shrubbery);
	return (0);
}
