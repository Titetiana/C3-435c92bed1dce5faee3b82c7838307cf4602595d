#include "Seller.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Seller::getId()
{
    return id;
}

int Seller::getAge()
{
    int input;
    bool valid = false;
    do
    {
       

        cin >> input;
        if (cin.good())
        {
            valid = true;
            //return input;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка вводу. Введіть ще раз" << endl;
        }
    } while (!valid);
    return input;

}

int Seller::setId()
{
    int id;
    string str;
    fstream file;
    file.open("id.txt", fstream::out | fstream::in);
    ifstream temp;
    while (!file.eof())
    {
        getline(file, str);
        id = atoi(str.c_str());
    }
    ++id;
    file.close();
    file.open("id.txt", fstream::out | fstream::in);
    file << id;
    file.close();
    return id;
}

void Seller::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Вік: "; age=getAge();
    id = setId();
}

void Seller::showData()
{
    cout << "id: " << id << endl;
    cout << "Ім'я: " << name << endl;
    cout << "Прізвище: " << surname << endl;
    cout << "По батькові: " << patronymic << endl;
    cout << "Вік: " << age << endl << endl;
}

void Seller::read(int pn)
{
    ifstream ifile;
    ifile.open("Seller.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    ifile.seekg(pn * sizeof(Seller));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

void Seller::write()
{
    ofstream ofile;
    ofile.open("Seller.dat", ios::app | ios::binary | ios::out | ios::in);
    ofile.write((char*)this, sizeof(*this));
    ofile.close();
}

int Seller::count()
{
    ifstream ifile;
    ifile.open("Seller.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(Human);
    ifile.close();
}

int Seller::search(int variant)
{
    if (variant == 0)
        return 0;
    Seller seller;
    ifstream ifile;
    char str[40];
    ifile.open("Seller.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть дані для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Seller));
        ifile.read(reinterpret_cast<char*>(&seller), sizeof(Seller));

        switch (variant)
        {
        case 1:
            if (0 == strcmp(str, seller.name))
            {
                seller.showData();
            }
            break;

        case 2:
            if (0 == strcmp(str, seller.surname))
            {
                seller.showData();
            }
            break;
        case 3:
            if (0 == strcmp(str, seller.patronymic))
            {
                seller.showData();
            }
            break;
        case 4:
            if (atoi(str) == seller.age)
            {
                seller.showData();
            }
            break;
        case 5:
            if (atoi(str) == seller.id)
            {
                seller.showData();
            }
            break;
        }
    }
    ifile.close();
}



void Seller::deleteData()
{
    Seller seller;
    int str;
    cout << "Введіть номер документа для видалення: ";
    cin >> str;
    ifstream file;
    file.open("Seller.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.read(reinterpret_cast<char*>(&seller), sizeof(Seller));
    while (!file.eof())
    {

        if (seller.id != str)
        {
            temp.write(reinterpret_cast<char*>(&seller), sizeof(Seller));
        }

        else
        {
            cout << "\nЗапис видалено\n";
        }
        file.read(reinterpret_cast<char*>(&seller), sizeof(Seller));
    }
    temp.close();
    file.close();
    if (remove("Seller.dat") != 0)
    {
        cout << "file do not remove";
    }
    if (rename("temp.dat", "Seller.dat") != 0)
    {
        cout << "file do not rename";
    }
}

void Seller::editData()
{
    Seller seller;
    int str;
    cout << "Введіть номер документа для редагування: ";
    cin >> str;
    ifstream file;
    file.open("Seller.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&seller), sizeof(Seller));
    while (!file.eof())
    {

        if (seller.id != str)
        {
            temp.write(reinterpret_cast<char*>(&seller), sizeof(Seller));
        }

        else
        {
            seller.create();
            temp.write(reinterpret_cast<char*>(&seller), sizeof(Seller));
        }
        file.read(reinterpret_cast<char*>(&seller), sizeof(Seller));
    }
    temp.close();
    file.close();
    if (remove("Seller.dat") != 0)
    {
        cout << "file do not remove";
    }
    if (rename("temp.dat", "Seller.dat") != 0)
    {
        cout << "file do not rename";
    }
}