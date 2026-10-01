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
	return (0);
}
