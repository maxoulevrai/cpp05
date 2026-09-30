/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:13:33 by codespace         #+#    #+#             */
/*   Updated: 2026/09/30 16:39:42 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(): _name("Othmane"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) { }

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeIsTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeIsTooLowException();
	else 
}

Form::Form(const Form &other):
		_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) { }

Form &Form::operator=(const Form &other) { }
Form::~Form() { }

std::string	Form::getName(void) const {
	return (this->_name);
}

bool		Form::getSignStatus(void) {
	return (this->_isSigned);
}

int			Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int			Form::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

void		Form::beSigned(Bureaucrat &bureaucrat) {

}