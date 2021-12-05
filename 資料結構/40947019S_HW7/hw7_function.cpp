#include"hw7_function.h"

card card_set[52];
int card_index;
int number_of_person;
holder *person[10];
void card_init() {
    srand(time(0));
    card_index = 0;
    number_of_person = 0;
    bool fill[52] = {false};
    for(int i = 1; i <= 52; ++i) {
        while(1) {
            int index = rand() % 52;
            if(!fill[index]) {
                card_set[index].suit = (i - 1) / 13;
                int num = (i - 1) % 13;
                if(num == 0) num = 13;
                card_set[index].num = num;
                fill[index] = true;
                break;
            }
        }
    }
}
void print_choise() {
    print_line();
    cout << "1) 輸入一個正整數 n，隨機產生 n 張牌加到資料中，表示發給這個人 n 張牌。\n";
    cout << "2) 選擇某一花色，依發牌拿到的順序一一列出。\n3) 選擇某一花色，依發牌拿到的相反順序一一列出。\n";
    cout << "4) 選擇某一花色，依牌色大小由小而大一一列出。\n";
    cout << "5) 刪除一張牌: 根據一個輸入牌的花色及大小，從該花色中找到比該牌大的牌中最小的一張牌輸出並刪除。\n";
    cout << "6) 輸入並記錄另一個人的牌。\n";
    if(number_of_person >= 2)
        cout << "7) 全場輪流出牌，直到有人出完為止。" << endl;
}
void print_line() {
    cout << "\n-------------------------------------\n";
}
void give_card() {
    int n = 0;
    int suit = 0;
    person[number_of_person] = (holder*)calloc(1, sizeof(holder));
    for(int i = 0; i < 4; ++i) {
        person[number_of_person]->card_head[i] = (Info*)calloc(1, sizeof(Info));
        person[number_of_person]->card_head[i]->num = -1;
        person[number_of_person]->card_head[i]->next = NULL;
        person[number_of_person]->card_head[i]->pre = NULL;
        person[number_of_person]->card_rear[i] = NULL;
    }
    cout << "輸入正整數 n : " << endl;
    cin >> n;
    person[number_of_person]->num_of_card = 0;
    cout << "玩家 " << number_of_person + 1 << endl;
    cout << "手牌 :" << endl;
    while(n--) {
        if(card_index >= 52) {
            cout << "牌堆中的牌已發完" << endl;
            break;
        }
        Info *next_c = (Info*)calloc(1, sizeof(Info));
        suit = card_set[card_index].suit;
        Info *head = person[number_of_person]->card_head[suit];
        while(head->next != NULL) head = head->next;
        next_c->num = card_set[card_index].num;
        next_c->next = NULL;
        next_c->pre = head;
        head->next = next_c;
        person[number_of_person]->card_rear[suit] = next_c;
        //cout<<person[number_of_person]->card_head[suit]->next->num<<endl;
        //cout<<suit<<" "<<card_set[card_index].num+1<<endl;
        //cout<<person[number_of_person]->card_head[suit]->next->num<<endl;
        print_card(next_c, suit);
        ++card_index;
        ++person[number_of_person]->num_of_card;
        //free(next_c);
    }
    //person[number_of_person] = temp;
    /*if(person[number_of_person]->card_head[suit]->next != NULL)
        cout << person[number_of_person]->card_head[suit]->next->num << endl;
    else cout << "NULL" << endl;*/
    ++number_of_person;
    //free(temp);
}
int suit_to_num(char suit) {
    int num;
    if(suit == 'C' || suit == 'c') num = 0;
    else if(suit == 'D' || suit == 'd') num = 1;
    else if(suit == 'H' || suit == 'h') num = 2;
    else if(suit == 'S' || suit == 's') num = 3;
    return num;
}

int choose_a_person() {
    int choose;
    cout << "選擇一位開始操作(1 to ";
    cout << number_of_person;
    cout << ")" << endl;
    cin >> choose;
    return --choose;
}
void print_card(Info *card, int suit) {
    int num = card->num;
    if(suit == 0) cout << 'C';
    else if(suit == 1) cout << 'D';
    else if(suit == 2) cout << 'H';
    else if(suit == 3) cout << 'S';
    if(num == 13) cout << 'A' << endl;
    else cout << num + 1 << endl;
}
void print_in_order() {
    int person_index = choose_a_person();
    char s;
    cout << "輸入花色(C,D,H,S): " << endl;
    cin >> s;
    int suit = suit_to_num(s);
    Info *head = person[person_index]->card_head[suit]->next;
    if(head == NULL) cout << "此花色中沒有牌" << endl;
    else {
        while(head != NULL) {
            print_card(head, suit);
            head = head->next;
        }
    }
}
void print_in_opposite_order() {
    int person_index = choose_a_person();
    char s;
    cout << "輸入花色(C,D,H,S): " << endl;
    cin >> s;
    int suit = suit_to_num(s);
    Info *rear = person[person_index]->card_rear[suit];
    if(rear == NULL) cout << "此花色中沒有牌" << endl;
    else {
        while(rear != NULL && rear->num != -1) {
            print_card(rear, suit);
            rear = rear->pre;
        }
    }
}
void function_4() {
    int person_index = choose_a_person();
    bool c[14] = {false};
    char s;
    cout << "輸入花色(C,D,H,S): " << endl;
    cin >> s;
    int suit = suit_to_num(s);
    Info *head = person[person_index]->card_head[suit]->next;
    if(head == NULL) cout << "此花色中沒有牌" << endl;
    else {
        while(head != NULL) {
            c[head->num] = true;
            //print_card(head, suit);
            head = head->next;
        }
    }
    for(int i = 1; i <= 13; ++i) {
        if(c[i]) {
            cout << s;
            if(i == 13) cout << 'A' << endl;
            else cout << i+1 << endl;
        }
    }
}
void print_all_card(int person_index) {
    for(int suit = 0; suit < 4; ++suit) {
        Info *head = person[person_index]->card_head[suit]->next;
        if(head == NULL) continue;
        else {
            while(head != NULL) {
                print_card(head, suit);
                head = head->next;
            }
        }
    }
}
int str_to_num(string n) {
    int num;
    if(n == "A" || n == "a") num = 13;
    else num = stoi(n) - 1;
    return num;
}
void input_card(int *suit, int *num) {
    string card;
    cout << "輸入花色及大小(如下:H6) :" << endl;
    cin >> card;
    *suit = suit_to_num(card[0]);
    *num = str_to_num(card.substr(1)) - 1;
    //cout << sub;
}
void add_card(int person_index) {
    if(card_index >= 52) {
        cout << "牌堆中的牌已發完" << endl;
        return;
    }
    Info *next_c = (Info*)calloc(1, sizeof(Info));
    int suit = card_set[card_index].suit;
    Info *head = person[person_index]->card_head[suit];
    while(head->next != NULL) head = head->next;
    next_c->num = card_set[card_index].num;
    next_c->next = NULL;
    next_c->pre = head;
    head->next = next_c;
    person[person_index]->card_rear[suit] = next_c;
    cout << "增加: ";
    print_card(next_c, suit);
    ++card_index;
    ++person[person_index]->num_of_card;
}
card delete_card(int person_index, int suit, int num) {
    Info *head = person[person_index]->card_head[suit]->next;
    card ret;
    int upper_bound = 100;
    int smallest = 100;
    while(head) {
        if(num < head->num && head->num < upper_bound) upper_bound = head->num;
        if(smallest > head->num) smallest = head->num;
        //cout<<upper_bound<<endl;
        head = head->next;
    }
    head = person[person_index]->card_head[suit]->next;
    if(upper_bound < 100 || smallest < 100) {
        int num_delete = 0;
        if(upper_bound < 100) num_delete = upper_bound;
        else {
            cout << "刪除最小的牌" << endl;
            num_delete = smallest;
        }
        while(head) {
            if(head->num != num_delete) head = head->next;
            else {
                if(head == person[person_index]->card_rear[suit]) {
                    person[person_index]->card_rear[suit] = head->pre;
                    head->pre->next = NULL;
                }
                else if(head == person[person_index]->card_head[suit]) {
                    person[person_index]->card_head[suit] = head->next;
                    head->next->pre = NULL;
                }
                else {
                    Info *tn = head->next;
                    Info *tp = head->pre;
                    tp->next = tn;
                    tn->pre = tp;
                }
                --person[person_index]->num_of_card;
                cout << "刪除: ";
                print_card(head, suit);
                ret.num = num_delete;
                ret.suit = suit;
                free(head);
                break;
            }
        }
    }
    else ret.suit = -1;
    cout << "玩家 " << person_index + 1 << " 現有手牌 :" << endl;
    cout << "數量:" << person[person_index]->num_of_card << endl;
    print_all_card(person_index);
    return ret;
}
void delete_one() {
    int suit, num;
    int person_index = choose_a_person();
    input_card(&suit, &num);
    if(person[person_index]->card_head[suit]->next == NULL) cout << "此花色中沒有牌" << endl;
    else delete_card(person_index, suit, num);
}
void delete_continue() {
    bool first = true;
    int suit, num;
    while(1) {
        for(int person_index = 0; person_index < number_of_person; ++person_index) {
            if(first) {
                num = rand() % 13 + 1;
                suit = rand() % 4;
                int i = 0;
                for(i = 0; i < 4; ++i) {
                    if(person[person_index]->card_head[suit]->next != NULL) break;
                    suit++;
                    if(suit >= 4) suit = 0;
                }
                if(i == 4) {
                    cout << person_index + 1 << "號玩家 is winner!!!" << endl;
                    goto end;
                }
                first = false;
            }
            if(person[person_index]->card_head[suit]->next == NULL) {
                cout << "此花色中沒有牌，抽一張牌" << endl;
                add_card(person_index);
                cout << "玩家 " << person_index + 1 << " 現有手牌 :" << endl;
                cout << "數量:" << person[person_index]->num_of_card << endl;
                print_all_card(person_index);
                first = true;
            }
            else {
                card c = delete_card(person_index, suit, num);
                if(c.suit != -1) {
                    suit = c.suit;
                    num = c.num;
                }
            }
            if(person[person_index]->num_of_card == 0) {
                cout << person_index + 1 << "號玩家 is winner!!!" << endl;
                goto end;
            }
            print_line();
        }
    }
end:
    return;
}