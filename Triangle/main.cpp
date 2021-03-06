// Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <assert.h>
#include  <math.h>
using std::cout;
using std::endl;

int main()
{
	double a1, a2, a3, s1, s2, s3;
	int userInput;
	double pi = 3.14159;
	std::cout << "Type 1 for AAA\nType 2 for AAS\nType 3 for ASA \nType 4 for SAS\nType 5 for SSA \nType 6 for SSS\nChoose a triangle to solve:\t ";
	std::cin >> userInput;

	//control statements for AAA
	if (userInput == 1) 
		{
		int triangle = 0;

			std::cout << "Enter the first known angle:\t ";
			std::cin >> a1;

			std::cout << "Enter the second known angle:\t ";
			std::cin >> a2;

			std::cout << "Enter the second known angle:\t ";
			std::cin >> a3;
			
			/*valididate triangle*/
			triangle = a1 + a2 + a3;
			
			if (triangle != 180) 
			{
				std::cout << "\nThe sum of the angles of a triangle is always 180 degrees." << endl;
			}
			else
			{
				std::cout << "\nThe angles are: " << a1 << ", " << a2 << ", " << a3 << endl;
				std::cout << "AAA triangle is impossible to sove further since theire  is nothing to show us size." << endl;
			}
		}
	else if (userInput == 2) //AAS
	{
		double unknown_Angle = 0.0;

		std::cout << "Enter the first angle\t: ";
		std::cin >> a1;

		std::cout << "Enter the second angle\t: ";
		std::cin >> a2;

		std::cout << "Enter the side\t\t: ";
		std::cin >> s1;

		//Calculation for missing 1 angle and 2 sides
		unknown_Angle = 180.0 - (a1 + a2);
		s2 = (s1 * sin(a1 * pi / 180)) / sin(a2 * pi / 180);
		s3 = (s1 * sin(unknown_Angle)) / sin(a2 * pi / 180);

		//display results
		std::cout << "The angles are: " << std::fixed << std::setprecision(2) << a1 << ", " << a2 << ", " << unknown_Angle << endl;
		std::cout << "The sides are: " << std::fixed << std::setprecision(2) << s1 << ", " << s2 << ", " << s3 << endl;

	}
	else if (userInput == 3) //ASA
	{
		int unknown_Angle = 0;

		std::cout << "Enter the first angle\t: ";
		std::cin >> a1;

		std::cout << "Enter the side\t\t: ";
		std::cin >> s1;

		std::cout << "Enter the second angle\t: ";
		std::cin >> a2;

		//Calculation for missing 1 angle and 2 sides
		unknown_Angle = 180.0 - a1 - a2;

		s2 = (s1 / sin(unknown_Angle)) * sin(a2 * pi / 180);
		s3 = (s1 / sin(unknown_Angle)) *sin(a1 * pi / 180);

		//display results
		std::cout << "\nThe angles are: " << std::fixed << std::setprecision(2) << a1 << ", " << a2 << ", " << unknown_Angle << endl;
		std::cout << "The sides are: " << std::fixed << std::setprecision(2) << s1 << ", " << s2 << ", " << s3 << endl;
	}
	
	else if (userInput == 4) //SAS
	{
		std::cout << "Enter the first angle\t: ";
		std::cin >> a1;

		std::cout << "Enter the first side\t: ";
		std::cin >> s1;

		std::cout << "Enter the second side\t: ";
		std::cin >> s2;

		//Calculation for missing 1 side
		s3 = sqrt(((s1 * s1) + (s2 * s2)) - 2 * (s1 * s2) * cos(a1 * 3.14 / 180));

		a2 = asin(sin(a1 * 3.14 / 180))* s1 / s3 * 180 / pi; //convert from radian to degree
		a3 = 180 - (a1 + a2);
		//display results
		std::cout << "\nThe angles are: " << std::fixed << std::setprecision(2) << a1 << ", " << a2 << ", " << a3 << endl;
		std::cout << "The sides are: " << std::fixed << std::setprecision(2) << s1 << ", " << s2 << ", " << s3 << endl;
	}
	else if (userInput == 5) //SSA
	{
		double unknown_side = 0.0;
		std::cout << "Enter angle\t\t: ";
		std::cin >> a1;

		std::cout << "Enter the first side\t: ";
		std::cin >> s1;

		std::cout << "Enter the second side\t: ";
		std::cin >> s2;

		//Calculation

		a2 = asin((s2 * sin(31 * pi / 180 )) / s1) * 180 / pi;

		a3 = 180 - a1 - a2;
		unknown_side = (sin(a3 * 3.14 / 180) * s1) / sin(a1 * 3.14 / 180);
		//display results
		std::cout << "\nThe angles are: " << std::fixed << std::setprecision(2) << a1 << ", " << a2 << ", " << a3 << endl;
		std::cout << "The sides are: " << std::fixed << std::setprecision(2) << s1 << ", " << s2 << ", " << unknown_side << endl;
	}
	else if (userInput == 6) //SSS
	{
		std::cout << "Enter the first side\t: ";
		std::cin >> s1;

		std::cout << "Enter the second side\t: ";
		std::cin >> s2;

		std::cout << "Enter the second side\t: ";
		std::cin >> s3;

		//Calculation
		a1 = (pow(s2, 2) + pow(s3, 2) - pow(s1, 2)) / (2 * s2 * s3);
		a1 = acos(a1) * 180 / pi;

		a2 = (pow(s3, 2) + pow(s1, 2) - pow(s2, 2)) / (2 * s3 * s1);
		a2 = acos(a2) * 180 / pi;

		a3 = 180 - a1 - a2;
		//display results
		std::cout << "\nThe angles are: " << std::fixed << std::setprecision(2) << a1 << ", " << a2 << ", " << a3 << endl;
		std::cout << "The sides are: " << std::fixed << std::setprecision(2) << s1 << ", " << s2 << ", " << s3 << endl;
	}
	else {
		std::cout << "\n\nBye!!" <<endl;	
	}
    return 0;
}

