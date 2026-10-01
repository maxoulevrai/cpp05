#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other):
	_name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) { }

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() { }

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::string AForm::getName(void) const { return (_name); }
bool AForm::getSignStatus(void) const { return (_isSigned); }
int AForm::getGradeToSign(void) const { return (_gradeToSign); }
int AForm::getGradeToExecute(void) const { return (_gradeToExecute); }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	doExecute(executor);
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
	return (os << form.getName() << ", form grade to sign "
		<< form.getGradeToSign() << ", form grade to execute "
		<< form.getGradeToExecute() << ", signed "
		<< (form.getSignStatus() ? "yes" : "no"));
}
