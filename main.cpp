#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    if (rowNo < N)
    {
        CreateRow(a, rowNo, N, Low, High, 0);
        CreateRows(a, N, Low, High, rowNo + 1);
    }
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    if (rowNo < N)
    {
        PrintRow(a, rowNo, N, 0);
        PrintRows(a, N, rowNo + 1);
    }
    else
        cout << endl;
}

void SearchFirstEven(int** a, const int N, int i, int& minEven, int& k)
{
    if (i < N)
    {
        if (a[i][N - 1 - i] % 2 == 0)
        {
            k = i;
            minEven = a[i][N - 1 - i];
        }
        else
        {
            SearchFirstEven(a, N, i + 1, minEven, k);
        }
    }
}

void SearchMinEven(int** a, const int N, int i, int& minEven)
{
    if (i < N)
    {
        if (a[i][N - 1 - i] % 2 == 0 && a[i][N - 1 - i] < minEven)
            minEven = a[i][N - 1 - i];
        SearchMinEven(a, N, i + 1, minEven);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int N;
    cout << "N = ";
    cin >> N;
    cout << endl;

    int** a = new int*[N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = -9, High = 9;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    int k = -1;
    int minEven = INT_MAX;
    SearchFirstEven(a, N, 0, minEven, k);

    if (k > -1)
    {
        SearchMinEven(a, N, k + 1, minEven);
        cout << "minEven = " << minEven << endl;
    }
    else
    {
        cout << "there are no even elements" << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

