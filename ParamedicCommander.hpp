#include <iostream>
#include "Soldier.hpp"
using namespace std;


class ParamedicCommander :public Soldier{
	public:
	ParamedicCommander(int number): Soldier(number){
		setHealth_points(200);
		setDamage_points(100);
	}
 
	
};