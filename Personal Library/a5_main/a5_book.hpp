#ifndef A5_BOOK_HPP
#define A5_BOOK_HPP

#include <iostream>

using namespace std;

//PURPOSE: to store books using their title, authors, and date of publication
class Book {
	string title, authors, date_of_publication;
public:
	//PURPOSE: empty/default constructor
	Book();

	//PURPOSE: Parametric constructor with all attributes specified
	Book(string new_title, string new_authors, string new_dop);

	//PURPOSE: Parametric constructor with only title and authors specified
	Book(string new_title, string new_authors);

	//PURPOSE: Parametric constructor with only title specified
	Book(string new_title);

	//PURPOSE: service functions - attribute getters
	string get_title();
	string get_authors();
	string get_dop();

	//PURPOSE: service functions - attribute setters
	//INPUTS: corresponding attribute
	void set_title(string new_title);
	void set_authors(string new_authors);
	void set_dop(string new_dop);

	//PURPOSE: service function - to print the details of an instance
	void print();

};
#endif
