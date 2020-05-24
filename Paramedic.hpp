#include <iostream>
#include "Soldier.hpp"
using namespace std;


class Paramedic :public Soldier {
	public:
	Paramedic(int number): Soldier(number){
		setHealth_points(100);
		setDamage_points(50);
	}
 
	
};