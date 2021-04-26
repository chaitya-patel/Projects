// a1_q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Assignment 1 : Question 1
// Weight types: 125 lb, 75 lb, 42 lb, 15 lb, and 1 lb
// Base Object Weight : 2048 lb
// First find the quotient of the object weight divided by the largest weight type. Take this quotient and store it.
// Then take the remainder of the object weight when divided by the weight type and store that as the object_weight, since that is still unbalanced

/*Values used to test the program include 2048, the values of each weight separately, 
and numbers like 200, 117, 57, 16 since those would require different pairs of the weights.*/
/*The range of values for which this program will work correctly is : 0 to 2,147,483,647 for the object weight 
(since that is the largest number an int can store) */
/*The output of the code is as follows for the base case:
Enter the weight of the object : 2048
The number of weights of each type needed are as follows :
    16 of the 125 lb weights are needed.
    0 of the 75 lb weights are needed.
    1 of the 42 lb weights are needed.
    0 of the 15 lb weights are needed.
    6 of the 1 lb weights are needed. */

#include <iostream>
using namespace std;

void maximize_largest_weights() {
    // function to output how many of each weight type are needed to balance the inputted object weight by maximizing the usage of the heaviest weight type

    // decalare and initialize variable for the weight of the object
    int object_weight; // weight of the object to be balanced

    // declare and initialize variables to store the number of each weight needed
    // each weight type weighs the amount of the number used in the variable
    int weight_125, weight_75, weight_42, weight_15, weight_1;

    // ask for user input of the object weight
    cout << "Enter the weight of the object: ";
    cin >> object_weight;

    cout << "The number of weights of each type needed are as follows:\n";

    // compute the number of weights that are needed for each weight type
    // computing the number of 125 lb weights needed
    if (object_weight >= 125) { // condition to check if the object weight is above the weight type that is being worked with
        weight_125 = object_weight / 125; // calculating the max number of weights of the weight type that can help balance the object
        object_weight = object_weight % 125; // computing and storing the weight that remains unbalanced
    }
    else {
        weight_125 = 0; // in the case that the weight of the object is less than 125
    }
    cout << weight_125 << " of the 125 lb weights are needed."; // outputting the max number of weights of this type that are needed.

    // computing the number of 75 lb weights needed
    if (object_weight >= 75) { 
        weight_75 = object_weight / 75;
        object_weight = object_weight % 75;
    }
    else {
        weight_75 = 0;
    }
    cout << "\n" << weight_75 << " of the 75 lb weights are needed.";

    // computing the number of 42 lb weights needed
    if (object_weight >= 42) {
        weight_42 = object_weight / 42;
        object_weight = object_weight % 42;
    }
    else {
        weight_42 = 0;
    }
    cout << "\n" << weight_42 << " of the 42 lb weights are needed.";

    // computing the number of 15 lb weights needed
    if (object_weight >= 15) {
        weight_15 = object_weight / 15;
        object_weight = object_weight % 15;
    }
    else {
        weight_15 = 0;
    }
    cout << "\n" << weight_15 << " of the 15 lb weights are needed.";

    // computing the number of 1 lb weights needed
    if (object_weight >= 1) {
        weight_1 = object_weight / 1;
        object_weight = object_weight % 1;
    }
    else {
        weight_1 = 0;
    }
    cout << "\n" << weight_1 << " of the 1 lb weights are needed.";
}


int main() {
    // function to output how many of each weight type are needed to balance the inputted object weight by maximizing the usage of the heaviest weight type
    maximize_largest_weights();
}