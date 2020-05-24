#include <iostream>
#include "Soldier.hpp"
using namespace std;


class Sniper :public Soldier {
	public:
	Sniper(int number): Soldier(number){
		setHealth_points(100);
		setDamage_points(50);
	}
 
	
};