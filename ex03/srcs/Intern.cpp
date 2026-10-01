#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() { }
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}
Intern::~Intern() { }

AForm *Intern::makeForm(std::string formName, std::string target) const {
	if (formName == "shrubbery creation") {
		std::cout << "Intern creates " << formName << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	if (formName == "robotomy request") {
		std::cout << "Intern creates " << formName << std::endl;
		return (new RobotomyRequestForm(target));
	}
	if (formName == "presidential pardon") {
		std::cout << "Intern creates " << formName << std::endl;
		return (new PresidentialPardonForm(target));
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
