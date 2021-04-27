//*****************************************************************************
// Student Names: Chaitya Patel and Mayurah Omkararuban
// Student Numbers: 20886642 (CP) and 20879369 (MO)
//
//  SYDE 121 Assignment 5
//  Filename: a5_main (other linked files: a5_book.hpp, a5_book.cpp, a5_library.hpp, a5_library.cpp)
//
// We hereby declare that this code, submitted for credit for the course SYDE121, is a product of our own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
// Due Date: Friday, November 20, 2020
//**************************************************************

/*Testing and Debugging: To test the code the library was modified in various ways to check if appropriate changes were implemented in the library and other situations were also
tested in which no changes were required like adding a book that already exists. Every single class method was also tested and checked, and different methods of insertion and removal based on 
parametric constructors were also made and checked.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "a5_book.hpp"
#include "a5_library.hpp"
#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

bool test_instance_insertion();
//PURPOSE: to test insertion of Book instances into Library vector attribute
//INPUTS: none
//OUTPUTS: none

bool test_value_insertion();
//PURPOSE: to test insertion of Books by value into Library vector attribute
//INPUTS: none
//OUTPUTS: none

bool test_instance_removal();
//PURPOSE: to test removal of Book instances from the Library vector attribute
//INPUTS: none
//OUTPUTS: none

bool test_value_removal();
//PURPOSE: to test removal of Books by value from the Library vector attribute
//INPUTS: none
//OUTPUTS: none

void test_empty();
//PURPOSE: to test empty constructors of the Book and Library class
//INPUTS: none
//OUTPUTS: none

void test_book_methods();
//PURPOSE: to the methods of the Book class
//INPUTS: none
//OUTPUTS: none

void test_library_scenario();
//PURPOSE: to test the parametric constructor variants of the Book class and the Library class
//INPUTS: none
//OUTPUTS: none

void execute_tests();
//PURPOSE: to check if certain tests have passed or failed, and to see the results/behavior of others
//INPUTS: none
//OUTPUTS: none

bool test_instance_insertion() {
	//[SETUP] create library vector 
	Library library;

	//create two books with the same attributes
	Book my_book1("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999");
	Book my_book2("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999");

	//[PROCESSING] tests to see that the first instance of the book is inserted, but a repetition is rejected
	ASSERT_TRUE(library.insert_book(my_book1) == true);
	ASSERT_TRUE(library.insert_book(my_book2) == false);
	return true;
}

bool test_value_insertion() {
	//[SETUP] create library vector 
	Library library;

	//[PROCESSING] attempts to add two instances of the same book, but tests to see that the first instance of the book is inserted, but a repetition is rejected
	ASSERT_TRUE(library.insert_book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999") == true);
	ASSERT_TRUE(library.insert_book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999") == false);
	return true;
}

bool test_instance_removal() {
	//[SETUP] create library vector 
	Library library;

	//inserts a book instance into the vector attribute
	Book my_book1("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999");
	library.insert_book(my_book1);

	//[PROCESSING] removes the book once, and then tries to remove it again, even though it doesn't exist
	ASSERT_TRUE(library.remove_book(my_book1) == true);
	ASSERT_TRUE(library.remove_book(my_book1) == false);
	return true;
}

bool test_value_removal() {
	//[SETUP] create library vector 
	Library library;

	//inserts a book into the vector attribute by value
	library.insert_book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999");

	//removes the book once, and then tries to remove it again, even though it doesn't exist
	ASSERT_TRUE(library.remove_book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999") == true);
	ASSERT_TRUE(library.remove_book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999") == false);
	return true;
}

void test_empty() {
	//[SETUP] creates an empty vector and book instance
	Library empty_library;
	Book no_book;

	//[PROCESSING] prints the default values of the empty constructors
	empty_library.print();
	empty_library.insert_book(no_book);
	empty_library.print();
}

void test_book_methods() {
	//[SETUP] create an empty book in order to set attributes
	Book book1;

	//[PROCESSING] tests the getter and setter methods of the Book class
	book1.set_title("Percy Jackson and the Lightning Thief");
	book1.get_title();
	book1.set_authors("Rick Riordan");
	book1.get_authors();
	book1.set_dop("2005");
	book1.get_dop();
}

void test_library_scenario() {
	//Possible scenario to test the different parametric constructors of the Library Class and the Book Class to see how the entries are stored
	cout << "Harry Potter Library:" << endl;

	//[SETUP] create a library
	Library HP_library;	

	//[PROCESSING] insert and remove books with attributes defined in such a way to use and test the different parametric constructors
	Book hp_book1("Harry Potter and the Sorceror's Stone", "JK Rowling");
	HP_library.insert_book(hp_book1);
	HP_library.remove_book("Harry Potter and the Sorceror's Stone", "JK Rowling");
	HP_library.insert_book("Harry Potter and the Philospher's Stone", "JK Rowling", "1997");
	Book hp_book2("Harry Potter and the Chamber of Secrets");
	HP_library.insert_book(hp_book2);
	Book hp_book3("Harry Potter and the Prisoner of Azkaban", "JK Rowling", "1999");
	HP_library.insert_book(hp_book3);
	HP_library.insert_book("Harry Potter and the Goblet of Fire", "JK Rowling", "2000");
	HP_library.insert_book("Harry Potter and the Order of the Phoenix", "JK Rowling");
	HP_library.insert_book("Harry Potter and the Half-Blood Prince");
	HP_library.insert_book("Harry Potter and the Deathly Hallows", "JK Rowling");

	//[OUTPUT] print out the created library to see the contents of it and make sure it is working/formatting correctly
	HP_library.print();
}

void execute_tests() {

	//[PROCESSING] implement the test functions
	if (test_instance_insertion() == true) {
		cout << "Insertion By Instance Test Passed." << endl;
	}
	else {
		cout << "Insertion By Instance Test Failed." << endl;
	}

	if (test_value_insertion() == true) {
		cout << "Insertion By Value Test Passed." << endl;
	}
	else {
		cout << "Insertion By Value Test Failed." << endl;
	}

	if (test_instance_removal() == true) {
		cout << "Removal By Insertion Test Passed." << endl;
	}
	else {
		cout << "Removal By Insertion Test Failed." << endl;
	}

	if (test_value_removal() == true) {
		cout << "Removal By Value Test Passed." << endl;
	}
	else {
		cout << "Removal By Value Test Failed." << endl;
	}

	test_empty(); //function to test default constructors
	test_book_methods(); // function to test Book class methods
	test_library_scenario(); // function to test parametric parameters of the Book and Library class

}

int main()
{
	execute_tests();
}