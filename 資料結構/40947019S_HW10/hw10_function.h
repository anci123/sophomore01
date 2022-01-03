#pragma once
#include <iostream>
#include <string.h>
using namespace std;

struct node {
    node *leftchild;
    node *rightchild;
    char data;
    int value;
};

void print_choise();
void stack_init();
void push_node_1(char c);
void push_node_2(node N);
char pop_node_1();
node *pop_node_2(node *n);
node build_tree();
void postorder(node *ptr);
void preorder(node *ptr);
void inorder(node *ptr);
void addq(node *ptr);
node *deleteq();
void levelorder(node *ptr);
int postOrderEval(node *ptr);
