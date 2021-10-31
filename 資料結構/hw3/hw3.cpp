#include "function.h"
polynomial p[100];
int pCount;
int main() {
    pCount = 0;
    int choose;
    polynomial pRet;
    pRet.name = "Ans";
    while(1) {
        if(choose == 10) break;
        if(pCount != 0) choose = printMenu(pCount);
        else choose = 1;
        switch (choose) {
        case 1:
            input(&p[pCount]);
            break;
        case 2:
            output(p[choose_ptr(pCount)]);
            break;
        case 3:
            int chooseDegree;
            cout << "請輸入次方數" << endl;
            cin >> chooseDegree;
            cout << p[choose_ptr(pCount)].coef[chooseDegree - 1] << endl;
            break;
        case 4:
            pAttach(&p[choose_ptr(pCount)]);
            break;
        case 5:
            pRemove(&p[choose_ptr(pCount)]);
            break;
        case 6:
            pAdd(p[choose_ptr(pCount)], p[choose_ptr(pCount)], &p[pCount]);
            break;
        case 7:
            pMinus(p[choose_ptr(pCount)], p[choose_ptr(pCount)], &p[pCount]);
            break;
        case 8:
            pMult(p[choose_ptr(pCount)], p[choose_ptr(pCount)], &p[pCount]);
            break;
        default:
            break;
        }
        if(choose < 10 && choose > 0) cout << "輸入enter以繼續" << endl;
        if(choose != 1) cin.ignore(100, '\n');
        cin.ignore(100, '\n');
    }
    return 0;
}
int printChoose(int pCount) {
    int pChoose;
    while(pChoose < 1 || pChoose > pCount) {
        cout << "請選擇一個函式(最高到" << pCount << ")" << endl;
        for(int i = 0; i < pCount; ++i) cout << "(" << i + 1 << ") " << p[i].name << endl;
        cin >> pChoose;
    }
    return pChoose - 1;
}
void init(polynomial *p) {
    string name;
    cout << "請輸入函式的名稱:" << endl;
    cin >> name;
    p->name = name;
    for(int i = 0; i < MAX; ++i) p->coef[i] = 0.0;
    ++pCount;
}