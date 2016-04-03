using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "matrix.h"

#define pos 0
#define start 1
#define end 2

class Field : private Matrix{
	public:
			Field(int size = 0): Matrix(size) {};
			Field(const Field & f): Matrix(f) {};
			Field & operator = (const Field & f);
			Field & operator + (const Field & f);
			Field & operator - (const Field & f);

			int ** get_pointer() const;
			int get_size() const;
			friend ostream & operator << (ostream & s, const Field & f);
			friend istream & operator >> (istream & s, const Field & f);

			int gen_position();
			Field & new_game();
			bool IsEmpty_place();
			Field & continue_game();
			Field & move();
			void end_game();

			Field & up();	
			Field & down();
			Field & left();
			Field & right();

			Field & merge(int to_i, int to_j, int from_i, int from_j);
			bool compare(int i1, int j1, int i2, int j2);

			~Field(){};	

			friend char touch_key();
			friend void help();		
}; 

Field & Field :: operator = (const Field & f){ 
	Matrix :: operator = (f);
return * this;
};

Field & Field :: operator + (const Field & f){
	Matrix :: operator + (f);
return * this;
};

Field & Field :: operator - (const Field & f){
	Matrix :: operator - (f);
return * this;
}; 

int ** Field :: get_pointer() const {
return Matrix :: get_pointer();
};

int Field :: get_size() const {
return Matrix :: get_size();
};

ostream & operator << (ostream & s, const Field & f){
	for(int i = 0; i < f.get_size(); i++){
		for(int j = 0; j < f.get_size(); j++)
			s << (f.get_pointer())[i][j] << " ";
		s << endl;	
	} 
return s;
};

istream & operator >> (istream & s, const Field & f){
	for(int i = 0; i < f.get_size(); i++)
		for(int j = 0; j < f.get_size(); j++)
			s >> (f.get_pointer())[i][j];
return s;
};

//-------------------------------------------------------------------------------------

void help(){
	cout << "There will be an information about the game" << endl;
}

char touch_key(){
	cout << "Press w,a,s,d to move or h to help" << endl;
	char c;
	do {
		cin >> c;
	} while(c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'h');
	if(c == 'h'){ help(); c = touch_key(); }
return c;	
};


int Field :: gen_position(){
return (pos + rand() % this -> get_size());
};

Field & Field :: new_game(){
	int i, j;
	for(int k = 0; k < 2; k++){
		i = this -> gen_position();
		do {
			j = this -> gen_position();
		} while((this -> get_pointer())[i][j] != 0);
		(this -> get_pointer())[i][j] = (start + rand() % end) * 2;
	}
return * this;
};

bool Field :: IsEmpty_place(){
	for(int i = 0; i < this -> get_size(); i++)
		for(int j = 0; j < this -> get_size(); j++)
			if((this -> get_pointer())[i][j] == 0) return 1;
return 0;
};

void Field :: end_game(){
	cout << "Game Over" << endl;
	exit(0);
};

Field & Field :: continue_game(){
	if(this -> IsEmpty_place() == 1){	
		int i, j;
		do {
			i = this -> gen_position();
			j = this -> gen_position();
		} while((this -> get_pointer())[i][j] != 0);
		(this -> get_pointer())[i][j] = (start + rand() % end) * 2;
	} else {
		this -> end_game();
	}
return * this;	
}; 

Field & Field :: merge(int to_i, int to_j, int from_i, int from_j){
	(this -> get_pointer())[to_i][to_j] *= 2;
	(this -> get_pointer())[from_i][from_j] = 0;
return * this;
};

bool Field :: compare(int i1, int j1, int i2, int j2){
	if((this -> get_pointer())[i1][j1] == (this -> get_pointer())[i2][j2]) return 1;
return 0;
};

Field & Field :: up(){
	
return * this;
};

Field & Field :: down(){

return * this;
};

Field & Field :: left(){
	cout << "left" << endl;

	for(int i = 0; i < this -> get_size(); i++)
		for(int j = 0; j < this -> get_size(); j++)
			
	
	for(int i = 0; i < this -> get_size(); i++)
		for(int j = 0; j < this -> get_size(); j++)
			if(j != this -> get_size() - 1)					
				if(this -> compare(i, j, i, j + 1) == 1) this -> merge(i, j, i, j + 1);
return * this;
};

Field & Field :: right(){

return * this;
};

Field & Field :: move(){
	char way = touch_key();
	switch(way){
		case 'w': this -> up();    break;	
		case 'a': this -> left();  break;
		case 's': this -> down();  break;
		case 'd': this -> right(); break;
		default: cout << "There is some problem" << endl; exit(0); break;
	}
return * this;
};

int main(){
	srand(time(NULL));
	Field f(4);
	f.new_game();
	for(int i = 0; i < 6; i++)
		f.continue_game();
	cout << f;
	f.move();
	cout << f;
return 0;
}
