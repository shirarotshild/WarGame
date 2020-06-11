#include <iostream>
#include "Soldier.hpp"
using namespace std;


class ParamedicCommander :public Soldier{
	public:
	ParamedicCommander(int number): Soldier(number){
		setHealth_points(200);
		setDamage_points(100);
	}
 
	void attack(vector<vector<Soldier*>> &b, int i, int j){
    if( i>0 && b[i-1][j] != nullptr){
        if(b[i-1][j]->getNum_team()== getNum_team() ) 
            b[i-1][j]->setHealth_points(b[i-1][j]->getMax_health_points());
    }
    
    if( j<b[0].size()-1 && b[i][j+1] != nullptr){
        if(b[i][j+1]->getNum_team()== getNum_team()) 
            b[i][j+1]->setHealth_points(b[i][j+1]->getMax_health_points());
    }
   if(j>0 && b[i][j-1] != nullptr){
       if(b[i][j-1]->getNum_team()== getNum_team() ) 
            b[i][j-1]->setHealth_points(b[i][j-1]->getMax_health_points());
    }
    if(i<b[0].size()-1 && b[i+1][j] != nullptr){
        if(b[i+1][j]->getNum_team()== getNum_team() ) 
            b[i+1][j]->setHealth_points(b[i+1][j]->getMax_health_points());
    }
	
	
	
	int row = b.size();
    int col = b[0].size();
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
            if(s != nullptr) {        
                if(s->getNum_team()== getNum_team()){
                    if(Paramedic* ps=dynamic_cast<Paramedic*>(s)){
				    	ps->attack(b, i,j);
					}
            	}
            }
		}
	}
	
	
	
	
	
 }
};