/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:13:33 by codespace         #+#    #+#             */
/*   Updated: 2026/09/28 05:20:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(): _name("Othmane"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) { }*

Form::Form(std::string name, int gradeToSign, int gradeToExec):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) { }

Form::Form(const Form &other) { }
Form &Form::operator=(const Form &other) { }
Form::~Form() { }

std::string	getName(void) const;
bool		getSignStatus(void);
int			getGradeToSign(void) const;
int			getGradeToExec(void) const;

void		beSigned(Bureaucrat &bureaucrat);