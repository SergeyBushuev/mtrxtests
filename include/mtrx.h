using namespace std;

class Matrix
{
private:
	long int **Matr;
	long int m;
	long int n;

	void Create()
	{
		Matr = new long int*[m];
		for (int z = 0; z<m; z++)
			Matr[z] = new long int[n];
	}

public:
	// constructors and destructor
	Matrix() : m(5), n(5) { Create(); }

	Matrix(long int i) : m(i), n(i) { Create(); }

	Matrix(long int i, long int j) : m(i), n(j) { Create(); }

	~Matrix()
	{
		for (int z = 0; z<m; z++)
			delete[] Matr[z];
		delete[] Matr;
	}

	// methods
	long int& Element(long int i, long int j)
	{
		if (i<m && j<n)
			return Matr[i][j];
		else
			cout << "Error: 1";
	}

	void MultiplyBy(long int x)
	{
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				Matr[i][j] *= x;
	}

	void Display()
	{
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cout.width(4);
				cout << Matr[i][j];
			}
			cout << endl;
		}
	}
	void operator +(Matrix &mx)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Matr[i][j] += mx.Matr[i][j];
	}
	void operator -(Matrix &mx)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Matr[i][j] += mx.Matr[i][j];
	}
	Matrix operator *(Matrix &mx)
	{
		Matrix result(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				for (int t = 0; t < n; t++)
					result.Matr[i][j] += Matr[i][t] + mx.Matr[t][j];
	}
	int getstr()
	{
		return m;
	}
	int getstl()
	{
		return n;
	}

};
