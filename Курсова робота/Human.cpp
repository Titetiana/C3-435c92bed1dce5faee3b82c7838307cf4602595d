#include "Human.h"
#include <iostream>
using namespace std;
void Human::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Вік: "; cin >> age;
}

void Human::showData()
{
    cout << "Ім'я: " << name << endl;
    cout << "Прізвище: " << surname << endl;
    cout << "По батькові: " << patronymic << endl;
    cout << "Вік: " << age << endl;
}