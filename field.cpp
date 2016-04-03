using namespace std;

#include <iostream>
#include "matrix.h"

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

int main(){
	Field f(2);
	cout << f;
return 0;
}
