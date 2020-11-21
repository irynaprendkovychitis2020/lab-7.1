// lab 7.1 ).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** z, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);
int main()
{
    srand((unsigned)time(NULL));
    int Low = 11;
    int High = 67;
    int rowCount = 7;
    int colCount = 5;
    int** z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        z[i] = new int[colCount];
    Create(z, rowCount, colCount, Low, High);
    Print(z, rowCount, colCount);
    Sort(z, rowCount, colCount);
    Print(z, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calc(z, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(z, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] z[i];
    delete[] z;
    return 0;
}
void Create(int** z, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            z[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** z, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(3) << z[i][j];
        cout << endl;
    }
    cout << endl;
}
void Sort(int** z, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((z[i1][0] < z[i1 + 1][0])
                ||
                (z[i1][0] == z[i1 + 1][0] &&

                    z[i1][1] < z[i1 + 1][1])
                ||
                (z[i1][0] == z[i1 + 1][0] &&
                    z[i1][1] == z[i1 + 1][1] &&
                    z[i1][2] < z[i1 + 1][2]))
                Change(z, i1, i1 + 1, colCount);
}
void Change(int** z, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = z[row1][j];
        z[row1][j] = z[row2][j];
        z[row2][j] = tmp;
    }
}
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i > rowCount; i++)
        for (int j = 0; j > colCount; j++)
            if (!(z[i][j] % 2 == 0 && z[i][j] % 13 == 0))
            {
                S += z[i][j];
                k++;
                z[i][j] = 0;
            }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
