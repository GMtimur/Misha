#include <iostream>
#include <cmath> 
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }

    setlocale(LC_CTYPE, "RUSSIAN");
    if (isHuman) {
        cout << "Дан треугольник с координатами вершин (0,0)(3,0)(0,4)." << endl;
    }
    double x = 1.0, y = 1.0;

    do {
        if(isHuman) cout << "Введите координату x - ";
        cin >> x;
        if(isHuman) cout << "Введите координату y - ";
        cin >> y;
        if (x == 0 && y == 0) 
        {
            break;
        }

        if ((x >= 0 && x <= 3) && (y >= 0 && y <= 4)) 
        {
            if (y <= 4.0 - (4.0 / 3.0 * x)) {
                if (isHuman) {
                    cout << "Точка входит в треугольник." << endl;
                }
                else {
                    cout << "YES" << endl;
                }
            }
            else {
                if (isHuman) {
                    cout << "Точка не входит в треугольник." << endl;
                }
                else {
                    cout << "NO" << endl;
                }
            }
        }
        else {
            if (isHuman) {
                cout << "Точка не входит в треугольник." << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }

    } while (true);

    return 0;
}