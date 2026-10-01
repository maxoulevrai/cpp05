#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	protected:
		virtual void doExecute(Bureaucrat const &executor) const = 0;
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		std::string getName(void) const;
		bool getSignStatus(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
