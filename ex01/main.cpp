/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:26:36 by maleca            #+#    #+#             */
/*   Updated: 2026/09/25 19:10:15 by maleca           ###   ########.fr       */
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
	Bureaucrat alice("Alice", 42);
	std::cout << alice << std::endl;

	alice.increment();
	std::cout << "After increment: " << alice << std::endl;
	alice.decrement();
	std::cout << "After decrement: " << alice << std::endl;

	Bureaucrat copy(alice);
	std::cout << "Copy: " << copy << std::endl;

	Bureaucrat assigned("Assigned", 100);
	assigned = alice;
	std::cout << "Assigned: " << assigned << std::endl;

	testInvalidGrades();
	return (0);
}
