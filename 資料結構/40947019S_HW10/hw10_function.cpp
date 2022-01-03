#include"hw10_function.h"
char stack_1[100];
node stack_2[100];
int index_1 = 0;
int index_2 = 0;
void print_choise() {
    cout << "-------------------------------------------------------\n";
    cout << "(1) 輸入一串 infix 運算式，並輸出其 postfix 運算式\n";
    cout << "(2) 輸出對應 prefix 運算式\n";
    cout << "(3) 輸出對應二元運算樹之 level order 走訪順序" << endl;
    cout << "(4) 給定不同變數對應之整數，輸出運算式計算結果" << endl;
    cout << "(5) 離開" << endl;
}
void stack_init() {
    memset(stack_1, 0, sizeof(stack_1));
    memset(stack_2, 0, sizeof(stack_2));
    index_1 = 0;
    index_2 = 0;
}
node creat_node(char c) {
    node *N = (node*)calloc(1, sizeof(node));
    N->data = c;
    N->leftchild = NULL;
    N->rightchild = NULL;
    return *N;
}
void push_node_1(char c) {
    stack_1[index_1] = c;
    ++index_1;
}
void push_node_2(node N) {
    stack_2[index_2] = N;
    ++index_2;
}
char pop_node_1() {
    index_1--;
    char c = stack_1[index_1];
    stack_1[index_1] = 0;
    return c;
}
node *pop_node_2(node *n) {
    index_2--;
    node *N = (node*)calloc(1, sizeof(node));
    N->data = stack_2[index_2].data;
    N->leftchild = stack_2[index_2].leftchild;
    N->rightchild = stack_2[index_2].rightchild;
    n = N;
    return N;
}
node build_tree() {
    cout << "輸入一個運算式:" << endl;
    string str;
    cin >> str;
    node N;
    node *child;
    stack_init();
    int parenthese = 0;
    int num_ope = 0;
    bool parenth = true;
    bool operands = true;
    for(int i = 0; i < str.length(); ++i) {
        char c = str[i];
        int s = 0;
        if(c == '(') ++parenthese;
        else if(c == ')') --parenthese;
        if(parenthese < 0) {
            parenth = false;
            break;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/') --num_ope;
        if(c <= 'Z' && c >= 'A') {
            s = 1;
            ++num_ope;
        }
        else if(c == '+' || c == '-' || c == '(') s = 2;
        else if(c == '*' || c == '/') s = 3;
        else if(c == ')') s = 4;
        switch (s) {
        case 1: {
            N = creat_node(c);
            push_node_2(N);
        }
        break;

        case 2: {
            //cout<<index_2<<endl;
            if(stack_1[index_1]=='(' || (index_1 > 0 && (stack_1[index_1 - 1] != '*' && stack_1[index_1 - 1] != '/'))) push_node_1(c);
            else if(index_2 > 1) {
                char t = pop_node_1();
                N = creat_node(t);
                N.rightchild = pop_node_2(N.rightchild);
                N.leftchild = pop_node_2(N.leftchild);
                push_node_2(N);
                push_node_1(c);
            }
            else push_node_1(c);
            //cout<<stack_2[index_2-1].data<<endl;
            //cout<<stack_1[index_1-1]<<endl;
        }
        break;

        case 3:
            push_node_1(c);
            break;

        case 4: {
            //cout<<index_2<<endl;
            while(c != '(' && index_2 > 1) {
                char ch = pop_node_1();
                while(ch == '(') ch = pop_node_1();
                N = creat_node(ch);
                N.rightchild = pop_node_2(N.rightchild);
                N.leftchild = pop_node_2(N.leftchild);
                //cout << N.leftchild->data << endl;
                push_node_2(N);
            }
            char off = pop_node_1();
        }
        break;

        default:
            break;
        }
        //cout << c << endl;
        //if(index_2 > 0)cout << "S:" << stack_2[index_2 - 1].data << endl;
    }
    while(index_1 > 0) {
        char c = pop_node_1();
        N = creat_node(c);
        N.rightchild = pop_node_2(N.rightchild);
        N.leftchild = pop_node_2(N.leftchild);
        //cout << "LH:" << child->leftchild->data << endl;
        push_node_2(N);
    }
    //cout << stack_2[index_2-1].data << endl;
    //N = pop_node_2();
    pop_node_2(&N);
    //cout << N.data << endl;
    //cout << N.leftchild->leftchild->data << endl;
    if(parenthese != 0) parenth = false;
    if(num_ope != 1) operands = false;
    if(parenth && operands) {
        cout << "The postfix expression: ";
        postorder(&N);
        cout << endl;

    }
    if(!parenth) cout << "左右括弧不對稱" << endl;
    if(!operands) cout << "運算子數目不等於運算元數目+1" << endl;
    return N;
}

void postorder(node *ptr) {
    if(ptr) {
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->data;
    }
}
void preorder(node *ptr) {
    if(ptr) {
        cout << ptr->data;
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
}
node *node_queue[100];
int queue_rear = 0;
int queue_front = 0;
void addq(node *ptr) {
    node_queue[queue_rear] = ptr;
    queue_rear++;
}
node *deleteq() {
    node *N = node_queue[queue_front];
    //memset(&node_queue[queue_front],0,sizeof(node));
    queue_front++;
    return N;
}
void levelorder(node *ptr) {
    memset(node_queue, 0, sizeof(node_queue));
    queue_rear = queue_front = 0;
    if(!ptr) return;
    addq(ptr);
    while(true) {
        ptr = deleteq();
        if(ptr) {
            //cout<<ptr;
            cout << ptr->data;
            if(ptr->leftchild) addq(ptr->leftchild);
            if(ptr->rightchild) addq(ptr->rightchild);
        }
        else break;
    }
}
int postOrderEval(node *ptr) {
    int value;
    if(ptr) {
        postOrderEval(ptr->leftchild);
        postOrderEval(ptr->rightchild);
        char c = ptr->data;
        if(c <= 'Z' && c >= 'A') {
            int val = 0;
            cout << "請指定整數" << endl;
            cout << c << ": ";
            cin >> val;
            ptr->value = val;
        }
        switch (c) {
        case '+':
            ptr->value = ptr->leftchild->value + ptr->rightchild->value;
            break;
        case '-':
            ptr->value = ptr->leftchild->value - ptr->rightchild->value;
            break;
        case '*':
            ptr->value = ptr->leftchild->value * ptr->rightchild->value;
            break;
        case '/':
            ptr->value = ptr->leftchild->value / ptr->rightchild->value;
            break;
        default:
            break;
        }
        value = ptr->value;
        //cout<<ptr->data<<" : ";
        //cout<<value<<endl;
    }
    return value;
}
