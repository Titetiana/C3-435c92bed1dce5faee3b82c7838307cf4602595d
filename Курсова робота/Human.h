#pragma once
class Human
{
protected:
    char name[40];
    char surname[40];
    char patronymic[40];
    int age;
public:
    virtual void create();
    virtual void showData();
};

