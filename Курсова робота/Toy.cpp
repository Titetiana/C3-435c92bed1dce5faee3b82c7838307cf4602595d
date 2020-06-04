#include "Toy.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Toy::showSold()
{
    if (sold == true)
        cout << "���\n";
    else cout << "�\n";
}

double Toy::getPrice()
{
    double input;
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
            cout << "������� �����. ������ �� ���" << endl;
        }
    } while (!valid);
    return input;

}

int Toy::setId()
{
    int id;
    string str;
    fstream file;
    file.open("ToyId.txt", fstream::out | fstream::in);
    ifstream temp;
    while (!file.eof())
    {
        getline(file, str);
        id = atoi(str.c_str());
    }
    ++id;
    file.close();
    file.open("ToyId.txt", fstream::out | fstream::in);
    file << id;
    file.close();
    return id;
}

void Toy::create()
{
    cin.ignore(10, '\n');
    cout << "\n��'�: "; cin >> name;
    cout << "³���� ��������: "; cin >> age�ategory;
    cout << "ֳ��: "; price = getPrice();
    cout << "�������(�/�): "; sold = getSold();
    if (sold == 1)
    {
       sellerId = getSeller();
    }
    id = setId();
}

void Toy::showData()
{
    cout << "id: " << id << endl;
    cout << "�����: " << name << endl;
    cout << "³���� ��������: " << age�ategory << endl;
    cout << "����: " << price << endl;
    cout << "�������: "; showSold();
    if (sold == true)
    {
        cout << "id �������� �� ������: " << sellerId;
    }
    
}

void Toy::read(int pn)
{
    ifstream ifile;
    ifile.open("Toy.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    ifile.seekg(pn * sizeof(Toy));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

void Toy::write()
{
    ofstream ofile;
    ofile.open("Toy.dat", ios::app | ios::binary | ios::out | ios::in);
    ofile.write((char*)this, sizeof(*this));
    ofile.close();
}

int Toy::count()
{
    ifstream ifile;
    ifile.open("Toy.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(Toy);
    ifile.close();
}

bool Toy::getSold()
{
    char ch;
    cin >> ch;
    if (ch == '�')
        return true;
}

int Toy::getSeller()
{

    Seller seller;
    ifstream ifile;
    int id;
    ifile.open("Seller.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    int ok = 0;
    int n;
    while (ok != 1)
    {
        cout << "������ id ����������: ";
        cin >> id;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(Seller));
            ifile.read(reinterpret_cast<char*>(&seller), sizeof(Seller));
            n = seller.getId();
            if (id == n)
            {
                ok = 1;
                return seller.getId();
            }
        }
        cout << "\n���������� � ����� id ����. ������ �� ���\n";
    }
    


}

int Toy::search(int variant)
{
    if (variant == 0)
        return 0;
    Toy toy;
    ifstream ifile;
    char str[40];
    ifile.open("Toy.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "������ ��� ��� ������: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Toy));
        ifile.read(reinterpret_cast<char*>(&toy), sizeof(Toy));

        switch (variant)
        {
        case 1:
            if (0 == strcmp(str, toy.name))
            {
                toy.showData();
            }
            break;

        case 2:
            if (0 == strcmp(str, toy.age�ategory))
            {
                toy.showData();
            }
            break;
        case 3:
            if (atoi(str) == toy.price)
            {
                toy.showData();
            }
            break;
        case 4:
            if (atoi(str) == toy.id)
            {
                toy.showData();
            }
            break;
        case 5:
            if (atoi(str) == toy.sellerId)
            {
                toy.showData();
            }
            break;
            case 6:

                if (atoi(str) == toy.sold)
                {
                    seller.showData();
                }
                break;
            //case 7:
            //    if (0 == strcmp(str, seller.dateOfExpiry))
            //    {
            //        seller.showData();
            //    }
            //    break;
        default:
            cout << "������� �����. ������ �� ���\n";
            break;
        }
    }
    ifile.close();
}



void Toy::deleteData()
{
    Toy toy;
    int str;
    cout << "������ ����� ��������� ��� ���������: ";
    cin >> str;
    ifstream file;
    file.open("Toy.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.read(reinterpret_cast<char*>(&toy), sizeof(Toy));
    while (!file.eof())
    {

        if (toy.id != str)
        {
            temp.write(reinterpret_cast<char*>(&toy), sizeof(Toy));
        }

        else
        {
            cout << "\n����� ��������\n";
        }
        file.read(reinterpret_cast<char*>(&toy), sizeof(Toy));
    }
    temp.close();
    file.close();
    if (remove("Toy.dat") != 0)
    {
        cout << "file do not remove";
    }
    if (rename("temp.dat", "Toy.dat") != 0)
    {
        cout << "file do not rename";
    }
}

void Toy::editData()
{
    Toy toy;
    int str;
    cout << "������ ����� ��������� ��� �����������: ";
    cin >> str;
    ifstream file;
    file.open("Toy.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&toy), sizeof(Toy));
    while (!file.eof())
    {

        if (toy.id != str)
        {
            temp.write(reinterpret_cast<char*>(&toy), sizeof(Toy));
        }

        else
        {
            toy.create();
            temp.write(reinterpret_cast<char*>(&toy), sizeof(Toy));
        }
        file.read(reinterpret_cast<char*>(&toy), sizeof(Toy));
    }
    temp.close();
    file.close();
    if (remove("Toy.dat") != 0)
    {
        cout << "file do not remove";
    }
    if (rename("temp.dat", "Toy.dat") != 0)
    {
        cout << "file do not rename";
    }
}