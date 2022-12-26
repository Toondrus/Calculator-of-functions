#include <iostream>
#include <cmath>
using namespace std;
void Input_Matrix(int Lines, int Columns, int Matrix[20][20])
{
    for(int i = 0; i < Lines; i++)
    for(int j = 0; j < Columns; j++)
    {
        cout << "A[" << i << "][" << j << "]";
        cin >> A[i][j];
    }
}
void Output_Matrix(int Lines, int Columns, int Matrix[20][20])
{
    for(int i = 0; i < Lines; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            cout.width(7); cout << A[i][j];
        }
        cout << endl;
    }
}
void Mult_Matrix(int Lines1, int Lines2, int Columns1, int Columns2, int Matrix1[20][20], int Matrix2[20][20], int Fin_Matrix[20][20])
{
	int Lines3 = Lines1;
	int Columns3 = Columns2; 
	for(int i = 0; i < Lines3; i++)
	{
		for(int j = 0; j < Columns3; j++)
		{
			Fin_Matrix[i][j] = 0;
			for(int k = 0; k < Columns3; k++)
			{
				Fin_Matrix[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}
	Output_Matrix(Lines3, Columns3, Fin_Matrix);
}
void Clear_Memory(int** Matrix, int Size) 
{ 
    for(int i = 0; i < Size; i++) 
	{
        delete[] Matrix[i];
    }
        delete [] Matrix;        
}
int Find_Det(int** Matrix, int Size) 
{ 
    if (Size == 1)
        return Matrix[0][0];
    else if (Size == 2)
        return Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
    else 
	{
        int Det = 0;
        for (int k = 0; k < Size; k++) 
		{
            int** M = new int*[Size-1];
                for (int i = 0; i < Size - 1; i++) 
				{
                    M[i] = new int[Size - 1];
            	}
            for(int i = 1; i < Size; i++) 
			{
                int t = 0;
                for(int j = 0; j < Size; j++) 
				{
                    if (j == k)
                        continue;
                    M[i-1][t] = Matrix[i][j];
                    t++;
                }
            }
            Det += pow(-1, k + 2) * Matrix[0][k] * Find_Det(M, Size - 1);
            Clear_Memory(M, Size - 1);
        }
        return Det;
    }
}
int main()
{
    int Variant;
	cout << "1. Quadratic equation" << endl;
	cout << "2. Deteminant of square matrix" << endl;
	cout << "3. Multiplication matrix on matrix" << endl;
	cout << "4. Transposition of matrix" << endl;
	cout << "5. Multiplication matrix on number" << endl;
	cout << "0. Exit" << endl;
	cout << "Choose variant: ";
	cin >> Variant;
    switch(Variant)
	{
		case 1:
		{
			system("cls");
			float First_coeff;
			float Second_coeff;
			float Third_coeff;
			float x_0, x_1, x_2;
			float D;
			cout << "Input coefficiens of equetion" << endl;
			cout << "First coefficient: "; cin >> First_coeff;
			cout << "Second coefficient: "; cin >> Second_coeff;
			cout << "Third coefficient: "; cin >> Third_coeff; 
			D = Second_coeff * Second_coeff - 4 * First_coeff * Third_coeff; 
			cout << "\n";
			cout << "D = " << D << endl;
			if (D < 0) 
			{
				cout << "The discriminant is less than zero. The quadratic equation has no roots" << endl;
			}
			else if (D == 0) 
			{
				x_0 = (-First_coeff) / 2 * First_coeff;
				cout << "The discriminant is zero. The quadratic equation has 1 real root"<< " " << "x = " << x_0 << endl;
			}
			else if (D > 0) 
			{
				x_1 = (-Second_coeff + sqrt(D)) / (2 * First_coeff);
				x_2 = (-Second_coeff - sqrt(D)) / (2 * First_coeff);
				cout << "The discriminant is greater than zero. The quadratic equation has 2 real roots:" << endl;
				cout << "x_1 = " << x_1 << endl;
				cout << "x_2 = " << x_2 << endl;	
			}
			break;
		}
		case 2:
		{
			system("cls");
		    int Size;
		    cout << "Input a size of matrix: "; cin >> Size;
		    int** Matrix = new int*[Size];
		    for (int i = 0; i < Size; i++) 
			{
		        Matrix[i] = new int[Size];
		    }
		    cout << "\n";
			cout << "Input a matrix: " << endl;
		    for (int Lines = 0; Lines < Size; Lines++) 
			{
		        for (int Columns = 0; Columns < Size; Columns++) 
				{
		        	cout << "Matrix[" << Lines << "][" << Columns << "]";
		            cin >> Matrix[Lines][Columns]; 
		        }
		    }
		    cout << "\n";
			cout << "Found determinant: " << Find_Det(Matrix, Size) << endl;
		    Clear_Memory(Matrix, Size);
		    break;
		}
		case 3:
		{
			system("cls");
			int Matrix1[20][20], Matrix2[20][20];
			int Lines1, Lines2, Lines3;
			int Columns1, Columns2, Columns3;
			int Fin_Matrix[20][20];
			cout << "Lines and columns of first matrix" << endl;
			cout << "Lines: "; cin >> Lines1;
			cout << "Columns: "; cin >> Columns1; 
			cout << "\n";
			cout << "Input first matrix" << endl;
			Input_Matrix(Lines1, Columns1, Matrix1);
			cout << "\n";
			cout << "First matrix: "<< endl;
			Output_Matrix(Lines1, Columns1, Matrix1);
			cout << "\n";
			cout << "Lines and columns of second matrix" << endl;
			cout << "Lines: "; cin >> Lines2;
			cout << "Columns: "; cin >> Columns2;
			cout << "\n";
			cout << "Input second matrix" << endl;
			Input_Matrix(Lines2, Columns2, Matrix2);
			cout << "\n";
			cout << "Second matrix: " << endl;
			Output_Matrix(Lines2, Columns2, Matrix2);
			system("pause"); 
			system("cls"); 
			cout << "First matrix: "<< endl;
			Output_Matrix(Lines1, Columns1, Matrix1);
			cout << "\n";
			cout << "Second matrix: " << endl;
			Output_Matrix(Lines2, Columns2, Matrix2);
			Lines3 = Lines1;
			Columns3 = Columns2;
			cout << "\n";
			if (Columns1 != Lines2)
			{
				cout << "Unreal";
			}
			else
			{
				cout << "Composition:" << endl;
				Mult_Matrix(Lines1, Lines2, Columns1, Columns2, Matrix1, Matrix2, Fin_Matrix);
			}
			break;
		}
}