#include <iostream>
#include "Soldier.hpp"
using namespace std;


class Paramedic :public Soldier {
	public:
	Paramedic(int number): Soldier(number){
		setHealth_points(100);
		setDamage_points(50);
		setMax_health_points(100);
	}
	void attack(vector<vector<Soldier*>> &b, int i, int j){
    if( i>0 && b[i-1][j] != nullptr){
        if(b[i-1][j]->getNum_team()== getNum_team()) 
            b[i-1][j]-> setHealth_points((b[i-1][j]->getMax_health_points()));
    }
    
    if( j<b[0].size()-1 && b[i][j+1] != nullptr){
        if(b[i][j+1]->getNum_team()== getNum_team()) 
            b[i][j+1]-> setHealth_points(b[i][j+1]->getMax_health_points());
    }
   if(j>0 && b[i][j-1] != nullptr){
       if(b[i][j-1]->getNum_team()== getNum_team()) 
            b[i][j-1]-> setHealth_points(b[i][j-1]->getMax_health_points());
    }
    if(i<b[0].size() && b[i+1][j] != nullptr){
        if(b[i+1][j]->getNum_team()== getNum_team()) 
            b[i+1][j]-> setHealth_points(b[i+1][j]->getMax_health_points());
    }
	
	
	}
 
	
};
