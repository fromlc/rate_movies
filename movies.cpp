//------------------------------------------------------------------------------
// movies.cpp
//------------------------------------------------------------------------------

#include <iostream>
#include < string>

using namespace std;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
// accumulate final rating
double final_rating = 0;
bool any_error = false;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool getIntRating();
bool getStrRating();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// input
	int i;
	string s;

	cout << "It's movie rating time!\n\n";

	cout << "Movie title? ";
	string title;
	cin >> title;

	cout << "1) How do you rate this movie? (1-10) ";
	bool bad_rating = getIntRating();

	cout << "2) Do you like movies with this person? ";
	bool bad_actor_rating = getStrRating();

	cout << "3) How would others rate this movie? (1-10) ";
	bool bad_others_rating = getIntRating();

	cout << "4) Have you thumbed up this movie already? ";
	bool bad_thumbed_up = getStrRating();

	cout << "5) Have you thumbed down this movie already? ";
	bool bad_thumbed_down = getStrRating();

	if (!any_error) {
		cout << "Final rating: " << final_rating << '\n';
	}
	else {
		// report bad input
		if (bad_rating)
			cout << "Invalid rating\n";
		if (bad_actor_rating)
			cout << "Invalid actor rating\n";
		if (bad_others_rating)
			cout << "Invalid other people's rating\n";
		if (bad_thumbed_up)
			cout << "Invalid thumbed up rating\n";
		if (bad_thumbed_down)
			cout << "Invalid thumbed down rating\n";
	}
}

//------------------------------------------------------------------------------
// updates final rating
// returns true for valid integer input, false otherwise
//------------------------------------------------------------------------------
bool getIntRating() {
	int i;
	cin >> i;

	if (i >= 1 && i <= 10) {
		final_rating += i * 0.3;
		return false;
	}

	any_error = true;
	return true;
}

//------------------------------------------------------------------------------
// updates final rating
// returns true for valid string input (Yes/No), false otherwise
//------------------------------------------------------------------------------
bool getStrRating() {
	string s;
	cin >> s;

	if (!s.compare("Yes")) {
		final_rating += 2;
		return false;
	}

	if (s.compare("No")) {
		any_error = true;
		return true;
	}
}

