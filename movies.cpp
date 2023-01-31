//------------------------------------------------------------------------------
// movies.cpp
//------------------------------------------------------------------------------
#include <iostream>
#include < string>

using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
double g_final_rating = 0;		// accumulates final rating value (1-10)
bool g_any_error = false;		// set true on any error

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool addIntRating(double multiplier);
bool addStrRating(int points);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// input
	int i;
	string s;

	cout << "\nIt's movie rating time!\n\n";

	cout << "Movie title? ";
	string title;
	cin >> title;

	cout << "1) How do you rate this movie (1-10)? ";
	bool bad_rating = addIntRating(0.3);

	cout << "2) Do you like other movies with the same actors (y/n)? ";
	bool bad_actor_rating = addStrRating(2);

	cout << "3) How would others rate this movie (1-10)? ";
	bool bad_others_rating = addIntRating(0.3);

	cout << "4) Have you thumbed up this movie already (y/n)? ";
	bool bad_thumbed_up = addStrRating(2);

	cout << "5) Have you thumbed down this movie already (y/n)? ";
	bool bad_thumbed_down = addStrRating(-2);

	if (!g_any_error) {
		cout << "\nFinal rating: " << g_final_rating << '\n';
	}
	else {
		cout << "\nCan't calculate movie rating due to invalid input:\n";

		// report which input(s) was/were invalid
		if (bad_rating)
			cout << "\tInvalid rating\n";
		if (bad_actor_rating)
			cout << "\tInvalid actor rating\n";
		if (bad_others_rating)
			cout << "\tInvalid other people's rating\n";
		if (bad_thumbed_up)
			cout << "\tInvalid thumbed up rating\n";
		if (bad_thumbed_down)
			cout << "\tInvalid thumbed down rating\n";
	}
}

//------------------------------------------------------------------------------
// updates final rating using passed value
// returns false (no error) for valid integer input, true otherwise
//------------------------------------------------------------------------------
bool addIntRating(double multiplier) {
	int i;
	cin >> i;

	if (i >= 1 && i <= 10) {
		g_final_rating += i * multiplier;
		return false;
	}

	g_any_error = true;
	return true;
}

//------------------------------------------------------------------------------
// adds passed value to final rating when user inputs a form of yes
// returns false (no error) for valid yes/no input (Yes/No), true otherwise
//------------------------------------------------------------------------------
bool addStrRating(int points) {
	string s;
	cin >> s;

	// accept these forms of yes
	if (!s.compare("y") || !s.compare("Y") ||
		!s.compare("yes") || !s.compare("Yes")) {
		g_final_rating += points;
		return false;
	}

	// if user didn't type any form of no, it's an error
	if (!(!s.compare("n") || !s.compare("N") ||
		!s.compare("no") || !s.compare("No"))) {
		g_any_error = true;
		return true;
	}
}

