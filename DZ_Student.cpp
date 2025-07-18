#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string surname;
    string fatherName;

    unsigned mark1 : 1;
    unsigned mark2 : 1;
    unsigned mark3 : 1;
    unsigned mark4 : 1;
    unsigned mark5 : 1;
    unsigned mark6 : 1;
    unsigned mark7 : 1;
    unsigned mark8 : 1;
    unsigned mark9 : 1;
    unsigned mark10 : 1;

public:
    Student() : name(""), surname(""), fatherName(""),
        mark1(0), mark2(0), mark3(0), mark4(0), mark5(0),
        mark6(0), mark7(0), mark8(0), mark9(0), mark10(0) {
    }

    Student(string n, string s, string f) : name(n), surname(s), fatherName(f),
        mark1(0), mark2(0), mark3(0), mark4(0), mark5(0),
        mark6(0), mark7(0), mark8(0), mark9(0), mark10(0) {
    }

    Student(const Student& other) = default;
    ~Student() = default;

    void Fill() {
        cout << "\nВведіть ім'я: ";
        cin >> name;

        cout << "Введіть прізвище: ";
        cin >> surname;

        cout << "Введіть по батькові: ";
        cin >> fatherName;

        for (int i = 1; i <= 10; ++i) {
            int mark;
            do {
                cout << "Введіть оцінку " << i << " (1 - склав, 0 - не склав): ";
                cin >> mark;
            } while (mark != 0 && mark != 1);
            SetMark(i, mark);
        }
    }

    inline void SetMark(int index, int value) {
        if (index == 1) mark1 = value;
        else if (index == 2) mark2 = value;
        else if (index == 3) mark3 = value;
        else if (index == 4) mark4 = value;
        else if (index == 5) mark5 = value;
        else if (index == 6) mark6 = value;
        else if (index == 7) mark7 = value;
        else if (index == 8) mark8 = value;
        else if (index == 9) mark9 = value;
        else if (index == 10) mark10 = value;
    }

    inline int GetMark(int index) const {
        if (index == 1) return mark1;
        else if (index == 2) return mark2;
        else if (index == 3) return mark3;
        else if (index == 4) return mark4;
        else if (index == 5) return mark5;
        else if (index == 6) return mark6;
        else if (index == 7) return mark7;
        else if (index == 8) return mark8;
        else if (index == 9) return mark9;
        else if (index == 10) return mark10;
        return 0;
    }

    void Print() const {
        cout << "Студент: " << surname << " " << name << " " << fatherName << endl;
        cout << "Оцінки: ";
        for (int i = 1; i <= 10; i++) cout << GetMark(i) << " ";
        cout << endl;
    }

    double Average() const {
        int sum = 0;
        for (int i = 1; i <= 10; i++) sum += GetMark(i);
        return sum / 10.0;
    }
};

Student** AddStudent(Student** arr, int& size) {
    Student** newArr = new Student * [size + 1];
    for (int i = 0; i < size; i++) newArr[i] = arr[i];
    newArr[size] = new Student();
    newArr[size]->Fill();
    delete[] arr;
    ++size;
    return newArr;
}

void PrintAll(Student** arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nСтудент " << i + 1 << ":" << endl;
        arr[i]->Print();
        cout << "Середній бал: " << arr[i]->Average() << endl;
    }
}

void PrintDebtors(Student** arr, int size) {
    bool found = false;
    cout << "\nБоржники:" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i]->Average() < 0.5) {
            found = true;
            arr[i]->Print();
        }
    }
    if (!found) cout << "Боржників немає." << endl;
}

void PrintMarks(Student* s) {
    s->Print();
    cout << "Середній бал: " << s->Average() << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student** students = nullptr;
    int size = 0;
    int choice = 0;

    while (choice != 6) {
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Проставити оцінки студенту\n";
        cout << "3. Вивести список студентів\n";
        cout << "4. Вивести боржників\n";
        cout << "5. Вивести оцінки студента\n";
        cout << "6. Вийти\n";

        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            students = AddStudent(students, size);
        }
        else if (choice == 2) {
            if (size == 0) {
                cout << "Список порожній\n";
            }
            else {
                int num;
                cout << "Номер студента (1 - " << size << "): ";
                cin >> num;
                if (num < 1 || num > size) {
                    cout << "Некоректний номер\n";
                }
                else {
                    students[num - 1]->Fill();
                }
            }
        }
        else if (choice == 3) {
            if (size == 0) cout << "Список порожній\n";
            else PrintAll(students, size);
        }
        else if (choice == 4) {
            if (size == 0) cout << "Список порожній\n";
            else PrintDebtors(students, size);
        }
        else if (choice == 5) {
            if (size == 0) {
                cout << "Список порожній\n";
            }
            else {
                int num;
                cout << "Номер студента (1 - " << size << "): ";
                cin >> num;
                if (num < 1 || num > size) {
                    cout << "Некоректний номер\n";
                }
                else {
                    PrintMarks(students[num - 1]);
                }
            }
        }
        else {
            cout << "Невідомий вибір. Спробуйте ще.\n";
        }
    }

    for (int i = 0; i < size; i++) delete students[i];
    delete[] students;
    return 0;
}
