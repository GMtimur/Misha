#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

double Foo(double x, double a, double b, double c) {
    if (x < 0 && b != 0) {
        return a * x * x + b;
    }
    else if (x > 0 && b == 0) {
        return (x - a) / (x - c);
    }
    else {
        return x / c;
    }
}

double Okrug(double value, double a, double b, double c) {
    int a_int = static_cast<int>(a);
    int b_int = static_cast<int>(b);
    int c_int = static_cast<int>(c);

    if (((a_int | b_int) & (a_int | c_int)) == 0) {
        return round(value);
    }
    else {
        return round(value * 100.0) / 100.0;
    }
}

void table(double arr[], double arg[], int n) {
    cout << "Массив #" << n << endl;
    cout << "___________________________" << endl;
    cout << "|     F      | |     x    |" << endl;
    cout << "|_________________________|" << endl;
    for (int i = 0; i < 15; i++) {
        cout << "| " << setw(10) << arr[i] << " | " << setw(10) << arg[i] << " |" << endl;
    }
    cout << "|_________________________|" << endl;
}

void zapArrays(double x1, double x2, double a, double b, double c, double array1[], double array2[], double xArray1[], double xArray2[], double sortedArray[]) {
    for (int i = 0; i < 15; i++) {
        double x = x1 + (x2 - x1) * (i / 14.0);
        array1[i] = Okrug(Foo(x, a, b, c), a, b, c);
        xArray1[i] = x;
        sortedArray[i] = Okrug(Foo(x, a, b, c), a, b, c);
    }

    for (int i = 0; i < 15; i++) {
        double x = -x2 + (x2 - x1) * (i / 14.0);
        array2[i] = Okrug(Foo(x, a, b, c), a, b, c);
        xArray2[i] = x;
    }
}


void prtArr(const double array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << array[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

void prtMin5(const double array[]) {
    for (int i = 0; i < 3; ++i) {
        double minVal = array[i * 5];
        for (int j = 1; j < 5; ++j) {
            if (array[i * 5 + j] < minVal) {
                minVal = array[i * 5 + j];
            }
        }
        cout << fixed << setprecision(2) << minVal << endl;
    }
}
int countDublikat(const double array[]) {
    map<double, int> freq;
    for (int i = 0; i < 15; ++i) {
        freq[array[i]]++;
    }

    int count = 0;
    for (const auto& entry : freq) {
        if (entry.second > 1) {
            count++;
        }
    }
    return count;
}


int stepFirst2(const double array[]) {
    for (int i = 0; i < 15; ++i) {
        bool isPowerOfTwo = true;
        for (int j = i; j < 15; ++j) {
            if (array[j] <= 0 || (array[j] != 1 && (log2(array[j]) - floor(log2(array[j]))) != 0)) {
                isPowerOfTwo = false;
                break;
            }
            if (j == 14 && array[j + 1] <= array[j])
                break;
        }
        if (isPowerOfTwo) return i + 1;
    }
    return -1;
}




void redistributeArrays(double array1[], double array2[]) {
    double negative[15] = { 0 };
    double positive[15] = { 0 };

    int negIndex = 0, posIndex = 0;
    for (int i = 0; i < 15; ++i) {
        if (array1[i] < 0) {
            negative[negIndex++] = array1[i];
        }
        if (array1[i] > 0) {
            positive[posIndex++] = array1[i];
        }
    }
    for (int i = 0; i < 15; ++i) {
        if (array2[i] < 0) {
            negative[negIndex++] = array2[i];
        }
        if (array2[i] > 0) {
            positive[posIndex++] = array2[i];
        }
    }



    while (negIndex < 15) negative[negIndex++] = 0;
    while (posIndex < 15) positive[posIndex++] = 0;


}

void bubble(double list[], int listLength)
{
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            swap(list[j], list[j + 1]);
            j--;
        }
    }
}
int main(int argc, char* argv[])
{
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = false;
    }


    setlocale(LC_ALL, "RU");
    double x1, x2, a, b, c;


    if (isHuman)cout << "x1, x2, a, b, c: " << endl;
    cin >> x1 >> x2 >> a >> b >> c;
    const int SIZE = 15;
    double array1[SIZE], array2[SIZE], sortedArray[SIZE];
    double xArray1[SIZE], xArray2[SIZE];

    zapArrays(x1, x2, a, b, c, array1, array2, xArray1, xArray2, sortedArray);


    if (isHuman) { table(array1, xArray1, 1); }
    else {
        for (int i = 0; i < 15; i++) {
            cout << array1[i];
            if (i != 14) cout << " ";
        }
        cout << endl;
    }
    if (isHuman) { table(array2, xArray2, 2); }
    else{
        for (int i = 0; i < 15; i++) {
            cout << array2[i];
            if (i != 14) cout << " ";
        }
        cout << endl;
    }
    const int size = 15;
    for (int i = 0; i < (size / 5.0); i++) {
        double min = array1[5 * i];
        for (int j = 0; j < 5; j++) {
            if (array1[5 * i + j] < min)
                min = array1[5 * i + j];
        }
        if (isHuman) cout << "минимум " << i + 1 << "-й пятерки равен ";
        cout << min << endl;
    }
    bubble(sortedArray, 15);
    if (isHuman) cout << "Сортированный массив: " << endl;
    for (int i = 0; i < 15; i++) {
        cout << sortedArray[i];
        if (i != 14) cout << " ";
    }
    cout << endl;

    if (isHuman) cout << "количество повторяющихся чисел: ";
    cout << countDublikat(array1) << endl;

    if (isHuman) cout << "номер элементы, начиная с которого степени 2: ";
    cout << stepFirst2(array1) << endl;

    redistributeArrays(array2, array1);

    prtArr(array2, SIZE);
    prtArr(array1, SIZE);

    return 0;
}