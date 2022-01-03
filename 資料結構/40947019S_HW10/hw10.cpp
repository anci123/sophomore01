#include"hw10_function.h"
int main() {
    char c;
    while(true) {
        print_choise();
        int c;
        cin >> c;
        node *head;
        int value;
        switch (c) {
        case 1: {
            node n = build_tree();
            node *tree = &n;
            head = tree;
        }
        break;
        case 2:
            cout << "The prefix of expression tree: ";
            preorder(head);
            cout << endl;
            break;
        case 3:
            cout << "The level-order of expression tree: ";
            levelorder(head);
            cout << endl;
            break;
        case 4:
            value=postOrderEval(head);
            cout<<"計算結果: ";
            cout<<value<<endl;;
            break;
        case 5:
            goto end;
        default:
            break;
        }

        int ch = getchar();
        if(ch == 27)
            break;

    }
end:
    return 0;
}

