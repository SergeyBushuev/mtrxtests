#include "mtrx.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
Matrix<T>::Matrix() : lines(0), columns(0), massiv(nullptr)
{}
template <typename T>
Matrix<T>::Matrix(const Matrix &a)
{
	lines = a.lines;
	columns = a.columns;
	massiv = new int*[lines];

	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = a.massiv[i][j];
	}

}
template <typename T>
Matrix<T>::Matrix(int _lines, int _columns) : lines(_lines), columns(_columns)
{
	massiv = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = 0;
	}

}
template <typename T>
void Matrix<T>::read_matrix(const std::string s)
{
	ifstream fin(s);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			fin >> massiv[i][j];
	fin.close();

}
template <typename T>
void Matrix<T>::print_matrix() const
{
	for (int i = 0; i < lines; i++) {

		for (int j = 0; j < columns; j++)
			cout << massiv[i][j] << " ";
		cout << endl;
	}
}
template <typename T>
Matrix<T> & Matrix<T>::operator = (Matrix &a)
{
	for (int i = 0; i < lines; i++)

		delete[] massiv[i];
	delete[] massiv;
	lines = a.lines;
	columns = a.columns;
	massiv = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = a.massiv[i][j];
	}
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator + (const Matrix &array)
{

	Matrix result(*this);
	for (int i = 0; i < result.lines; i++)
		for (int j = 0; j < result.columns; j++)
			result.massiv[i][j] += array.massiv[i][j];
	return(result);
}

Matrix<T> Matrix<T>::operator * (const Matrix &array)
{

	Matrix result(lines, array.columns);
	result.reset();
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < array.columns; j++)
			for (int t = 0; t < columns; t++)
				result.massiv[i][j] += massiv[i][t] * array.massiv[t][j];
	return result;
}

int* Matrix<T>::operator [] (int i) const
{
	if ((i - 1) < 0) exit(0);
	int *temp = new int[columns];
	for (int j = 0; j < columns; j++)
		temp[j] = massiv[i - 1][j];
	return(temp);

}
int Matrix<T>::cout_columns() const
{
	return(columns);


}

int Matrix<T>::cout_lines() const
{
	return(lines);
}
void Matrix<T>::reset()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			massiv[i][j] = 0;
}

bool Matrix<T>::operator ==(const Matrix &array) const{
		if (lines != array.lines || columns != array.columns)
			return false; 

		for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
		if (massiv[i][j] != array.massiv[i][j])
			return false;

		return true; 
	}
Matrix<T>::~Matrix()
{
	for (int i = 0; i < lines; i++)

		delete[] massiv[i];
	delete[] massiv;

}
