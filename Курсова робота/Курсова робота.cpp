#include "Toy.h"
#include "Seller.h"
#include <iostream>
using namespace std;

void print_Toy_menu()
{
    system("cls");
    cout << "         Іграшки\n" << endl;
    cout << "1.  Додати іграшку" << endl;
    cout << "2.  Переглянути іграшки" << endl;
    cout << "3.  Пошук іграшок" << endl;
    cout << "4.  Редагування іграшки" << endl;
    cout << "5.  Видалення іграшки" << endl;
    cout << "6. Вихід" << endl;
    cout << ">";
}

void print_Seller_menu()
{
    system("cls");
    cout << "         Продавці\n" << endl;
    cout << "1.  Додати продавця" << endl;
    cout << "2.  Переглянути продавців" << endl;
    cout << "3.  Пошук продавця" << endl;
    cout << "4.  Редагування продаця" << endl;
    cout << "5.  Видалення продавця" << endl;
    cout << "6. Вихід" << endl;
    cout << ">";
}

void print_menu() {
    system("cls");
    cout << "          Магазин іграшок\n" << endl;
    cout << "1.  Іграшки" << endl;
    cout << "2.  Продавці" << endl;
    cout << "3. Вихід" << endl;
    cout << ">";
}

void printSearchSellerMenu()
{
    cout << "Пошук за полем: \n";
    cout << "1. Ім'я" << endl;
    cout << "2. Прізвище" << endl;
    cout << "3. По батькові" << endl;
    cout << "4. Вік" << endl;
    cout << "5. id" << endl;
}
void printSearchToyMenu()
{
    cout << "Пошук за полем: \n";
    cout << "1. Назва" << endl;
    cout << "2. Вікова категорія" << endl;
    cout << "3. Ціна" << endl;
    cout << "4. id" << endl;
    cout << "5. id працівника" << endl;
    cout << "6. Продано" << endl;
}
int get_variant(int max) {
    double input = -1;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            valid = true;
            if (input > 0 && input <= max)
                return input;
            else
            {
                valid = false;
                cout << "Помилка вводу. Введіть ще раз" << endl;
            }

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

int main()
{
    system("chcp 1251>nul");
    int variant;
    string str;
    Toy toy;
    int n;
    Seller seller;
    do {

        print_menu();
        char ch;
        variant = get_variant(3);
        switch (variant) 
        {
            case 1:
                do {
                    print_Toy_menu();
                    variant = get_variant(6);
                    switch (variant) 
                    {
                    case 1:
                        do
                        {
                            cout << "Введіть дані іграшки: ";
                            toy.create();
                            toy.write();
                            cout << "Продовжити ввід?(т/н)?";
                            cin.ignore();
                            cin >> ch;
                        } while (ch == 'т');
                        break;

                    case 2:
                        n = Toy::count();
                        cout << "У файлі " << n << " іграшок\n";
                        for (int j = 1; j < n + 1; j++)
                        {
                            cout << "\n Іграшка " << j << endl;
                            toy.read(j - 1);
                            toy.showData();
                            cout << endl;
                        }
                        cout << endl;
                        break;
                    case 3:
                        do
                        {
                            printSearchToyMenu();
                            variant = get_variant(6);
                            toy.search(variant);
                            break;
                            system("pause");
                        } while (variant != 6);
                        break;
                    case 4:
                        toy.editData();
                        break;
                    case 5:
                        toy.deleteData();
                        break;
                    }
                    if (variant != 6)
                        system("pause");
                } while (variant != 6);
                break;

            case 2:
                do {
                    print_Seller_menu();
                    variant = get_variant(6);
                    switch (variant)
                    {
                    case 1:
                        do
                        {
                            cout << "Введіть дані продавця: ";
                            seller.create();
                            seller.write();
                            cout << "Продовжити ввід?(т/н)?";
                            cin >> ch;
                        } while (ch == 'т');
                        break;

                    case 2:
                        n = Seller::count();
                        cout << "У файлі " << n << " продавців\n";
                        for (int j = 1; j < n + 1; j++)
                        {
                            cout << "\n Продавець " << j << endl;
                            seller.read(j - 1);
                            seller.showData();
                            cout << endl;
                        }
                        cout << endl;
                        break;
                    case 3:
                        do
                        {
                            printSearchSellerMenu();
                            variant = get_variant(5);
                            seller.search(variant);
                            break;
                            system("pause");
                        } while (variant != 5);
                        break;
                    case 4:
                        seller.editData();
                        break;
                    case 5:
                        seller.deleteData();
                        break;
                    }
                    if (variant != 6)
                        system("pause");
                } while (variant != 6);
                break;
        }
        if (variant != 3)
            system("pause");
    } while (variant != 3);
    return 0;
}