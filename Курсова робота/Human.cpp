#include "Human.h"
#include <iostream>
using namespace std;
void Human::create()
{
    cin.ignore(10, '\n');
    cout << "\n��'�: "; cin >> name;
    cout << "�������: "; cin >> surname;
    cout << "�� �������: "; cin >> patronymic;
    cout << "³�: "; cin >> age;
}

void Human::showData()
{
    cout << "��'�: " << name << endl;
    cout << "�������: " << surname << endl;
    cout << "�� �������: " << patronymic << endl;
    cout << "³�: " << age << endl;
}