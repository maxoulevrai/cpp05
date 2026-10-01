#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade is too low");
}

std::string Bureaucrat::getName(void) const { return (_name); }
int Bureaucrat::getGrade(void) const { return (_grade); }

void Bureaucrat::increment(void) {
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrement(void) {
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception const &exception) {
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << exception.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception const &exception) {
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << exception.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
