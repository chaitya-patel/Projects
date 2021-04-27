#include <iostream>

using namespace std;

int birth_month();
// PURPOSE: to retrieve information about the user's month of birth
// INPUTS: none
// OUTPUTS: birth_month - integer that represents the user's birth month

int birth_date(int birth_month);
// PURPOSE: to retrieve information about the user's date (day) of birth
// INPUTS: birth_month - the birth month in order to verify that the user is inputting a valid date based on the month they inputted
// OUTPUTS: birth_date - the day the user was born

void tropical_zodiac_sign(int birth_month, int birth_date);
// PURPOSE: to tell the user their zodiac sign based on tropical astrology
// INPUTS: birth_month - month of birth, birth_date - day/date of birth
// OUTPUTS: none

void sidereal_zodiac_sign(int birth_month, int birth_date);
// PURPOSE: to tell the user their zodiac sign based on vedic/sidereal astrology
// INPUTS: birth_month - month of birth, birth_date - day/date of birth
// OUTPUTS: none

int birth_month() {
	// [SETUP] step0. declare and initialize variables
	int birth_month;

	// [PROCESSING] step1. ask the user their month of birth
	cout << "What month were you born in (Enter from 1 - 12)?";
	cin >> birth_month;

	// [INPUT VALIDATION] step2. making sure the user entered a valid month of birth
	while (birth_month < 1) {
		cout << "What month were you born in (Please enter from 1 - 12)? ";
		cin >> birth_month;
	}
	while (birth_month > 12) {
		cout << "What month were you born in (PLease enter from 1 - 12)? ";
		cin >> birth_month;
	}

	return birth_month;
}

int birth_date(int birth_month) {
	// [SETUP] step0. declare and initialize variables
	int birth_date;

	// [PROCESSING] step1. ask the user their date of birth
	cout << "What day were you born (Enter as DD)? ";
	cin >> birth_date;

	// [INPUT VALIDATION] step2. making sure the user entered a valid month of birth based on the month they entered
	while (birth_date < 1) {
		cout << "What day were you born (please enter a valid day based on the month): ";
		cin >> birth_date;
	}

	switch (birth_month) {
	case 1:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 2:
		while (birth_date > 29) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 3:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 4:
		while (birth_date > 30) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 5:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 6:
		while (birth_date > 30) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 7:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 8:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 9:
		while (birth_date > 30) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 10:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 11:
		while (birth_date > 30) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}
	case 12:
		while (birth_date > 31) {
			cout << "What day were you born (please enter a valid day based on the month): ";
			cin >> birth_date;
		}

	}

	return birth_date;
}

void tropical_zodiac_sign(int birth_month, int birth_date) {
	
	cout << "Your tropical zodiac sign is: ";

	//[PROCESSING] matching month and date of birth of the user to the correct sign
	switch (birth_month) {
	case 1:
		if (birth_date < 20) {
			cout << "Capricorn!";
		}
		else {
			cout << "Aquarius!";
		}
		break;
	case 2:
		if (birth_date < 19) {
			cout << "Aquarius!";
		}
		else {
			cout << "Pisces!";
		}
		break;
	case 3:
		if (birth_date < 21) {
			cout << "Pisces!";
		}
		else {
			cout << "Aries!";
		}
		break;
	case 4:
		if (birth_date < 20) {
			cout << "Aries!";
		}
		else {
			cout << "Taurus!";
		}
		break;
	case 5:
		if (birth_date < 21) {
			cout << "Taurus!";
		}
		else {
			cout << "Gemini!";
		}
		break;
	case 6:
		if (birth_date < 21) {
			cout << "Gemini!";
		}
		else {
			cout << "Cancer!";
		}
		break;
	case 7:
		if (birth_date < 23) {
			cout << "Cancer!";
		}
		else {
			cout << "Leo!";
		}
		break;
	case 8:
		if (birth_date < 23) {
			cout << "Leo!";
		}
		else {
			cout << "Virgo!";
		}
		break;
	case 9:
		if (birth_date < 23) {
			cout << "Virgo!";
		}
		else {
			cout << "Libra!";
		}
		break;
	case 10:
		if (birth_date < 23) {
			cout << "Libra!";
		}
		else {
			cout << "Scorpio!";
		}
		break;
	case 11:
		if (birth_date < 22) {
			cout << "Scorpio!";
		}
		else {
			cout << "Sagittarius!";
		}
		break;
	case 12:
		if (birth_date < 22) {
			cout << "Sagittarius!";
		}
		else {
			cout << "Aquarius!";
		}
		break;
	}
}

void sidereal_zodiac_sign(int birth_month, int birth_date) {
	
	cout << endl << "Your sidereal zodiac sign is: ";

	//[PROCESSING] matching month and date of birth of the user to the correct sign
	switch (birth_month) {
	case 1:
		if (birth_date < 20) {
			cout << "Sagittarius!";
		}
		else {
			cout << "Capricorn!";
		}
		break;
	case 2:
		if (birth_date < 14) {
			cout << "Capricorn!";
		}
		else {
			cout << "Aquarius!";
		}
		break;
	case 3:
		if (birth_date < 10) {
			cout << "Aquarius!";
		}
		else {
			cout << "Pisces!";
		}
		break;
	case 4:
		if (birth_date < 21) {
			cout << "Pisces!";
		}
		else {
			cout << "Aries!";
		}
		break;
	case 5:
		if (birth_date < 13) {
			cout << "Aries!";
		}
		else {
			cout << "Taurus!";
		}
		break;
	case 6:
		if (birth_date < 20) {
			cout << "Taurus!";
		}
		else {
			cout << "Gemini!";
		}
		break;
	case 7:
		if (birth_date < 17) {
			cout << "Gemini!";
		}
		else {
			cout << "Cancer!";
		}
		break;
	case 8:
		if (birth_date < 7) {
			cout << "Cancer!";
		}
		else {
			cout << "Leo!";
		}
		break;
	case 9:
		if (birth_date < 15) {
			cout << "Leo!";
		}
		else {
			cout << "Virgo!";
		}
		break;
	case 10:
		cout << "Virgo!";
	case 11:
		if (birth_date < 4) {
			cout << "Virgo!";
		}
		else if (birth_date > 3 && birth_date < 23) {
			cout << "Libra!";
		}
		else {
			cout << "Scorpio!";
		}
		break;
	case 12:
		if (birth_date < 7) {
			cout << "Scorpio!";
		}
		else if (birth_date > 6 && birth_date < 19) {
			cout << "Ophiuchus!";
		}
		else {
			cout << "Sagittarius!";
		}
		break;
	}
}

int main() {

	int month = birth_month(); // get the month of birth
	int date = birth_date(month); // get the day/date of birth that corresonds with the entered month
	tropical_zodiac_sign(month, date); // tell the user the matching tropical zodiac sign based on dates given
	sidereal_zodiac_sign(month, date); // tell the user the matching sidereal zodiac sign based on dates given
}