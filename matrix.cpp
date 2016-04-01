using namespace std;

#include <iostream>

class Matrix {
			int ** matr;
			int size;
	public:	
			Matrix(int size = 0);
			~Matrix();
};

Matrix :: Matrix(int size){
	if(size == 0){
		this -> size = 0;
		matr = NULL;
	} else {
		this -> size = size;
		matr = new int * [size];
		for(int i = 0; i < size; i++)
			matr[i] = new int[size];

		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				matr[i][j] = 0;
	}
};

Matrix :: ~Matrix(){
	if(size == 0){
		
	}
};

int main(){

return 0;
}
