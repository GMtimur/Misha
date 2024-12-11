#include <iostream> 
#include <fstream> 
#include <sstream>

using namespace std;

//функция для создания матрицы
int** newMat(int size)
{
    int** matrix = new int* [size];//выделяется динамическая память для массива с указателями
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    return matrix;
}
//функция, которая удаляет матрицу, дабы освободить память 
void delMat(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i]; // удаляется динамический объект из памяти 
    }
    delete[] matrix;
}

void vodMat(int** matrix, int size)//функция для ввода значений матрицы
{
    cout << "введите элементы матрицы (" << size << "x" << size << "):" << endl;//данная строка предназначена для удобного ввода значений пользователю, которая означает, что матрица квадратная
    //количество строк равняется количеству столбцов
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void vvodMat(int** matrix, int size)//функция предназначена для вывода матрицы в консоль 
{
    cout << "Матрица (" << size << "x" << size << "):" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//функция, которая предназначена для редактирования элементов в матрице
void redMat(int** matrix, int size) {
    int rows, cols, newNumber;
    cout << "введите номер строки (0-" << size - 1 << ") и номер столбца (0-" << size - 1 << ") для редактирования: ";
    cin >> rows >> cols;

    if (rows >= 0 && rows < size && cols >= 0 && cols < size) {
        cout << "введите новое значение: ";
        cin >> newNumber;
        matrix[rows][cols] = newNumber;
    }
    else {
        cout << "ошибка. местонахождение элемента не найдено." << endl;
    }
}
//функция предназначения для суммирования двух матрицы, результат которой записывается в матрицу С
void sumMat(int** A, int** B, int** C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            if (C[i][j] < 0) {//условие на то, что элемент матрицы - отрицательное число 
                C[i][j] = 0;// то оно заменется на значение 0 
            }
        }
    }
}
//функция, предназначеная для записи матрицы в файл
void zapFileOfMate(const string& filename, int** matrix, int size) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << size << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                outFile << matrix[i][j] << " ";
            }
            outFile << endl;
        }
        outFile.close();
    }
    else {
        cout << "Не удалось открыть файл для записи." << endl;
    }
}

//функция для чтения матрицы из файла 
void readMatOfFile(const string& filename, int**& matrix, int& size) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Ошибка: файл не удалось открыть" << endl;
        return;
    }
    else {
        cout << "Файл успешно открыт" << endl;

        string line;
        if (getline(fin, line)) {
            size = stoi(line);
        }
        else {
            cout << "Ошибка: не удалось прочитать размер матрицы" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            if (getline(fin, line)) {
                istringstream iss(line);
                for (int j = 0; j < size; j++) {
                    if (!(iss >> matrix[i][j])) {
                        cout << "Ошибка: не удалось прочитать элемент матрицы на позиции ("
                            << i << ", " << j << ")" << endl;
                        matrix[i][j] = 0;
                    }
                }
            }
            else {
                cout << "Ошибка: не удалось прочитать строку " << endl;
            }
        }
        fin.close();
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int size;
    cout << "Введите размерность квадратных матриц: ";
    cin >> size;

    int** A = newMat(size);
    int** B = newMat(size);
    int** C = newMat(size);

    int choice;
    do {
        cout << "0. выход\n";
        cout << "1. ввести матрицу A и B\n";
        cout << "2. вывести матрицу A,B,C\n";
        cout << "3. записать матрицу в файл\n";
        cout << "4. прочитать матрицу из файла\n";
        cout << "5. редактировать элементы матрицы\n";
        cout << "6. суммировать матрицу A и B\n";
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {//при помощи конструкции switch case программа понимает, что следует вывести на экран, в зависимости от выбора условия, заданными пользователем
        case 1:
            vodMat(A, size);
            vodMat(B, size);
            vodMat(C, size);
            break;
        case 2:
            vvodMat(A, size);
            vvodMat(B, size);
            vvodMat(C, size);
            break;
        case 3:
            zapFileOfMate("matrixA.txt", A, size);
            zapFileOfMate("matrixB.txt", B, size);
            zapFileOfMate("matrixC.txt", C, size);
            break;

        case 4:
            readMatOfFile("matrixA.txt", A, size);
            readMatOfFile("matrixB.txt", B, size);
            readMatOfFile("matrixC.txt", C, size);
            break;
        case 5:
            cout << "Редактирование матрицы A:" << endl;
            redMat(A, size);
            cout << "Редактирование матрицы B:" << endl;
            redMat(B, size);
            break;
        case 6:
            sumMat(A, B, C, size);
            cout << "Сумма матриц A и B записана в C." << endl;
            break;
        case 0:
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 0);

    delMat(A, size);
    delMat(B, size);
    delMat(C, size);

    return 0;
}