#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAX 10000
typedef struct {
    string name;
    float coef[MAX];
} polynomial;
void init(polynomial *p);
void output(polynomial p);
void input(polynomial *p);
bool pAttach(polynomial *p);
void pRemove(polynomial *p);
void pAdd(polynomial p1, polynomial p2,polynomial *ans);
void pMinus(polynomial p1, polynomial p2,polynomial *ans);
void pMult(polynomial p1, polynomial p2,polynomial *ans);
void pDivid(polynomial p1, polynomial p2,polynomial *ans);
int printMenu(int c);
int printChoose(int pCount);
static int (*choose_ptr)(int) = printChoose;

