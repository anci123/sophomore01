#pragma once
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
struct card{
    int suit;
    int num;
};
struct Info{
    int num;
    Info *next;
    Info *pre;
};
struct holder{
    int num_of_card;
    Info *card_head[4];
    Info *card_rear[4];
};

void card_init();
void print_choise();
void print_line();
void give_card();
int suit_to_num(char suit);
int choose_a_person();
void print_card(Info *card,int suit);
void print_in_order();
void print_in_opposite_order();
void function_4();
void print_all_card(int person_index);
int str_to_num(string n);
void input_card(int *suit, int *num);
card delete_card(int person_index,int suit,int num);
void delete_one();
void delete_continue();