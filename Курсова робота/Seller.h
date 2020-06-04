#pragma once
#include "Human.h"
class Seller : public Human
{
protected:
	int id;
	double salary;
public:
    virtual void create() override;
    virtual void showData() override;
    void read(int pn);
    void write();
    static int count();
    int search(int variant);
    void deleteData();
    void editData();
    int setId();
    int getId();
    int getAge();
};

