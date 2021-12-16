#include <iostream>

using namespace std;

class SqrMatrix
{
private:
	double** matrix;
	double** matrix2;
	double** matrixres;
	int size;

public:
	SqrMatrix(int s)
	{
		size = s;
	}

	double Creatematrix() // создание матриц
	{
		matrix = new double* [size];
		matrix2 = new double* [size];
		matrixres = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
			matrix2[i] = new double[size];
			matrixres[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
				matrix2[i][j] = 0;
				matrixres[i][j] = 0;
			}
		}
		return **matrix;
	}

	void Fillmatrix() // заполнение матриц
	{
		//первая матрица
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j]= rand() % 3 + 1; // заполнение случайными числами от 1 до 3
			}
		}

		//вторая матрица
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix2[i][j] = rand() % 3 + 1; // заполнение случайными числами от 1 до 3
			}
		}

		Print(size, matrix);
		Print(size, matrix2);
	}

	void Scalarmult() // умножение на скаляр
	{
		double scalar;
		cin >> scalar;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrixres[i][j] = matrix[i][j] * scalar;
			}
		}
		Print(size, matrixres);
	}

	void Matrixmult() // умножжение матриц
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int m = 0; m < size; m++)
				{
					matrixres[i][j] += matrix[i][m] * matrix2[m][j];
				}
			}
		}
		Print(size, matrixres);
	}

	void Matrixsum() // сложение матриц
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
					matrixres[i][j] = matrix[i][j] + matrix2[i][j];
			}
		}
		Print(size, matrixres);
	}

	void Matrixsub() // вычитание матриц
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrixres[i][j] = matrix[i][j] - matrix2[i][j];
			}
		}
		Print(size, matrixres);
	}

	void Matrixdiv() // деление матриц
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int m = 0; m < size; m++)
				{
					matrixres[i][j] = 0;
					matrixres[i][j] += matrix[i][m] * (1/matrix2[m][j]);
				}
			}
		}
		Print(size, matrixres);
	}

	~SqrMatrix() // деструктор с освобождением памяти
	{
		delete[] matrix;
		delete[] matrix2;
		delete[] matrixres;
	}

	void Print(int s, double ** mtrx)
	{
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s; j++)
			{
				cout << mtrx[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};


void main()
{
	setlocale(0, "RUSSIAN");
	SqrMatrix mat(5);
	mat.Creatematrix();
	cout << "1) Генерация матриц" << endl;
	cout << "Сгенерированные матрицы размером " << 5 << "x" << 5 << ":" << endl;
	mat.Fillmatrix();
	cout << "2) Умножение матрицы на скаляр" << endl;
	cout << "Умножить матрицу на: ";
	mat.Scalarmult();
	cout << "3) Умножение матриц" << endl;
	cout << "Результат умножения матриц:" << endl;
	mat.Matrixmult();
	cout << "4) Сложение матриц" << endl;
	cout << "Результат сложения матриц:" << endl;
	mat.Matrixsum();
	cout << "5) Вычитание матриц" << endl;
	cout << "Результат вычитания:" << endl;
	mat.Matrixsub();
	cout << "6) Деление матриц" << endl;
	cout << "Результат деления:" << endl;
	mat.Matrixdiv();
}