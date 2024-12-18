#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX_STUDENTS = 100;
const int GRADES_COUNT = 5;

struct STUDENT {
    char name[100];
    int group_number;
    int grades[GRADES_COUNT];
};

void print(double size, string ch)
{
    for (int i = 0; i <= size; i++)
        cout << ch;
}

void inf_student(STUDENT students[], int count, int S, bool isHuman) {
    if (isHuman) {
        S++;
        cout << "______________________";
        print(S, "_");
        cout << "____________________________" << endl;
        cout << "| Группа             | ФИО";
        print(S - 4, " ");
        cout << "| Оценки                   |" << endl;
        cout << "|____________________|";
        print(S, "_");
        cout << "|__________________________|" << endl;

        for (int i = 0; i < count; i++) {
            cout << "| " <<left << setw(19) << students[i].group_number << "| " << left << setw(S) << students[i].name << setw(3) << "| ";
            for (int j = 0; j < GRADES_COUNT; j++) {
                cout << students[i].grades[j];
                if (j < GRADES_COUNT - 1) cout << ",";
            }
            cout << string(25 - (2 * GRADES_COUNT), ' ');
            cout << "|" << endl;
            cout << "|____________________|";
            print(S, "_");
            cout << "|__________________________|" << endl;
        }
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << students[i].group_number << " - " << students[i].name << ":";
            for (int j = 0; j < GRADES_COUNT; j++) {
                cout << " " << students[i].grades[j];
                if (j < GRADES_COUNT - 1) cout << ",";
            }
            cout << endl;
        }
    }
}


float sr_ball(int grades[]) {
    float sum = 0;
    for (int i = 0; i < GRADES_COUNT; i++) {
        sum += grades[i];
    }
    return sum / GRADES_COUNT;
}

void sort_bubble(STUDENT students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (sr_ball(students[j].grades) < sr_ball(students[j + 1].grades)) {
                STUDENT temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void inf_srBall(STUDENT students[], int count, int S, bool isHuman) {
    sort_bubble(students, count);
    bool found = false;
    if (isHuman)
    {
        S++;
        cout << "_________________";
        print(S, "_");
        cout << "________________________" << endl;
        cout << "| Номер группы  | ФИО";
        print(S - 4, " ");
        cout << "| Средний балл         | " << endl;
        cout << "|_______________|";
        print(S, "_");
        cout << "|______________________|" << endl;


    for (int i = 0; i < N; i++) {
        cin.ignore();
        if (isHuman) cout << "Введите ФИО студента " << (i + 1) << ": ";
        cin.getline(students[i].name, sizeof(students[i].name));
        if (S < size(string(students[i].name)))
            S = size(string(students[i].name));

        if (isHuman) cout << "Введите номер группы студента " << (i + 1) << ": ";
        cin >> students[i].group_number;

        if (isHuman) cout << "Введите 5 оценок студента " << (i + 1) << ": ";
        for (int j = 0; j < GRADES_COUNT; j++) {
            cin >> students[i].grades[j];
        }
    }
    if (isHuman) {
        cout << "Полный список студентов по возрастанию номера группы:" << endl;
    }
    inf_student(students, N, S, isHuman);
    if (isHuman) {
        cout << endl << "Студенты со средним баллом > 4.0, упорядоченные по убыванию среднего балла:" << endl;
    }
    inf_srBall(students, N, S, isHuman);
    if (isHuman) {
        cout << endl << "Сводка по группам:" << endl;
    }
    print_group_info(students, N, isHuman);

    return 0;
}