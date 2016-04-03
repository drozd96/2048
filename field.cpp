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
			void end_game();
			~Field(){};			
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

int main(){
	srand(time(NULL));
	Field f(4);
	f.new_game();
	f.continue_game();
	cout << f;
return 0;
}
