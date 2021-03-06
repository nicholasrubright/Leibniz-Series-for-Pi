
//Program that displays the Leibniz series based on a user input for the number of iterations

#include <cmath>
#include <iostream>

using namespace std;

													//Must set the functions prototype before main in order for main to call the functions below it
bool isValid(int);									//Prototype for isValid function
int denominator(int);								//Prototype for denominator function
int numerator(int);									//Prototype for numerator function
void printSeries(int, int);							//Prototpe for printSeries functions


int main()
{
	int iterations;									//Variable for the number of iterations of the series
	cout << "Enter Number of Iterations: ";			//Prompt asking for user input
	cin >> iterations;								//Takes the user input and assigns it to the number of iterations
	
	while (isValid(iterations) == false)			//Validates the number of iterations as they can't less than or 0
	{
		cout << "Enter a number greater than 0: ";	//Prompt asking for a value greater than 0
		cin >> iterations;							//Assigns the value to iterations
		if (isValid(iterations) == true)			//Breaks the while loop if number of iterations is valid	//if(iterations > 0) also correct
			break;									//Break statement to break the while loop
	}

	cout << "Leibniz Series for Pi: ";				//Displays this at the beginning of the series
	
	for (int i = 0; i < iterations; i++)			//For loop that displays the series from the number of iterations
	{
		printSeries(numerator(i), denominator(i));	//Calls the printSeries function that also calls the numerator/denominator function with the value of i
	}												//The value i will determine the number of iterations the series go through and calls the functions as such
	
}

bool isValid(int integer)							//Validation function that ensures the number of iterations is greater than 0
{
	if (integer > 0)								//If statement to determine if the value is greater than 0
		return true;								//Returns true if the value is greater than 0
	else
		return false;								//Anything else it returns false
}

int denominator(int n)								//Denominator function that determines the denominator based on the formula and the number of iterations
{
	int denom;									//Created denominator variable
	denom = (2 * n) + 1;							//Formula to determine the denominator based on the iterations (n)
	return denom;									//Returns the denominator 
}

int numerator(int n)								//Numerator function that determines the numerator based on the formula and the number of iteration
{
	int numer;										//Created numerator variable
	numer = pow(-1, n);								//Formula to determine the numerator based on the iterations (n), I used the power function from the cmath lib
	return numer;									//Returns the numerator
}

void printSeries(int n, int d)						//Display function that prints out the series based on the iterations
{
	if (n < 0 && d < 0)								//Determines if either the numerator or denominator are negative to put the negative "-" sign infront
		cout << "-" << n << "/" << d << " ";		//Prints out the fraction with a negative sign infront
	else
		cout << n << "/" << d << " ";				//Or else it prints out the fraction without a sign
}