#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool prostoe(int t) 
{
    if (t <= 1) return false; 
    if (t == 2) return true;  
    if (t % 2 == 0) return false; 

    for (int i = 3; i*i <= t; i += 2) {
        if (t% i == 0) return false; 
    }
    return true;
}

bool countDegree(int t) {
    return (t > 0) && ((t & (t- 1)) == 0);
}

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "RUSSIAN");
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }
    int N;
     if (isHuman)cout << "Введите количество чисел: ";
    cin >> N;

    if (N <= 0) {
        if (isHuman) cout << "Количество чисел должно быть положительным!" << endl;
        return 1;
    }

    int sum = 0;
    int countMultiplicity5 = 0;
    int countDegree = 0;
    int countPrevious = 0;
    int prev1 = 0, prev2 = 0; 
    int maxk = INT_MIN, mink = INT_MAX;

    for (int i = 0; i < N; ++i) {
        int t;
        if (isHuman) cout << "Введите число " << (i + 1) << ": ";
        cin >> t;

        sum += t;

        if (t > maxk) maxk = t;
        if (t < mink) mink = t;

        if (prostoe(t)) {
            if (isHuman) cout << t << endl; 
        }

        if (t % 5 == 0) {
            countMultiplicity5++;
        }

        if (prostoe(t)) {
            countDegree++;
        }

        if (i >= 2 && t> (prev1 + prev2)) {
            countPrevious++;
        }

        prev2 = prev1;
        prev1 = t;
    }

    // вопрос номер 2
    double average = static_cast<double>(sum) / N;
    if (isHuman)  cout << "среднее арифметическое — " << endl;
    cout << fixed << setprecision(2) << average << endl;
    // вопрос номер 3
    if (isHuman)  cout << "разница между максимумом и минимумом —  " << endl;
    cout << (maxk - mink) << endl;
    // вопрос номер 4
    if (isHuman)  cout << "количество чисел, кратных 5 — " << endl;
    cout << countMultiplicity5 << endl;
    // вопрос номер 5
    if (isHuman)  cout << "количество чисел, которые являются  степенью двойки — " << endl;
    cout << countDegree << endl;
    // вопрос номер 6 
    if (isHuman)cout << "количество чисел, превышающих сумму двух предшествующих членов последовательности — " << endl;
    cout << countPrevious;
    return 0;
}