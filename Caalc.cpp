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
}