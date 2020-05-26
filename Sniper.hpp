#include <iostream>
#include "Soldier.hpp"
using namespace std;


class Sniper :public Soldier {
	public:
	Sniper(int number): Soldier(number){
		setHealth_points(100);
		setDamage_points(50);
		setMax_health_points(100);
		setType("sniper");
	}
	void attack(vector<vector<Soldier*>> &b, int first, int second){
		int index1=-1; 
		int index2=-1;
		int strong;
		for(int i= 0; i< b.size(); ++i){
			for(int j=0; j< b[i].size(); ++j) {
			Soldier* s = b[i][j];
				if (s != nullptr && s->getNum_team() !=getNum_team()){
					if(index1 == -1|| strong < s->getHealth_points()){
						strong=s->getHealth_points();
						index1=i;
						index2=j;
					}
				}
			
			}
		}
		Soldier* s=b[index1][index2];
		s->setHealth_points(s->getHealth_points()-b[first][second]->getDamage_points());
		if(s->getHealth_points() <= 0){
			b[index1][index2]=nullptr;
		}
		
		
	
	}
	
 
	
};