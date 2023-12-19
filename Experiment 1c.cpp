#include<iostream>
using namespace std;

const int row = 3, column = 3;

int update(int mat[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int n = 0;
            cout <<"Enter element: ";
            cin >> n;
            mat[i][j] = n;
        }
    }
}
int add(int a[row][column], int b[row][column], int r[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}
int print(int mat[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
        	cout<< mat[i][j]<<"\t";
        }
        cout <<"\n";
    }
}
int multiply(int a[row][column], int b[row][column], int r[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int s = 0;
            for (int k = 0; k < row; k++)
            {
                s = s + (a[i][k] * b[k][j]);
            }
            r[i][j] = s;
        }
    }
}
int main()
{

    int a[row][column];
    int b[row][column];
    int r[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
        }
    }
    int ch = 1;
    while (ch == 1)
    {
        cout << "Menu driven Program to perform various function on matrices.\n";
        cout << "1) Update Matrix A.\n";
        cout << "2) Update Matrix B.\n";
        cout << "3) Add A and B\n";
        cout << "4) Print Matrices\n";
        cout << "5) Multiply A and B\n";
        int x = 0;
        cout << "Enter your choice >> ";
        cin >> x;
        switch (x)
        {
        case 1:
            update(a);
            cout << "\nMatrix A Updated\n";
            print(a);
            break;
        case 2:
            update(b);
            cout << "\nMatrix B Updated\n";
            print(b);
            break;
        case 3:
            add(a, b, r);
            cout << "\nMatrix after addition is\n";
            print(r);
            break;
        case 4:
            cout << "\nMatrix A\n";
            print(a);
            cout << "\nMatrix B\n";
            print(b);
            cout << "\nMatrix R\n";
            print(r);
            break;
        case 5:
            multiply(a, b, r);
            cout << "\n Matrix after multiplication\n";
            print(r);
            break;
        }

        cout << "Do you want to continue (0/1): ";
        cin >> ch;
    }
}
