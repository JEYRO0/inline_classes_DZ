#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>

class Point {
private:
    int x, y, z;

public:
    Point() : x(0), y(0), z(0) {}

    Point(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal) {}

    inline void setX() {
        printf("Введіть координату X: ");
        scanf("%d", &x);
    }

    inline void setY() {
        printf("Введіть координату Y: ");
        scanf("%d", &y);
    }

    inline void setZ() {
        printf("Введіть координату Z: ");
        scanf("%d", &z);
    }
    inline int getX() const { return x; }
    inline int getY() const { return y; }
    inline int getZ() const { return z; }

    inline void Show() const {
        printf("Координати: X = %d, Y = %d, Z = %d\n", x, y, z);
    }

    void SaveToFile() const {
        FILE* file;
        file = fopen("coordinates.txt", "w");
        if (file != NULL) {
            fprintf(file, "Координати: X = %d, Y = %d, Z = %d\n", x, y, z);
            fclose(file);
            printf("Дані збережено в файл coordinates.txt\n");
        }
        else {
            printf("Помилка при відкритті файлу.\n");
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int a = 0;

    Point p(1, 2, 3);

    while (a != 6) {
        printf("Введіть свій вибір:\n");
        printf("1. Ввести координату X\n");
        printf("2. Ввести координату Y\n");
        printf("3. Ввести координату Z\n");
        printf("4. Вивести координати\n");
        printf("5. Збереження даних в файл\n");
        printf("6. Вийти\n");
        scanf("%d", &a);

        if (a == 1) {
            p.setX();
        }
        else if (a == 2) {
            p.setY();
        }
        else if (a == 3) {
            p.setZ();
        }
        else if (a == 4) {
            p.Show();
        }
        else if (a == 5) {
            p.SaveToFile();
        }
        else if (a == 6) {
            printf("Вихід з програми.\n");
            break;
        }
        else {
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    }
}
