#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
template <typename T>
class Matrix;

class Matrix
{
private:
	int lines;
	int columns;
	T **massiv;
public:
	int cout_columns() const;
	int cout_lines() const;
	Matrix<T>();
	Matrix<T>(const Matrix &a);
	~Matrix<T>();
	Matrix(int _lines, int _columns);
	void read_matrix(std::string s);
	void print_matrix() const;
	Matrix operator + (const Matrix &array);
	Matrix operator * (const Matrix &array);
	int* operator [](int i) const;
	Matrix &operator = (Matrix &a);
	void reset();
	bool operator ==(const Matrix &array) const;

};

#endif
