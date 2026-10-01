/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:26:36 by maleca            #+#    #+#             */
/*   Updated: 2026/10/01 10:16:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

static void testInvalidGrades(void)
{
	try
	{
		Bureaucrat bureaucrat("Too high", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << "Error: " << exception.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Too low", 151);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << "Error: " << exception.what() << std::endl;
	}

}

static void testForms(void)
{
	std::cout << "\n--- Form construction tests ---" << std::endl;
	try
	{
		Form invalidForm("Invalid form", 0, 75);
		std::cout << invalidForm.getName() << " should not exist" << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << "Invalid signing grade: " << exception.what() << std::endl;
	}

	try
	{
		Form invalidForm("Invalid form", 75, 151);
		std::cout << invalidForm.getName() << " should not exist" << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << "Invalid execution grade: " << exception.what() << std::endl;
	}

	std::cout << "\n--- Form signing tests ---" << std::endl;
	Form taxForm("Tax form", 50, 25);
	Bureaucrat senior("Senior", 25);
	Bureaucrat junior("Junior", 100);

	std::cout << taxForm.getName() << " signed: "
		<< (taxForm.getSignStatus() ? "yes" : "no") << std::endl;
	junior.signForm(taxForm);
	std::cout << "After junior attempt: "
		<< (taxForm.getSignStatus() ? "signed" : "not signed") << std::endl;
	senior.signForm(taxForm);
	std::cout << "After senior attempt: "
		<< (taxForm.getSignStatus() ? "signed" : "not signed") << std::endl;

	std::cout << "\n--- Direct beSigned test ---" << std::endl;
	Form directForm("Direct form", 75, 75);
	try
	{
		directForm.beSigned(junior);
	}
	catch (const std::exception &exception)
	{
		std::cout << "Direct signing refused: " << exception.what() << std::endl;
	}
	try
	{
		directForm.beSigned(senior);
		std::cout << "Direct signing accepted" << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << "Direct signing refused: " << exception.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat Othmane("Othmane", 42);
	std::cout << Othmane << std::endl;

	Othmane.increment();
	std::cout << "After increment: " << Othmane << std::endl;
	Othmane.decrement();
	std::cout << "After decrement: " << Othmane << std::endl;

	Bureaucrat copy(Othmane);
	std::cout << "Copy: " << copy << std::endl;

	Bureaucrat assigned("Assigned", 100);
	assigned = Othmane;
	std::cout << "Assigned: " << assigned << std::endl;

	testInvalidGrades();
	testForms();
	return (0);
}
