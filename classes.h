//Brett Chafin's Assignment 1
//This .h includes the different player classes you can choose
#include "header.h"

//One of a choosable class with unique abilitys
class warrior: public player
{
   public:
	int special_ability();
	
};

//one of a choosable class with unique abilitys
class mage: public player
{
   public:
	int special_ability();

};

//one of a choosable class with unique abilitys
class rogue: public player
{
   public: 
	int special_ability();
};


