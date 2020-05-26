#pragma once
#include <iostream>

using namespace std;

class Soldier{
private:
int num_team;
int health_points;
int damage_points;
int max_health_points;
string type;

	
public:
Soldier(int number){
	num_team=number;
	
}
 int getNum_team(){return num_team;}
 int getHealth_points(){return health_points;}
 int getDamage_points(){return damage_points;}
 int getMax_health_points(){return max_health_points;}
 string getType(){return type;}
 void setHealth_points(int num){ this->health_points=num;}
 void setDamage_points(int num){ this->damage_points=num;}
 void setMax_health_points(int num){this->max_health_points=num;}
 void setType(string type){this->type=type;}
 virtual void attack (vector<vector<Soldier*>> &b, int first, int second) = 0;
 
 
	 
	
	
	
};