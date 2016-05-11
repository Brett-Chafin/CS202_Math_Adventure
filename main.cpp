//Brett Chafin's Assignment 1
//This file contains the main function

#include "classes.h"
using namespace std;


int main()
{
	//map board;
	//board.load_graph_data(board);

	//introduction 
	cout << "\n\n\n\n\n\nWelcome to your math adventure game!\n"
	     << "Your first task, what class do you want your character to be?\n"
             << "Each class will give you a different set of bonuses\n"
	     << "Press (W) for Warrior\n"
             << "Press (M) for Mage\n"
	     << "Press (R) for Rogue\n\n\n";
	
	char response; 
	cin >> response; cin.ignore();
	if(toupper(response) == 'W')
	{
		warrior player1;
		player1.load_graph_data(player1);
		player1.play_game();	
	}
	else if(toupper(response) == 'M')
	{
		mage player1;
		player1.load_graph_data(player1);
		player1.play_game();
	}
	else if(toupper(response) == 'R') 
	{
		rogue player1;
		player1.load_graph_data(player1);
		player1.play_game();
	}
	else
	{
		cout << "Wrong response! Try again later\n";
		return 0;
	}
	     
}
