#ifndef A5_LIBRARY_HPP
#define A5_LIBRARY_HPP

#include <iostream>
#include <vector>
#include <string>
#include "a5_book.hpp"
using namespace std;

//PURPOSE: to store Book instances in a vector attribute to form a library of Book objects
class Library {
	vector<Book> library;
public: 
	//PURPOSE: empty/default constructor
	Library();

	//PURPOSE: constructor with vector of Book objects
	Library(vector<Book> updated_library);

	//PURPOSE: to insert a Book object into the vector attribute
	//INPUTS: direct string values for title, authors and the date of publication
	//OUTPUTS: true - if book was inserted, false - if book was not inserted
	bool insert_book(string title, string authors = "n/a", string date_of_publication = "n/a");

	//PURPOSE: to insert a Book object into the vector attribute
	//INPUTS: a Book instance
	//OUTPUTS: true - if book was inserted, false - if book was not inserted
	bool insert_book(Book new_book);

	//PURPOSE: to remove a Book object from the vector attribute
	//INPUTS: direct string values for title, authors and the date of publication
	//OUTPUTS: true - if book was removed, false - if book was not removed
	bool remove_book(string title, string authors = "n/a", string date_of_publication = "n/a");

	//PURPOSE: to remove a Book object from the vector attribute
	//INPUTS: a Book instance
	//OUTPUTS: true - if book was removed, false - if book was not removed
	bool remove_book(Book new_book);

	//PURPOSE: print out the contents of the vector attribute
	void print();
};
#endif