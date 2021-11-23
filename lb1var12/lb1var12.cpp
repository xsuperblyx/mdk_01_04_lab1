#include <iostream>

using namespace std;

class SqrMatrix
{
private:
	double** result;
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
		result = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
			matrix2[i] = new double[size];
			matrixres[i] = new double[size];
			result[i] = new double[size];
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
		cout << "1) Генерация матриц" << endl;

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

		cout << "Сгенерированные матрицы размером " << size << "x" << size << ":" << endl;

		//вывод первой матрицы
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		// вывод второй матрицы
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix2[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Scalarmult() // умножение на скаляр
	{
		double scalar;
		cout << endl;
		cout << "2) Умножение матрицы на скаляр" << endl;
		cout << "Умножить матрицу на:" << endl;
		cin >> scalar;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				result[i][j] = matrix[i][j] * scalar;
			}
		}
		cout << "Результат умножения матрицы на скаляр:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Matrixmult() // умножжение матриц
	{
		cout << endl;
		cout << "3) Умножение матриц" << endl;
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

		// вывод 
		cout << "Результат умножения:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrixres[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Matrixsum() // сложение матриц
	{
		cout << endl;
		cout << "4) Сложение матриц" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
					matrixres[i][j] = matrix[i][j] + matrix2[i][j];
			}
		}

		// вывод 
		cout << "Результат сложения:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrixres[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Matrixsub() // вычитание матриц
	{
		cout << endl;
		cout << "5) Вычитание матриц" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrixres[i][j] = matrix[i][j] - matrix2[i][j];
			}
		}

		// вывод 
		cout << "Результат вычитания:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrixres[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Matrixdiv() // деление матриц
	{
		cout << endl;
		cout << "6) Деление матриц" << endl;
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

		// вывод 
		cout << "Результат деления:" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrixres[i][j] << " ";
			}
			cout << endl;
		}
	}
};


void main()
{
	setlocale(0, "RUSSIAN");
	SqrMatrix mat(5);
	mat.Creatematrix();
	mat.Fillmatrix();
	mat.Scalarmult();
	mat.Matrixmult();
	mat.Matrixsum();
	mat.Matrixsub();
	mat.Matrixdiv();
}