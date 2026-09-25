/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:26:42 by maleca            #+#    #+#             */
/*   Updated: 2026/09/25 18:32:40 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Othmane"), _grade(150) {
	std::cout << "Othmane Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Othmane Param constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	std::cout << "Othmane Copy constructor called" << std::endl; 
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Othmane Copy assignment constructor called" << std::endl; 
	if (this != &other) {
		this->_name = other.getName();
		this->_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Othmane destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void		Bureaucrat::setName(const std::string name) {
	this->_name = name;
}

void		Bureaucrat::setGrade(const int grade) {
	this->_grade = grade;
}

void		Bureaucrat::increment(void) {
	this->_grade -= 1;
}

void		Bureaucrat::decrement(void) {
	this->_grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os	<< bureaucrat.getName()
		<< ", bureaucrat grade"
		<< bureaucrat.getGrade();
	return (os);
}
