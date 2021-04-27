// a2_q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// step1. allow user to enter an integer that is greater than 1. Include error checking of input
// step2. compute and output all the prime numbers that are less than or equal to the input value
// step3. if the prime number is less than 10,000 and also palindromic then indicate that in the output
// step4. if prime number is less than 100,000 and the sum of digits is odd, then indicate that output
//*****************************************************************************
// Student Name: Chaitya Patel
//  Student Number:  20886642
//
//  SYDE 121 Assignment: 2
//  Filename: a2_q1
//
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
// Due Date: Sunday, October 11, 2020
//**************************************************************
/*- to test the program invalid numbers were tested to check error testing and valid numbers tested included
2,9999, 10000, 99999, 100000 since those are numbers where there are condition switches and randomn values between the two ranges
were also tested such as 929, 4656, 77889
  - for a value as large as 100,000 the program takes about 53 to compute the numbers, which I think is inefficient in terms of how long 
  a user would wait for a program to run
  - 50,000 on the other hand takes about 20 seconds to compute which I think is the longest that a user would wait. Therefore I would 
  that up to 50,000 is an efficient range for this program to compute.*/


#include <iostream>
using namespace std;

void prime_numbers();
// PURPOSE: to find all of the prime numbers up to the value that the user has entered and make use of other functions to determine
//          if palindromic and if sum of digits is odd

void collect_input(int& max_value); 
// PURPOSE: to collect user input of a max value to calculate primes up to 
//      INPUTS: max_value - integer that is initialized and set to zero in prime_numbers function to make available and pass by reference
//      OUTPUTS: nothing; value entered by user is returned by reference

void check_input(int& max_value); 
// PURPOSE: to error check that a positive integer more than 1 has been entered by the user.
//      INPUTS: max_value - integer entered by user and passed by reference in order to check
//      OUTPUTS: nothing - in the case that the entered value is invalid, the user is prompted 
//               again to enter a valid number and this is passed by reference

void get_reverse(int max_value);
// PURPOSE: to reverse the prime numbers ound in prime_numbers function and check if they are palindromic
//      INPUTS: max_value - prime integer within the range of the value entered by the user
//                        - passed by value because reference is not to be manipulated
//      OUTPUTS: a string that indicates that the prime number passed through is a palindrome

void check_sum_odd(int max_value);
// PURPOSE: to sum the digits of the prime passed in the argument and check and output if the sum of its digits is odd
//      INPUTS: max_value - prime integer within the range of the value entered by the user
//                        - passed by value because reference is not to be manipulated
//      OUTPUTS: a string that indicates whether the sum of the digits of the number passed through is odd 
//               sum - an integer that is the sum of the digits of the number passed in the case that the sum is odd

void prime_numbers() {
    // [SETUP] declare and initialize the variables
    int max_value = 0; // the largest value that the function will compute the prime number up to 
    int divisor = 1; // the number that the max_value will be divided by to check for factors
    int factor_found = 0; // number of factors found

    // [INPUT] step1. allow the user to enter a maximum value to compute primes up to 
    //         step2. check to make sure user has entered a valid positive integer more than 1
    collect_input(max_value); // FUNCTION PURPOSE: to collect user input of a max value to calculate primes up to

    // [PROCESSING] step3. check if numbers up to max_value have factors other than 1 and themselves
    // perform the computation once to account for the inital number entered
    do {
        // let the divior increment as long as it is less than the max_value
        while (divisor < max_value && divisor++) {
            // the divisor is more than 1 and less than the number itself meaning a remainder of 0 would indicate a factor other than 1 and itself
            if (max_value % divisor == 0 && divisor < max_value) {
                factor_found += 1;
            }
        }
        // if no factors between 1 and the number itself are found then factor count is 0 and thus the number is prime
        if (factor_found == 0) {
            // palindrome check to be done for primes less than 10,000 and odd sum check for primes less than 100,000
            if (max_value < 10000) {
                // [OUTPUT] step4. output the prime value
                cout << max_value;
                // step5. check if number is a palindrome and indicate in output
                get_reverse(max_value);
                // step6. check is the sum of the digits is odd and indicate in output 
                check_sum_odd(max_value);
            }
            // odd sum check to be done for primes less than 100,000 - this accounts for those at or above 10,000
            if (max_value < 100000 && max_value >= 10000) {
                // step7.output the prime value
                cout << max_value;
                // step8. check is the sum of the digits is odd and indicate in output
                check_sum_odd(max_value);
            }
        }
        // reset counts to restart the process for the next number in the range
        if (divisor >= max_value) {
            divisor = 1;
            factor_found = 0;
        }


    } while (max_value > 2 && max_value--); // repeat the computation decrementing the input value until 2 since no positive primes less than 1 exist
}

void collect_input(int& max_value) {
    // [INPUT] step1. collect user input for the program to compute prime values+ up to
    cout << "Enter a positive integer more than 1: ";
    cin >> max_value; // compute up to this maximum value
    cout << "You entered: " << max_value << endl; // echo user input
    
    // step2. error checking for the value inputted
    check_input(max_value);
}

void check_input(int& max_value) {
    //step1. check if value entered by user is a positive number such that it is greater than 1
    //step2. if value is invalid (not a positive integer more than 1) then prompt user to reenter a valid input until a valid value is entered
    while (max_value <= 1) {
        cout << "Please enter a valid positive integer more than 1: ";
        cin >> max_value;
        cout << "You entered: " << max_value << endl; // echo user input
    }
    cout << "The prime numbers from largest to smallest are as follows: " << endl;
}

void get_reverse(int max_value) {
    // [SETUP] declare and initialize variables
    int prime_number = max_value; // so the argument value can be manipulated in the function without manipulating the reference
    int reversed = 0; // reversed version of the arguement
    int store; // to store a number in memory during calculation

    // [PROCESSING] step.1 as long as the prime number has not become 0 in the process of removing place values, the process will repeat
    // != used in case function is used to check a negative prime number in the future
    // methodology referenced : https://medium.com/@ManBearPigCode/how-to-reverse-a-number-mathematically-97c556626ec6
    while (prime_number != 0) {
        store = prime_number % 10; // 1) isolates the ones place
        reversed = reversed * 10;  // 2) makes the ones places into a leftmost place in the reversed number
        reversed += store;         // 3) adds the ones place from the prime to the ones place of the reversed number
        prime_number /= 10;        // 4) removes the ones place altogether, making the leftmost place a place to the right
    }
   
    // [OUTPUT] step2. checks if the reversed number is the same as the value passed by value and if so, outputs a string that indicates it's a palindrome
    if (max_value == reversed) {
        cout << " [Palindromic Prime]";
    }
}

void check_sum_odd(int max_value) {
    // [SETUP] declare and initialize variables
    int digits = max_value; // digits of the value passed in
    int sum = 0; // sum of the digits of the value passed in

    // [PROCESSING] step 1. while the digits are not equal to zero as their base 10 place values are being removed
    // != used if function wants to be used for negative integers as well
    // based on the methodology for the palindrome check, the same logic of isolating place values was used:
    // https://medium.com/@ManBearPigCode/how-to-reverse-a-number-mathematically-97c556626ec6
    while (digits != 0) {
        sum = sum + digits % 10; // 1) make the sum equal to the existing sum plus the value in the ones place of the number
        digits /= 10;            // 2) reduce the number by taking out a base 10 place
    }
    
    // [OUTPUT] step2. if the sum can't be divided without a remainder by 2 then it is odd and a string indicating that will be outputted
    if (sum % 2 != 0) {
        cout << " [Sum = " << sum << " = Odd]" << endl;
    }
    else {
        cout << endl;
    }
}

int main()
{
    
    prime_numbers(); // FUNCTION: to output all prime numbers up to a value inputted by user and 
                     //           indicate if the prime is a palindrome and if the sum of the digits is off
}