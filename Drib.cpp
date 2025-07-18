

#include <iostream>
#include <Windows.h>
using namespace std;

#include <iostream>
#include <Windows.h>
using namespace std;

#include <iostream>
#include <Windows.h>
using namespace std;

class Drib {
private:
    int number; 
    int ground; 

public:

    Drib() : number(0), ground(1) {}

    Drib(int num, int den) : number(num), ground(den == 0 ? 1 : den) {
        Simplify();
    }

    Drib(const Drib& d) : number(d.number), ground(d.ground) {}

    inline void Add() {
        cout << "Введіть знаменник: ";
        cin >> ground;
        if (ground == 0) {
            cout << "Знаменник не може бути нульовим. Встановлено 1.\n";
            ground = 1;
        }
        cout << "Введіть чисельник: ";
        cin >> number;
        Simplify();
    }

    inline void Show() const {
        cout << "Дріб: " << number << "/" << ground << endl;
    }

    inline int Even(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void Simplify() {
        int gcd_val = Even(abs(number), abs(ground));
        number /= gcd_val;
        ground /= gcd_val;
        if (ground < 0) {
            number = -number;
            ground = -ground;
        }
    }

    void Plus(const Drib& d) {
        number = number * d.ground + d.number * ground;
        ground = ground * d.ground;
        Simplify();
        Show();
    }

    void Minus(const Drib& d) {
        number = number * d.ground - d.number * ground;
        ground = ground * d.ground;
        Simplify();
        Show();
    }

    void Multiply(const Drib& d) {
        number *= d.number;
        ground *= d.ground;
        Simplify();
        Show();
    }

    void Divide(const Drib& d) {
        number *= d.ground;
        ground *= d.number;
        if (ground == 0) {
            cout << "Помилка: ділення на 0!" << endl;
            number = 0;
            ground = 1;
        }
        else {
            Simplify();
        }
        Show();
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Drib* d1 = new Drib;
    int a = 0;
    while(a!= 6) {
        cout << "1.ввести дріб" << endl;
        cout << "2.додати дроби" << endl;
        cout << "3.відняти дроби" << endl;
        cout << "4.помножити дроби" << endl;
        cout << "5.поділити дроби" << endl;
        cout << "6.вийти" << endl;
        cin >> a;
        switch (a) {
        case 1:
            d1->Add();
            d1->Show();
            break;
        case 2: {
            Drib* d2 = new Drib;
            d2->Add();
            d1->Plus(*d2);
            delete d2;
            break;
        }
        case 3: {
            Drib* d2 = new Drib;
            d2->Add();
            d1->Minus(*d2);
            delete d2;
            break;
        }
        case 4: {
            Drib* d2 = new Drib;
            d2->Add();
            d1->Multiply(*d2);
            delete d2;
            break;
        }
        case 5: {
            Drib* d2 = new Drib;
            d2->Add();
            d1->Divide(*d2);
            delete d2;
            break;
        }
        case 6: {
            break;
        }

        }
    }
        
    return 0;
}
