#include <iostream>
#include <cstring> 
using namespace std;

void MulMat(int** Mat1, int** Mat2, int** result, int N, int M, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}

void powMat(int** Mat, int** result, int x, int N) {
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
        int** temp = new int* [N];
        for (int i = 0; i < N; i++)
            temp[i] = new int[N]();

        MulMat(result, Mat, temp, N, N, N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result[i][j] = temp[i][j];

        for (int i = 0; i < N; i++)
            delete[] temp[i];
        delete[] temp;
    }
}

void prtMat(int** matrix, int N, int M) {
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

void inputMatrix(int** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main(int argc, char* argv[]) {
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }

    setlocale(LC_ALL, "RU");
    int N, M;

    if (isHuman) cout << "введите кол-во строк и столбцов Матрицы 1:" << endl;
    cin >> N >> M;

    int** A1 = new int* [N];
    for (int i = 0; i < N; i++)
        A1[i] = new int[M];

    if (isHuman) cout << "введите элементы матрицы построчно:" << endl;
    inputMatrix(A1, N, M);

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

            int** A2 = new int* [M];
            for (int i = 0; i < M; i++)
                A2[i] = new int[K];

            if (isHuman) cout << "введите элементы матрицы А2:" << endl;
            inputMatrix(A2, M, K);

            if (M != M) {
                cout << "NO" << endl;
                continue;
            }


            int** result = new int* [N];
            for (int i = 0; i < N; i++)
                result[i] = new int[K];

            MulMat(A1, A2, result, N, M, K);


            M = K;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < K; j++)
                    A1[i][j] = result[i][j];


            for (int i = 0; i < N; i++)
                delete[] result[i];
            delete[] result;


            for (int i = 0; i < M; i++)
                delete[] A2[i];
            delete[] A2;

        }
        else if (command == 3) {
            if (N != M) {
                cout << "NO" << endl;
                continue;
            }
            int x;
            if (isHuman) cout << "степень: " << endl;
            cin >> x;

            int** result = new int* [N];
            for (int i = 0; i < N; i++)
                result[i] = new int[N];

            powMat(A1, result, x, N);


            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    A1[i][j] = result[i][j];
                for (int i = 0; i < N; i++)
                delete[] result[i];
            delete[] result;
        }
        else {
            if (isHuman) { cout << "ошибка " << endl; }
            else { cout << "NO" << endl; }
        }
    }


    for (int i = 0; i < N; i++)
        delete[] A1[i];
    delete[] A1;

    return 0;
}