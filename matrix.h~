#ifndef _matrix_h_
#define _matrix_h_

class Matrix {
			int ** matr;
			int size;
	public:	
			Matrix(int size = 0);
			Matrix(const Matrix & m);
			~Matrix();

			Matrix & operator = (const Matrix & m);
			Matrix & operator + (const Matrix & m);
			Matrix & operator - (const Matrix & m);
			int sum_proizv(const Matrix & m, int k, int l) const;
			Matrix & operator * (const Matrix & m);
			int ** get_pointer() const;	
			int get_size() const;
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

Matrix & Matrix :: operator + (const Matrix & m){
	if(m.size == 0 || m.size != size) return *this;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matr[i][j] += m.matr[i][j]; 
return *this;
};

Matrix & Matrix :: operator - (const Matrix & m){
	if(m.size == 0 || m.size != size) return *this;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matr[i][j] -= m.matr[i][j]; 
return *this;
};

int Matrix :: sum_proizv(const Matrix & m, int k, int l) const {
	int sum = 0;
	for(int i = 0; i< size; i++){
		cout << "matr[ " << k << " ][ " << i << "] = " << matr[k][i] << endl;
		cout << "matr[ " << i << " ][ " << l << "] = " << matr[i][l] << endl;
		sum += matr[k][i] * m.matr[i][l];
	}
	cout << endl;
return sum;
};

Matrix & Matrix :: operator * (const Matrix & m){
	if(m.size == 0 || m.size != size) return * this;
	Matrix tmp(*this); 
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matr[i][j] = tmp.sum_proizv(m,i,j);
return * this;
};

Matrix :: ~Matrix(){
	if(size != 0){
		for(int i = 0; i < size; i++)
			delete [] matr[i];
		delete [] matr;
	}
};

int ** Matrix :: get_pointer() const{
return matr;
};

int Matrix :: get_size() const {
return size;
};

ostream & operator << (ostream & s, const Matrix & m){
	for(int i = 0; i < m.size; i++){
		for(int j = 0; j < m.size; j++)
			s << m.matr[i][j] << " ";
		s << endl;	
	} 
return s;
};

#endif
istream & operator >> (istream & s, const Matrix & m){
	for(int i = 0; i < m.size; i++)
		for(int j = 0; j < m.size; j++)
			s >> m.matr[i][j];
return s;
};
