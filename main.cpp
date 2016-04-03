using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "field.h"

int main(){
	Field game(4);
	game.new_game();

	while(game.IsEmpty_place() == 1){
		cout << game;
		game.move();
		game.continue_game(); // if no empty place this function exit from the game
	}
return 0;
}
