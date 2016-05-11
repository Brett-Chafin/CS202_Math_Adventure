//Brett Chafins Assignment 1
//This .h includes the map, player, inventory, and score classes
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>


const int SIZE = 8;//used to manage size of graph

//handles all questions and answers using an graph data structure
class map
{
   public:
	map();
        ~map();
        int insert_vertex(char*);
        int insert_edge(char*, char*, char*);
        int find_location(char*);
        int load_graph_data(map &);
   protected:
        struct vertex * adjacency_list;
        int list_size;	
};

//Manages inventory my using a doubly linked list
class inventory
{
   public:
	inventory();
	~inventory();
	bool check_for(char*);
	int display_inventory();
	int delete_item(char*);
	int add_item(char*);
   protected:
	struct item_node * head; 
};

//Manages players score
class points
{
   public:
	points();
	~points();
	int add_points(int);
	int subtract_points(int);
	int display_points();
   protected:
	int score; 
};

//manages player name and allows them to answer and move character
class player: public map
{
   public:
	player();
	~player();
	int answer(char*&);
	int input_name(char*);
	int play_game();
   protected:
	char * name;
	inventory backpack;
	points score;
	
};

//vertex of the graph structure in class map
struct vertex
{
	char * question;
	struct edge * head;
	bool visited; 
};

//edges of the graph data structure in the map class
struct edge
{
	char * answer;
	vertex * adjacent;
	edge * next_edge; 
};

//node for the LLL of items in inventory
struct item_node
{
	char * item_name;
	item_node * next;
};
