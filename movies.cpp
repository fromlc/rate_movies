//------------------------------------------------------------------------------
// movies.cpp
//------------------------------------------------------------------------------

#include <iostream>
#include < string>

using namespace std;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// accumulate final rating
	double final_rating = 0;

	// input
	int i;
	string s;

	// track bad input
	bool bad_rating = false;
	bool bad_actor_input = false;
	bool bad_others_rating = false;
	bool bad_thumbed_up = false;
	bool bad_thumbed_down = false;

	cout << "Movie title? ";
	string title;
	cin >> title;

	cout << "#1 How do you rate this movie? (1-10) ";
	cin >> i;

	if (i >= 1 && i <= 10) {
		final_rating += i * 0.3;
	}
	else {
		// bad rating
		bad_rating = true;
	}

	cout << "#2 Do you like movies with this person? ";
	cin >> s;

	if (!s.compare("Yes")) {
		final_rating += 2;
	}
	else if (s.compare("No")) {
		bad_actor_input = true;
	}

	cout << "#3 How would others rate this movie? (1-10) ";
	cin >> i;

	if (i >= 1 && i <= 10) {
		final_rating += i * 0.3;
	}
	else {
		bad_others_rating = true;
	}

	cout << "#4 Have you thumbed up this movie already? ";
	cin >> s;

	if (!s.compare("Yes")) {
		final_rating += 2;
	}
	else if (s.compare("No"))	{
		bad_thumbed_up = true;
	}

	cout << "#5 Have you thumbed down this movie already? ";
	cin >> s;

	if (!s.compare("Yes")) {
		final_rating -= 2;
	}
	else if (s.compare("No")) {
		bad_thumbed_down = true;
	}


	// display the final rating
	cout << "Final rating: " << final_rating << '\n';

	// here are all the boolean flags we've used so far
	// we need to check each boolean flag

	//bool bad_rating = false;
	//bool bad_person_input = false;
	//bool bad_others_rating = false;
	//bool bad_thumbed_up = false;

	if (bad_rating)
		cout << "Bad rating\n";
	if (bad_actor_input)
		cout << "Bad other people's rating\n";
	if (bad_others_rating)
		cout << "Bad other people's rating\n";
	if (bad_thumbed_up)
		cout << "Bad thumbed up rating\n";
	if (bad_thumbed_down)
		cout << "Bad thumbed down rating\n";

	// #TODO check for the other two errors

}

