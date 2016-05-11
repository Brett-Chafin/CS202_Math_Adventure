//Brett Chafin's Assignment 1
//This file contains all functions of class map

#include "classes.h"
using namespace std;

//constructor
map::map()
{
        list_size = SIZE;
        adjacency_list = new vertex[list_size];
        for(int i = 0; i < SIZE; ++i)
        {
                adjacency_list[i].question = NULL;
                adjacency_list[i].head = NULL;
                adjacency_list[i].visited = false;
        }
   //Allocate the adjacency list and set each
   //head pointer to NULL
}



//destructor
map::~map()
{
        for(int i = 0; i < list_size; ++i)
        {
                vertex * current = &adjacency_list[i];
                if(current != NULL)
                {
                        //If vertex has edges to delete
                        if(current->head)
                        {
                                while(current->head != NULL)
                                {
                                        edge * temp = current->head->next_edge;
                                        delete current->head;
                                        current->head = temp;
                                }
                        }
                        else
                        {
                                delete current->question;
                        }
                }
                else
                {
                 //do nothing
                }
        }
}

//Allows players to start game
/*int map::play_game()
{
	//sets pointer to the begining of the map
	vertex * current_vertex = &adjacency_list[0];

	cout << current_vertex->question <<endl; 
			
} */

//loads questions from external data file
int map::insert_vertex(char * add_question)
{
        int i = 0;
        //points to first element in list
        vertex * current = &adjacency_list[i];
        while(current->question != NULL)//finds first open element
        {
                ++i;
                if(i > list_size)
                        return 0;

                current = &adjacency_list[i];
        }

        //copies question from input
        adjacency_list[i].question = new char[strlen(add_question) + 1];
        strcpy(adjacency_list[i].question, add_question);
}



//connect up verticys with edges
int map::insert_edge(char * current_vertex, char * to_attach, char * answer)
{
        //copies answer to correct edge
        int current = find_location(current_vertex);
        int attach = find_location(to_attach);

        if(!adjacency_list[current].head)//if head is NULL
	{
		adjacency_list[current].head = new edge;
        	adjacency_list[current].head->adjacent = &adjacency_list[attach];
		adjacency_list[current].head->next_edge = NULL;//set next to NULL
		adjacency_list[current].head->answer = new char[strlen(answer +1)];
		strcpy(adjacency_list[current].head->answer, answer);
	}
	else
	{
		//points at head edge in edge chain
		edge * current_edge = adjacency_list[current].head;
		while(current_edge->next_edge)//while next is not NULL
		{
			current_edge = current_edge->next_edge;//points to next edge 	
		}
		
		current_edge->next_edge = new edge;
		current_edge = current_edge->next_edge;
		current_edge->adjacent = &adjacency_list[attach];
		current_edge->next_edge = NULL;//set next to NULL;
		current_edge->answer = new char[strlen(answer +1)];
		strcpy(current_edge->answer, answer);
	}
}



//finds index of the requested vertex to find
int map::find_location(char* to_find)
{
        int i = 0;
        vertex * current = &adjacency_list[i];
        while(i < SIZE)
	{
		if(adjacency_list[i].question && !strcmp(adjacency_list[i].question,to_find))
        	{
			return i;//returns the location of vertex
        	}
		else
		{	
			++i;
			if(i > SIZE)
				return 10;
        		current = &adjacency_list[i];
        	}
	}
}



//takes data from external file and sends it to functions
int map::load_graph_data(map & quiz)
{
        //opens and loads questions first
        ifstream inData;
        inData.open("question_file.txt");
        if(inData.fail())
        {
                cout << "Error Opening File\n";
                return 0;
        }
        for(int i = 0; i < SIZE; ++i)
        {
                //local arrays to store data
                char question[500];

                inData.get(question, 500, '\n');
                inData.ignore();

                quiz.insert_vertex(question);
        }
        inData.close();

        //now opens and loads answers
        inData.open("answer_file.txt");
        if(inData.fail())
        {
                cout << "Error Opening File\n";
                return 0;
        }
	int i = 0; 
        while(i < SIZE)
        {
		char answer[20];
		int vertex1;//vertex to connect
		int vertex2;//connecting vertex

                inData.get(answer, 20, '\t');
		inData >> vertex1;
		inData >> vertex2; 
                inData.ignore();

                quiz.insert_edge(adjacency_list[vertex1].question, adjacency_list[vertex2].question, answer);
                ++i;
        }
        inData.close();
}


