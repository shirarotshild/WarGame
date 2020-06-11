#include <iostream>
#include "Soldier.hpp"
#include <math.h>   
using namespace std;


class FootCommander :public Soldier {
	public:
	FootCommander (int number): Soldier(number){
		setHealth_points(150);
		setDamage_points(20);
		setMax_health_points(150);
		setType("FootCommander");
	}
	void attack(vector<vector<Soldier*>> &b, int first, int second){
	    double minDis;
		int index1=-1; 
		int index2=-1;
		int index3=-1; 
		int index4=-1;
		for(int t= 0; t< b.size(); ++t){
			for(int l=0; l< b[t].size(); ++l) {
				Soldier* att = b[t][l];
				index3=t;
				index4=l;
				if (att != nullptr && att->getNum_team() == getNum_team() && att->getType() == "FootSoldier"){
				 for(int i= 0; i< b.size(); ++i){
					for(int j=0; j< b[i].size(); ++j) {
			        Soldier* s = b[i][j];
				      if (s != nullptr && s->getNum_team() != getNum_team()){
					double dis=distance(t,l,i,j);
					if(index1 == -1 || minDis > dis){
						minDis=dis;
						index1=i;
						index2=j;
					
					}
				}
			
			}
			
		
		}
				
			    Soldier* minS=b[index1][index2];
				minS->setHealth_points(minS->getHealth_points()-b[index3][index4]->getDamage_points());
		        if(minS->getHealth_points() <= 0){
			    b[index1][index2]=nullptr;}
				index1=-1; 
		        index2=-1;
		
				
				
			
			
		}
	
			}}
	}
		
	
  private:
	
	double distance(int x1, int y1, int x2, int y2){
	  int temp1= pow(x2-x1,2);
	  int temp2= pow(y2-y1,2);
	  return sqrt(temp1+temp2);
	}
   	
 
	
};
