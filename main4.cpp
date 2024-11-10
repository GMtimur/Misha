#include <iostream>
using namespace std;


const int COLS = 10;
const int ROWS = 10;

void MulMat(int Mat1[ROWS][COLS], int Mat2[ROWS][COLS], int result[ROWS][COLS], int N, int M, int K) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < M; k++)
            {
                result[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}
void powMat(int Mat[ROWS][COLS], int result[ROWS][COLS], int x, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = 0;
            }
        }
    }

    for (int p = 0; p < x; p++) {
        int temp[ROWS][COLS] = { 0 };
        MulMat(result, Mat, temp, N, N, N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result[i][j] = temp[i][j];
    }
}

void prtMat(int matrix[ROWS][COLS], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j];
            if (j != M - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}



int main(int argc, char* argv[])
{
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }

    setlocale(LC_ALL, "RU");
    int N, M;

    if (isHuman) cout << "введите кол-во строк и столбцов Матрицы 1:" << endl;
    cin >> N >> M;

    int A1[COLS][ROWS];
    if (isHuman) cout << "введите элементы матрицы построчно:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A1[i][j];
        }
    }

    int command;

    while (true) {
        if (isHuman) cout << "КОММАНДЫ: 0 - выход из команды| 1 - актуальное значение матрицы| 2 - умножение двух матриц| 3 - возведение квадратной матрицы в степень: " << endl;
        cin >> command;

        if (command == 0) {
            break;
        }
        else if (command == 1) {
            prtMat(A1, N, M);
        }
        else if (command == 2) {
            int K;
            if (isHuman) cout << "введите кол-во столбцов матрицы А2" << endl;
            cin >> K;

            int A2[ROWS][COLS];
            if (isHuman) cout << "введите элементы матрицы А2:" << endl;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < K; j++) {
                    cin >> A2[i][j];
                }
            }

            if (M != M) {
                cout << "NO" << endl;
                continue;
            }

            int result[ROWS][COLS];
            MulMat(A1, A2, result, N, M, K);


            M = K;


            for (int i = 0; i < N; i++)
                for (int j = 0; j < K; j++)
                    A1[i][j] = result[i][j];


            if (isHuman) cout << "Ответ" << endl;
            prtMat(result, N, K);
        }

        else if (command == 3) {
            if (N != M) {
                cout << "NO" << endl;
                continue;
            }
            int x;
            if (isHuman) cout << "степень: " << endl;
            cin >> x;
            int result[10][10];
            powMat(A1, result, x, N);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A1[i][j] = result[i][j];
            cout << x << ":" << endl;
            prtMat(A1, N, M);
        }
        else {
            if (isHuman) cout << "ошибка " << endl;
        }

        return 0;
    }}