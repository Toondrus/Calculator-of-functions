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