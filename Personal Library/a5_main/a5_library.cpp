#include "a5_library.hpp"
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Library::Library() {}

Library::Library(vector<Book> updated_library) :
	library(updated_library) {}

bool Library::insert_book(string title, string authors, string date_of_publication) {
	//step1. check to see if book values already exist in the library
	for (unsigned int index = 0; index < library.size(); ++index) {
		if (title == library[index].get_title() &&
			authors == library[index].get_authors() &&
			date_of_publication == library[index].get_dop()) {

			//indicate not inserted
			return false;
		}
	}

	//step2. insert the book values into the vector attribute as an object
	Book new_book(title, authors, date_of_publication);
	library.push_back(new_book);
	return true;
}

bool Library::insert_book(Book new_book) {
	//step1. check to see if book instance already exist in the library
	for (unsigned int index = 0; index < library.size(); ++index) {
		if (new_book.get_title() == library[index].get_title() &&
			new_book.get_authors() == library[index].get_authors() &&
			new_book.get_dop() == library[index].get_dop()) {

			//indicate not inserted
			return false;
		}
	}
	//step2. insert the book instance into the vector attribute as an object
	library.push_back(new_book);
	return true;
}

bool Library::remove_book(string title, string authors, string date_of_publication) {
	//step1. check to see if book values already exist in the library
	for (unsigned int index = 0; index < library.size(); ++index) {
		if (title == library[index].get_title() &&
			authors == library[index].get_authors() &&
			date_of_publication == library[index].get_dop()) {

			//step2. remove the book object from the vector attribute
			library.erase(library.begin() + index);
			return true;
		}
	}

	//indicate not removed
	return false;
}
bool Library::remove_book(Book old_book) {
	//step1. check to see if book instance already exist in the library
	for (unsigned int index = 0; index < library.size(); ++index) {
		if (old_book.get_title() == library[index].get_title() &&
			old_book.get_authors() == library[index].get_authors() &&
			old_book.get_dop() == library[index].get_dop()) {

			//step2. remove the book object from the vector attribute
			library.erase(library.begin() + index);
			return true;
		}
	}

	//indicate not removed
	return false;
}

void Library::print() {
	//iterate through the vector attribute and print out the contents
	for (unsigned int index = 0; index < library.size(); ++index) {
		cout << "index[" << index << "]: ";
		library[index].print();
	}
}