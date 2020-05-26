#include <iostream>
#include "Soldier.hpp"
using namespace std;


class SniperCommander :public Soldier {
	public:
	SniperCommander(int number): Soldier(number){
		setHealth_points(120);
		setDamage_points(100);
		setMax_health_points(120);
		setType("snipercommander");
	}
 void attack(vector<vector<Soldier*>> &b, int first, int second){
	    int strong;
		int index1=-1; 
		int index2=-1;
		int index3=-1; 
		int index4=-1;
		for(int t= 0; t< b.size(); ++t){
			for(int l=0; l< b[t].size(); ++l) {
				Soldier* att = b[t][l];
				index3=t;
				index4=l;
				if (att != nullptr && att->getNum_team() == getNum_team()&& (att->getType() == "sniper" || att->getType() =="snipercommander")){					cout<<";;"<<endl;
				 for(int i= 0; i< b.size(); ++i){
					for(int j=0; j< b[i].size(); ++j) {
			        Soldier* s = b[i][j];
				      if (s != nullptr && s->getNum_team() != getNum_team()){
					  if(index1 == -1|| strong < s->getHealth_points()){
						strong=s->getHealth_points();
						index1=i;
						index2=j;
					}
				}
			
			}
			
		
		}
				
			    Soldier* strong=b[index1][index2];
				strong->setHealth_points(strong->getHealth_points()-b[index3][index4]->getDamage_points());
		        if(strong->getHealth_points() <= 0){
			    b[index1][index2]=nullptr;
				index1=-1; 
		        index2=-1;
			
		
				
				
			
			}
		}
	
			}}
	}
	
};