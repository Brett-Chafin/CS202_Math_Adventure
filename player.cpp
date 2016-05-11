//Brett Chafin's Assignment 1
//This .cpp file contains class player functions

#include "classes.h"
using namespace std;

//constructor
player::player():name(NULL)
{

}

//destructor
player::~player()
{
	delete name;
}

//Promps the player for input and returns answer
int player::answer(char* & answer)
{
	cout << "Your Answer is: \n";
	char response[20];
	cin.get(response, 20, '\n');
	cin.ignore();
	answer = new char[strlen(response) + 1];
	strcpy(answer, response);
}


//creates player name
int player::input_name(char* new_name)
{
	cout << "Please enter the name of the person playing this character: \n";
	
	char response[50];
	cin.get(response, 50, '\n'); cin.ignore();
	
	name = new char[strlen(response) +1];
	strcpy(name, response);
}

//Allows players to start game
int player::play_game()
{
	//sets pointer to the begining of the map
	vertex * current_vertex = &adjacency_list[0];

	cout << current_vertex->question <<endl; 
	
	while(1 < 2)
	{
		//has the player give thier answer
		char * player_answer;
		answer(player_answer);
		
		edge * current_edge = current_vertex->head;
	
		//if correct answer is given
		if(!strcmp(current_edge->answer, player_answer))
		{	
			cout << "\n\nCorrect!\n Next question\n";
			score.add_points(10);
			score.display_points();
			current_vertex = current_edge->adjacent; 
			cout << current_vertex->question <<endl;
		}
		else
		{
			current_edge = current_edge->next_edge;
			//if there is another edge to compare answer
			if(current_edge != NULL)
			{
				//if correct answer is found
				if(!strcmp(current_edge->answer, player_answer))
				{
					cout << "\n\nCorrect!\n Next question\n";
				
					//gives player 10 points
					score.add_points(10);
					score.display_points();
				
					//moves to next vertex
					current_vertex = current_edge->adjacent; 
					cout << current_vertex->question <<endl;
				}
				//finds edge if wrong answer is given
				else if(!strcmp(current_edge->answer, "wrong"))
				{
					//deducts player 10 points
					score.subtract_points(10);
					score.display_points();

					//moves to next vertex 
					current_vertex = current_edge->adjacent;
					cout << current_vertex->question <<endl;
				}
				//moves to next edge
				else
				{
					current_edge = current_edge->next_edge;
				}
			}
			//if no path for wrong answer vertex is given
			else
			{
				cout <<"Wrong answer, try again!\n";
			}
		}
		
	}

			
}
