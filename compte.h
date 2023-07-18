#ifndef COMPTE
#define COMPTE
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "compte.h"


struct date{
    int day,month,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

void menu();
void close();
void attente(double j);
void new_acc();
void view_list();
void edit(void);
void transact(void);
void erase(void);
void see(void);





#endif