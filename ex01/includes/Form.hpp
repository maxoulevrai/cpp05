/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:20:52 by codespace         #+#    #+#             */
/*   Updated: 2026/09/28 05:13:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"


class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string	getName(void) const;
		bool		getSignStatus(void);
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		void		beSigned(Bureaucrat &bureaucrat);

		class GradeIsTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeIsTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif