#include "Seller.h"
#pragma once
class Toy
{
private:
	int id;
	char name[50];
	char age—ategory[10];
	double price;
	Seller seller;
    int sellerId;
	bool sold;
public:
    void create();
    void showData();
    void read(int pn);
    void write();
    static int count();
    int search(int variant);
    void deleteData();
    void editData();
    int setId();
    bool getSold();
    int getSeller();
    void showSold();
    double getPrice();
};

