#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
