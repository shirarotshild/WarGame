#include <iostream>
#include "Soldier.hpp"
#include <math.h>    

using namespace std;


class FootSoldier :public Soldier {
	public:
	FootSoldier(int number): Soldier(number){
	setHealth_points(100);
	setDamage_points(100);
	}
	void attack(vector<vector<Soldier*>> &b, int first, int second, int player_number){
		//Soldier* minS;
		int index1=-1; 
		int index2=-1;
		for(int i= 0; i< b.size(); ++i){
			double minDis;
			for(int j=0; j< b[i].size(); ++j) {
			Soldier* s = b[i][j];
				if (s != nullptr && s->getNum_team() != player_number){
					double dis=distance(first,second,i,j);
					if(index1 == -1|| minDis > dis){
						minDis=dis;
						index1=i;
						index2=j;
					}
				}
			
			}
		}
		Soldier* minS=b[index1][index2];
		minS->setHealth_points(minS->getHealth_points()-b[first][second]->getDamage_points());
		if(minS->getHealth_points() <= 0){
			b[index1][index2]=nullptr;
		}
		cout<<minS->getHealth_points()<<endl;
		
	
	}
	private:
	
	double distance(int x1, int x2, int y1, int y2){
	  int temp1= pow(x2-x1,2);
	  int temp2= pow(y2-y1,2);
	  return sqrt(temp1+temp2);
	}
   	
	
	
 
	
};