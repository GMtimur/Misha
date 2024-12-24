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

struct GroupInfo {
    int group_number;
    int student_count;
    int bad_count;
};

void print(double size, string ch)
{
    for (int i = 0; i <= size; i++)
        cout << ch;
}


void bubbleSort(STUDENT students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].group_number > students[j + 1].group_number) {
                STUDENT temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void inf_student(STUDENT students[], int count, int S, bool isHuman) {
    bubbleSort(students, count);

    if (isHuman) {
        S++;
        cout << "______________________";
        print(S, "_");
        cout << "____________________________" << endl;
        cout << "|       Группа       |";
        print((S - 3) / 2, " ");
        cout << "ФИО";
        if ((S - 3) % 2 == 1)
            print((S - 3) / 2, " ");
        else
            print((S - 3) / 2 + 1, " ");
        cout << "|          Оценки          |" << endl;
        cout << "|____________________|";
        print(S, "_");
        cout << "|__________________________|" << endl;
        for (int i = 0; i < count; i++) {
            cout << "|";
            print(7, " ");
            cout << students[i].group_number;
            print(7, " ");
            cout << "|";
            print((S - size(string(students[i].name))) / 2, " ");
            cout << students[i].name;
            if ((S - size(string(students[i].name))) % 2 == 1)
                print((S - size(string(students[i].name))) / 2, " ");
            else
                print((S - size(string(students[i].name))) / 2 - 1, " ");
            cout << "|";
            print(5, " ");
            for (int j = 0; j < GRADES_COUNT; j++) {
                cout << students[i].grades[j];
                if (j < GRADES_COUNT - 1) cout << ", ";
            }
            print(5, " ");
            cout << " |" << endl;
            cout << "|____________________|";
            print(S, "_");
            cout << "|__________________________|" << endl;
        }
    }
    else {
        for (int i = 0; i < count; i++) {
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
    int count_sr_ball = 0;
    for (int i = 0; i < count; i++) {
        float avg = sr_ball(students[i].grades);
        if (avg > 4.0) {
            count_sr_ball++;
        }
    }
    if (count_sr_ball == 0) {
        if (isHuman) {
            cout << "Отсутствуют." << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        if (isHuman)
        {
            S++;
            cout << "________________";
            print(S, "_");
            cout << "_______________________" << endl;
            cout << "| Номер группы |";
            print((S - 3) / 2, " ");
            cout << "ФИО";
            if ((S - 3) % 2 == 1)
                print((S - 3) / 2, " ");
            else
                print((S - 3) / 2 + 1, " ");
            cout << "|    Средний балл     | " << endl;
            cout << "|______________|";
            print(S, "_");
            cout << "|_____________________|" << endl;


            for (int i = 0; i < count; i++) {
                float avg = sr_ball(students[i].grades);
                if (avg > 4.0) {
                    cout << "|";
                    print(4, " ");
                    cout << students[i].group_number;
                    print(4, " ");
                    cout << "|";
                    print((S - size(string(students[i].name))) / 2, " ");
                    cout << students[i].name;
                    if ((S - size(string(students[i].name))) % 2 == 1)
                        print((S - size(string(students[i].name))) / 2, " ");
                    else
                        print((S - size(string(students[i].name))) / 2 - 1, " ");
                    if (round(avg * 10.0) / 10.0 == round(avg)) {
                        cout << "|          ";
                        cout << round(avg * 10.0) / 10.0;
                        cout << "          |" << endl;
                    }
                    else {
                        cout << "|         ";
                        cout << fixed << setprecision(1) << avg;
                        cout << "         |" << endl;
                    }
                    found = true;
                }
            }
            cout << "|______________|";
            print(S, "_");
            cout << "|_____________________|" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                float avg = sr_ball(students[i].grades);
                if (avg <= 4)
                    break;
                cout << students[i].group_number << ", " << students[i].name << " - ";
                if (avg == 5)
                    cout << setprecision(0) << avg << endl;
                else
                    cout << setprecision(2) << avg << endl;
            }
        }
    }
}
void print_group_info(STUDENT students[], int count, bool isHuman) {
    GroupInfo groups[MAX_STUDENTS] = { {0, 0, 0} };
    int unique_groups = 0;

    for (int i = 0; i < count; i++) {
        bool found = false;
        for (int j = 0; j < unique_groups; j++) {
            if (groups[j].group_number == students[i].group_number) {
                groups[j].student_count++;
                for (int k = 0; k < GRADES_COUNT; k++) {
                    if (students[i].grades[k] == 2) {
                        groups[j].bad_count++; 
                        break;
                    }
                }
                found = true;
                break;
            }
        }
        if (!found) {
            groups[unique_groups].group_number = students[i].group_number;
            groups[unique_groups].student_count = 1;
            groups[unique_groups].bad_count = 0;
            for (int k = 0; k < GRADES_COUNT; k++) {
                if (students[i].grades[k] == 2) {
                    groups[unique_groups].bad_count = 1;
                    break;
                }
            }
            unique_groups++;
        }
    }


    for (int i = 0; i < unique_groups - 1; i++) {
        for (int j = i + 1; j < unique_groups; j++) {
            if (groups[i].bad_count < groups[j].bad_count) {
                swap(groups[i], groups[j]);
            }
        }
    }

    if (isHuman) {
        cout << "______________________________________________________" << endl;
        cout << "| Номер группы | Кол-во студентов | Кол-во без двоек |" << endl;
        cout << "|______________|__________________|__________________|" << endl;

        for (int i = 0; i < unique_groups; i++) {
            cout << "|";
            print(4, " ");
            cout << groups[i].group_number; 
            print(4, " ");
            cout << "|         " << left << setw(9) << groups[i].student_count
                << "|         " << left << setw(9) << groups[i].bad_count << "|" << endl;
        }

        cout << "|______________|__________________|__________________|" << endl;
    }
    else {
        for (int i = 0; i < unique_groups; i++) {
            cout << groups[i].group_number << " - " << groups[i].student_count << " - " << groups[i].bad_count << endl;
        }
    }
}


int main(int argc, char* argv[]) {
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    int N{};
    int S{};

    if (isHuman) {
        cout << "Укажите количество студентов: ";
    }
    cin >> N;

    STUDENT* students = new STUDENT[N];


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

    delete[] students;

    return 0;
}