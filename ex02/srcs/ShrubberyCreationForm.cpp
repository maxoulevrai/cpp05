#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other), _target(other._target) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void ShrubberyCreationForm::doExecute(Bureaucrat const &executor) const {
	(void)executor;
	std::ofstream output((_target + "_shrubbery").c_str());
	if (!output)
		return;
	output << "       /\\\n"
		<< "      /  \\\n"
		<< "     /    \\\n"
		<< "    /______\\\n"
		<< "      ||||\n"
		<< "      ||||\n";
}
