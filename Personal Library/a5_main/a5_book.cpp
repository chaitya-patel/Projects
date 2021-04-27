#include "a5_book.hpp"

Book::Book():
	title("n/a"),
	authors("n/a"),
	date_of_publication("n/a") {}

Book::Book(string new_title, string new_authors, string new_dop) :
	title(new_title),
	authors(new_authors),
	date_of_publication(new_dop) {}

Book::Book(string new_title, string new_authors) :
	title(new_title),
	authors(new_authors),
	date_of_publication("n/a") {}

Book::Book(string new_title) :
	title(new_title),
	authors("n/a"),
	date_of_publication("n/a") {}

string Book::get_title() {
	return title;
}

string Book::get_authors() {
	return authors;
}

string Book::get_dop() {
	return date_of_publication;
}

void Book::set_title(string new_title) {
	title = new_title;
}

void Book::set_authors(string new_authors) {
	authors = new_authors;
}

void Book::set_dop(string new_dop) {
	date_of_publication = new_dop;
}
void Book::print() {
	cout << title << " "
		<< authors << " "
		<< date_of_publication << endl;
}