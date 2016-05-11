//Brett Chafin's Assignment 1
//This .cpp contains score function

#include "classes.h"
using namespace std;

//constructor
points::points():score(0)
{
	
}

//destructor
points::~points()
{
	score = 0;
}

//Add points to players score
int points::add_points(int to_add)
{
	score += to_add;
}

//Subtracts pionts from players score
int points::subtract_points(int to_sub)
{
	score -= to_sub;
}

//Displays players current score
int points::display_points()
{
	cout <<'\t' <<'\t' << "Your Current score is: " <<score <<endl; 
}

