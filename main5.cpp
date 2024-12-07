#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
using namespace std;

const int MAX_STUDENTS = 100;
const int GRADES_COUNT = 5;

struct STUDENT {
    char name[100];
    int group_number;
    int grades[GRADES_COUNT];
};



void print_student_info(STUDENT students[], int count) {

    cout << "________________________________________________________________________________" << endl;
    cout << "| Группа             | ФИО                          | Оценки                   |" << endl;
    cout << "|____________________|______________________________|__________________________|" << endl;

    for (int i = 0; i < count; i++) {
        cout << "| " << left << setw(19) << students[i].group_number << "| " << left << setw(29) << students[i].name << setw(3) << "| ";
        for (int j = 0; j < GRADES_COUNT; j++) {
            cout << students[i].grades[j];
            if (j < GRADES_COUNT - 1) cout << ",";
        }
        cout << string(25 - (2 * GRADES_COUNT), ' ');
        cout << "|" << endl;
        cout << "|____________________|______________________________|__________________________|" << endl;
    }
}


float calculate_average(int grades[]) {
    float sum = 0;
    for (int i = 0; i < GRADES_COUNT; i++) {
        sum += grades[i];
    }
    return sum / GRADES_COUNT;
}

void sort_students_by_average(STUDENT students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (calculate_average(students[j].grades) < calculate_average(students[j + 1].grades)) {
                STUDENT temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students_above_average(STUDENT students[], int count) {
    sort_students_by_average(students, count);

    bool found = false;

    // Заголовок таблицы
    cout << "_____________________________________________________________________" << endl;
    cout << "| Номер группы  |              Имя           |     Средний балл     |" << endl;
    cout << "|_______________|____________________________|______________________|" << endl; 


    for (int i = 0; i < count; i++) {
        float avg = calculate_average(students[i].grades);
        if (avg > 4.0) {
            cout << "| " << setw(13) << students[i].group_number << " |"
                << setw(27) << students[i].name << " |"
                << fixed << setprecision(1) << avg << "                   |" << endl;

            found = true;
        }
    }

    cout << "|_______________|____________________________|______________________|"<< endl; 
}
void print_group_info(STUDENT students[], int count) {
    int group_count[MAX_STUDENTS] = { 0 };
    int bad_count[MAX_STUDENTS] = { 0 };
    int group_numbers[MAX_STUDENTS];

    int unique_groups = 0;

    for (int i = 0; i < count; i++) {
        bool found = false;
        for (int j = 0; j < unique_groups; j++) {
            if (group_numbers[j] == students[i].group_number) {
                group_count[j]++;
                if (students[i].grades[0] == 2 && students[i].grades[1] == 2 &&
                    students[i].grades[2] == 2 && students[i].grades[3] == 2 &&
                    students[i].grades[4] == 2) {
                    bad_count[j]++;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            group_numbers[unique_groups] = students[i].group_number;
            group_count[unique_groups] = 1;
            bad_count[unique_groups] = (students[i].grades[0] == 2 && students[i].grades[1] == 2 &&
                students[i].grades[2] == 2 && students[i].grades[3] == 2 &&
                students[i].grades[4] == 2) ? 1 : 0;
            unique_groups++;
        }
    }
for (int i = 0; i < unique_groups - 1; i++) {
        for (int j = i + 1; j < unique_groups; j++) {
            if (bad_count[i] < bad_count[j]) {
                swap(group_numbers[i], group_numbers[j]);
                swap(group_count[i], group_count[j]);
                swap(bad_count[i], bad_count[j]);
            }
        }
    }

    cout << "_______________________________________________________" << endl;
    cout << "| Номер группы  | кол-во студентов | кол-во без двоек |" << endl;
    cout << "|_______________|__________________|__________________|" << endl;

    for (int i = 0; i < unique_groups; i++) {
        cout << "| " << left << setw(14) << group_numbers[i]
            << "| " << left << setw(17) << group_count[i]
            << "| " << left << setw(17) << bad_count[i] << "|" << endl;
    }

    cout << "|_______________|__________________|__________________|" << endl;
}

int main(int argc, char* argv[])
{
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    STUDENT students[MAX_STUDENTS];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin.ignore();
        cin.getline(students[i].name, sizeof(students[i].name));
        cin >> students[i].group_number;
        for (int j = 0; j < GRADES_COUNT; j++) {
            cin >> students[i].grades[j];
        }
    }

    if (isHuman) print_student_info(students, N);

    print_students_above_average(students, N);


    print_group_info(students, N);

    return 0;
}