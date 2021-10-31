#include"function.h"
void output(polynomial p) {
    int first = 1;
    cout << p.name << " : ";
    for(int i = MAX - 1; i >= 0; --i) {
        float c = p.coef[i];
        if(c != 0.0) {
            if(first) {
                cout << c;
                first = 0;
            }
            else if(c > 0) cout << " +" << c;
            else if(c < 0) cout << " " << c;
            if(i != 0) cout << "x";
            if(i != 1 && i != 0) cout << "^" << i;
        }
    }
    if(first) cout << "0" << endl;
    cout << endl;
}
void input(polynomial *p) {
    init(p);
    string poly;
    cout << "請輸入一個函式\n形式如下:[係數][空格][次方][空格][係數][空格][次方]..." << endl;
    cin.ignore(100, '\n');
    getline(cin, poly);
    stringstream ss(poly);
    int co, deg;
    while(ss >> co) {
        ss >> deg;
        p->coef[deg] = co;
    }
    output(*p);
}
bool pAttach(polynomial *p) {
    int coef, exp;
    cout << "請輸入要新增的項目的底數及底數:\n形式如下:[係數][空格][指數]\n若是該次方的係數已存在則不會更該原函式" << endl;
    cin >> coef >> exp;
    if(p->coef[exp] != 0.0) cout << "該次方的係數已存在" << endl;
    else p->coef[exp] = coef;
    output(*p);
    return true;
}
void pRemove(polynomial *p) {
    int exp;
    cout << "請輸入要刪除的項目的指數:\n形式如下:[指數]\n若是該次方的係數為零則不會更該原函式" << endl;
    cin >> exp;
    if(p->coef[exp] == 0.0) cout << "該次方係數為零" << endl;
    else p->coef[exp] = 0.0;
    output(*p);
}
void pAdd(polynomial p1, polynomial p2,polynomial *ans) {
    init(ans);
    for(int i = 0; i < MAX; ++i) {
        if(p1.coef[i] || p2.coef[i]) ans->coef[i] = p1.coef[i] + p2.coef[i];
    }
    output(*ans);
}
void pMinus(polynomial p1, polynomial p2,polynomial *ans) {
    init(ans);
    for(int i = 0; i < MAX; ++i) {
        if(p1.coef[i] || p2.coef[i]) ans->coef[i] = p2.coef[i] - p1.coef[i];
    }
    output(*ans);
}
void pMult(polynomial p1, polynomial p2,polynomial *ans) {
    init(ans);
    for(int i=0;i<MAX;++i){
        for(int j=0;j<=i;++j){
            if(p1.coef[j] && p2.coef[i-j]) ans->coef[i]=p1.coef[j]*p2.coef[i-j];
        }
    }
    output(*ans);
}
void pDivid(polynomial p1, polynomial p2,polynomial *ans) {
}
int printMenu(int c) {
    int choose;
    if(c > 1) c = 2;
    switch(c) {
    case 1:
        cout << "(1) 輸入一個 X 的多項式\n(2) 顯示多項式的內容\n(3) 指定多項式之指數次方，顯示該項的係數值\n(4) 新增多項式的非零項\n(5) 移除多項式的非零項" << endl;
        break;
    case 2:
        cout << "(1) 輸入一個 X 的多項式\n(2) 顯示多項式的內容\n(3) 指定多項式之指數次方，顯示該項的係數值\n(4) 新增多項式的非零項\n(5) 移除多項式的非零項" << endl;
        cout << "(6) 選擇兩個多項式 P1 及 P2，做 P1 及 P2 的相加，並顯示 P1+P2 的結果\n(7) 選擇兩個多項式 P1 及 P2，做 P1 及 P2 的相減，並顯示 P1-P2 的結果\n(8) 選擇兩個多項式 P1 及 P2，做 P1 及 P2 的相乘，並顯示 P1xP2 的結果\n(9) 選擇兩個多項式 P1 及 P2，做 P1 及 P2 的相除，並顯示 P1 除 P2 的商及餘數" << endl;
        cout << "(10) 結束" << endl;
        break;
    default:
        break;
    }
    cin >> choose;
    return choose;
}

