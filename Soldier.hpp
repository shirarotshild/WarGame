#pragma once
#include <iostream>

using namespace std;

class Soldier{
private:
int num_team;
int health_points;
int damage_points;

	
public:
Soldier(int number){
	num_team=number;
	
}
 int getNum_team(){return num_team;}
 int getHealth_points(){return health_points;}
 int getDamage_points(){return damage_points;}
 void setHealth_points(int num){ this->health_points=num;}
 void setDamage_points(int num){ this->damage_points=num;}
 virtual void attack (vector<vector<Soldier*>> &b, int first, int second, int player_number) = 0;
 
 
	 
	
	
	
};