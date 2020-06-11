#include "Board.hpp"
namespace WarGame {


// operator for putting soldiers on the game-board during initialization.
Soldier*& Board :: operator[](std::pair<int,int> location){

	return board[location.first][location.second];
}
    
    // operator for reading which soldiers are on the game-board.
Soldier* Board :: operator[](std::pair<int,int> location) const{
		
		return board[location.first][location.second];
	}
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
void Board :: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
	
	int first=source.first;
	int second=source.second;
	
	if(first >= board.size() || first < 0 || second >= board[0].size() || second < 0) {
		throw invalid_argument("Outside of the board");
		}
	
	Soldier* s = (*this)[source];
	
	
	if((*this)[{first,second}] == nullptr){
		
		
		 throw std::invalid_argument("No player in the selected location");
	}
	if(s->getNum_team() != player_number){
		throw std::invalid_argument("The player does not belong to your team");
	}
	int first_new;
	int second_new;
	
	if(direction == Up){
	first_new=first+1;
	second_new=second;
	}
	else if(direction == Down){
	first_new=first-1;
	second_new=second;
	}
	else if(direction == Right){
    second_new=second+1;
	first_new=first;
	}
	else{
	second_new=second-1;
    first_new=first;	
	}
	
	if(first_new < 0 || first_new >= board.size()|| second_new <0 || second_new >= board[0].size()){
			
		throw std::invalid_argument("Invalid displacement");
	}
	
	if((*this)[{first_new,second_new}] != nullptr){
		
		 throw std::invalid_argument("The place belongs to another soldier");
	}
	
	(*this)[source] = nullptr;
	(*this)[{first_new,second_new}] = s;
	s->attack(board, first_new,second_new);
	
	
	
}
	
		

    // returns true iff the board contains one or more soldiers of the given player.
bool Board :: has_soldiers(uint player_number) const{
		for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* s = (*this)[{i, j}];
				if (s != nullptr && s->getNum_team() == player_number){
					cout<<"true"<<endl;
				return true;
				}
				
			}
		}
		cout<<"false"<<endl;
		return false;
    }
void  Board :: print(){
		for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* s = (*this)[{i, j}];
				if (s != nullptr){
					cout <<s->getNum_team()<<"+"<<s->getHealth_points()<<"+"<<s->getDamage_points()<<" ";
				}
				else{
					cout<<"--"<<"	";
				}
				
			}
			cout<<endl;
		}
		
	}
};
	

	