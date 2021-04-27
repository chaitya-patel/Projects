// a1_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A function will be created to compute the summation of a specified range of numbers.
// Variables need to be initialized for each variable that is in the sum formula, including a, n and d.
// Variable b, for biggest number will need to be added so the program can use it to find the range where the function is finding the sum.
/*n has to be set up to take the difference between the a and b values in order to find their range, but 1 will need to be added since the 
difference between a and b will not include a, just b.*/
// A variable named sum will need to be introduced to store the value of the summation formula and will be equated to that.
// The summation function will be called in the main function to display the sum of the range of numbers entered.

/*To test the program logic, I tested the range from 1 to 10 and 5 to 20, basically smaller ranges that I could manually compute.*/
/*The valid range of values for which this program will work correctly is when the sum is a maximum of 10^38 since that is the max value
a float can store*/

/*Answers to step 1 :
	1 to 500 = 125250 is the computed sum of the number range entered!
	5 to 2020 = 2.0412e+06 is the computed sum of the number range entered! (2'041'200)
	42 to 32000 = 5.11999e+08 is the computed sum of the number range entered!(411'999'000) */


#include <iostream>
using namespace std;

void summation() {
// function for summation that completes the compution of the sum of numbers within the entered number range
	
	// declare and initialize variables that are a part of the sum formula
	int first_integer; // start of the range
	int last_integer; // end of the range 
	int term_difference = 1; // difference between the numbers that should be summed

	// prompt user to input the start of the range
	cout << "Enter the first integer of the range: ";
	cin >> first_integer;

	// prompt user to input the end of the rage
	cout << "Enter the last integer of the range: ";
	cin >> last_integer;

	// initialize and set number_of_integers equal to the difference between the highest and lowest numbers, plus 1 
	//to include the initial number in the range
	int number_of_integers = (last_integer - first_integer) + 1;

	// initialize a float named sum and make it store the results of the sum formula when the variables within are defined
	// float was chosen instead of float to accomodate for larger sums
	float sum = (number_of_integers / 2) * (2 * (first_integer) + (number_of_integers - 1) * term_difference);  // sum formula

	// output to console the sum of the numbers within the range that was defined
	cout << sum << " is the computed sum of the number range entered!";
}

int main() {
	// call the summation function to complete the compution of a sum of numbers within a number range
	summation();
}


