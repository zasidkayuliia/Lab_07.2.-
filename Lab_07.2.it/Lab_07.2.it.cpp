#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

void Create(int** a, const int rows, const int cols, const int Low, const int High);
void Print(int** a, const int rows, const int cols);
int SumMaxOddColumns(int** a, const int rows, const int cols);

int main()
{
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 100;
    int rows, cols;

    cout << "k: ";
    cin >> rows;
    cout << "n: ";
    cin >> cols;

    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    Create(a, rows, cols, Low, High);
    Print(a, rows, cols);

    int sum = SumMaxOddColumns(a, rows, cols);
    cout << "Сума максимальних елементів по непарних стовпцях матриці = " << sum << endl;

    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rows, const int cols, const int Low, const int High)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rows, const int cols)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumMaxOddColumns(int** a, const int rows, const int cols)
{
    int sum = 0;
    for (int j = 1; j < cols; j += 2) 
    {
        int maxElement = a[0][j];
        for (int i = 1; i < rows; i++)
        {
            if (a[i][j] > maxElement)
                maxElement = a[i][j];
        }
        sum += maxElement;
    }
    return sum;
}

