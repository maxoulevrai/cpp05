/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:26:42 by maleca            #+#    #+#             */
/*   Updated: 2026/10/01 10:16:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

Bureaucrat::Bureaucrat(): _name("Othmane"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) { }

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_name = other.getName();
		this->_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void		Bureaucrat::increment(void) {
	this->_grade -= 1;
}

void		Bureaucrat::decrement(void) {
	this->_grade += 1;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os	<< bureaucrat.getName()
		<< ", bureaucrat grade"
		<< bureaucrat.getGrade();
	return (os);
}
