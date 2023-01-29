//------------------------------------------------------------------------------
// movies.cpp
//------------------------------------------------------------------------------

#include <iostream>
#include < string>

using namespace std;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
	double final_rating = 0;

	// track bad input
	bool bad_rating = false;
	bool bad_person_input = false;
	bool bad_others_rating = false;
	bool bad_thumbed_up = false;

	cout << "Movie title? ";
	string title;
	cin >> title;

	cout << "#1 How would you rate this movie? (1-10) ";
	int rating;
	cin >> rating;

	if (rating >= 1 && rating <= 10)
	{
		final_rating = final_rating + rating * 0.3;
	}
	else
	{
		// bad rating
		bad_rating = true;
	}

	cout << "#2 Do you like movies with this person? ";
	string like_person;
	cin >> like_person;

	if (like_person == "Yes" || like_person == "No")
	{
		if (like_person == "Yes")
		{
			final_rating = final_rating + 2;
		}
	}
	else
	{
		// track bad person input
		bad_person_input = true;
	}

	cout << "#3 How would others rate this movie? (1-10) ";
	int others_rating;
	cin >> others_rating;

	if (others_rating >= 1 && others_rating <= 10)
	{
		final_rating = final_rating + (others_rating * 0.3);
	}
	else
	{
		// bad rating by other people
		bad_others_rating = true;
	}

	cout << "#4 Have you thumbed up this movie already? ";
	string already_thumbed_up;
	cin >> already_thumbed_up;

	if (already_thumbed_up == "Yes" || already_thumbed_up == "No")
	{
		if (already_thumbed_up == "Yes")
		{
			final_rating = final_rating + 2;
		}
	}
	else
	{
		// track bad person input
		bad_thumbed_up = true;
	}

	// more efficient if statement
	//if (already_thumbed_up == "Yes")
	//{
	//	final_rating = final_rating + 2;
	//}
	//else if (already_thumbed_up != "No")
	//{
	//	// track bad person input
	//	bad_thumbed_up = true;
	//}

	// #TODO we still need to check for already thumbed down


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
	if (bad_person_input)
		cout << "Bad other people's rating\n";

	// #TODO check for the other two errors

}

