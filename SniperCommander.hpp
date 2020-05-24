#include <iostream>
#include "Soldier.hpp"
using namespace std;


class SniperCommander :public Soldier {
	public:
	SniperCommander(int number): Soldier(number){
		setHealth_points(120);
		setDamage_points(100);
	}
 
	
};