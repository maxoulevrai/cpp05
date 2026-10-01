#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Intern intern;
	Bureaucrat executive("Executive", 1);
	Bureaucrat junior("Junior", 150);
	const char *names[] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
	};

	for (int index = 0; index < 3; ++index) {
		AForm *form = intern.makeForm(names[index], "Target");
		if (form != NULL) {
			junior.signForm(*form);
			executive.signForm(*form);
			executive.executeForm(*form);
			delete form;
		}
	}

	AForm *unknown = intern.makeForm("coffee request", "Target");
	if (unknown != NULL)
		delete unknown;
	return (0);
}
