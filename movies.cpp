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
double g_final_rating = 0;
bool g_any_error = false;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool accIntRating(double multiplier);
bool accStrRating(int points);

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
	bool bad_rating = accIntRating(0.3);

	cout << "2) Do you like movies with this person? ";
	bool bad_actor_rating = accStrRating(2);

	cout << "3) How would others rate this movie? (1-10) ";
	bool bad_others_rating = accIntRating(0.3);

	cout << "4) Have you thumbed up this movie already? ";
	bool bad_thumbed_up = accStrRating(2);

	cout << "5) Have you thumbed down this movie already? ";
	bool bad_thumbed_down = accStrRating(-2);

	if (!g_any_error) {
		cout << "\nFinal rating: " << g_final_rating << '\n';
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
// updates final rating using passed value
// returns false (no error) for valid integer input, true otherwise
//------------------------------------------------------------------------------
bool accIntRating(double multiplier) {
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
// updates final rating using passed value
// returns false (no error) for valid string input (Yes/No), true otherwise
//------------------------------------------------------------------------------
bool accStrRating(int points) {
	string s;
	cin >> s;

	if (!s.compare("Yes")) {
		g_final_rating += points;
		return false;
	}

	if (s.compare("No")) {
		g_any_error = true;
		return true;
	}
}

