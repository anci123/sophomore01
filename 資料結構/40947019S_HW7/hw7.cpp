#include"hw7_function.h"
int main() {
    int choose;
    card_init();
    while(1) {
        print_choise();
        cin >> choose;
        print_line();
        switch (choose) {
        case 1:
            give_card();
            break;
        case 2:
            print_in_order();
            break;
        case 3:
            print_in_opposite_order();
            break;
        case 4:
            function_4();
            break;
        case 5:
            delete_one();
            break;
        case 6:
            give_card();
            break;
        case 7:
            delete_continue();
            break;
        default:
            break;
        }
    }
    return 0;
}