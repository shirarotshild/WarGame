#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <cassert>


	

TEST_CASE("Positioning the players"){
           WarGame:: Board board (8, 8);
		    board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,5}] = new FootSoldier(1);
			Soldier *s1=board[{0,1}];
			Soldier *s2=board[{0,3}];
			Soldier *s3=board[{0,5}];
			
			CHECK((s1->getNum_team()) ==1);
			CHECK((s2->getNum_team()) ==1);
			CHECK((s3->getNum_team()) ==1);
			
			CHECK((s1->getHealth_points()) ==100);
			CHECK((s2->getHealth_points()) ==100);
			CHECK((s3->getHealth_points()) ==100);
			
			CHECK((s1->getDamage_points()) ==1);
			CHECK((s2->getDamage_points()) ==1);
			CHECK((s3->getDamage_points()) ==1);
			
			
			
			
			
			
			
			board[{7,1}] = new FootSoldier(2);
			board[{7,3}] = new FootCommander(2);
			board[{7,5}] = new FootSoldier(2);
}	
