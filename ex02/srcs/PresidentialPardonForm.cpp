#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other), _target(other._target) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void PresidentialPardonForm::doExecute(Bureaucrat const &executor) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
