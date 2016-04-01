using namespace std;

#include <iostream>

class Matrix {
			int ** matr;
			int size;
	public:	
			Matrix(int size = 0);
			Matrix(const Matrix & m);
			~Matrix();

			Matrix & operator = (const Matrix & m);
			friend ostream & operator << (ostream & s, const Matrix & m);
			friend istream & operator >> (istream & s, const Matrix & m);
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

Matrix :: Matrix(const Matrix & m){
	// create space for new matrix
	size = m.size;
	matr = new int *[size];
	for(int i = 0; i < size; i++)
		matr[i] = new int [size];
	// initializate new matrix
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matr[i][j] = m.matr[i][j];
};

Matrix & Matrix :: operator = (const Matrix & m){
	// delete previous matrix	
	if(size != 0){
		for(int i = 0; i < size; i++)
			delete [] matr[i];
		delete [] matr;
	}
	// create space for new matrix
	size = m.size;
	matr = new int *[size];
	for(int i = 0; i < size; i++)
		matr[i] = new int [size];
	// initializate new matrix
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matr[i][j] = m.matr[i][j];
return *this;
};

Matrix :: ~Matrix(){
	if(size != 0){
		for(int i = 0; i < size; i++)
			delete [] matr[i];
		delete [] matr;
	}
};

ostream & operator << (ostream & s, const Matrix & m){
	for(int i = 0; i < m.size; i++){
		for(int j = 0; j < m.size; j++)
			s << m.matr[i][j] << " ";
		s << endl;	
	} 
return s;
};

istream & operator >> (istream & s, const Matrix & m){
	for(int i = 0; i < m.size; i++)
		for(int j = 0; j < m.size; j++)
			s >> m.matr[i][j];
return s;
};

int main(){
	Matrix m(2);
return 0;
}
