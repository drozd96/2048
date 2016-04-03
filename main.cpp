using namespace std;

#include <iostream>

int main(){
	Field game;
	game.new_game();
	
	while(game.IsEmpty_place() == 1){
		game.move();
		game.continue_game(); // if no empty place this function exit from the game
	}
return 0;
}
