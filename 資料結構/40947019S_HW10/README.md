# HW10 說明及介紹

## 如何使用

- 請在linux的環境下進行
- 輸入以下指令:
  - 編譯: $make
  - 執行: $./hw10

## procedure 功能說明
- 程式說明
  - 功能(1):
    - 要求使用者輸入一行運算式(需在一行內輸入完成，不可有空格)
    - 偵錯功能:有以下狀況，會在終端上印出相對的警告
      1. 左右括弧不對稱
      2. 運算子數目不等於運算元數目+1
    - 建樹(若是運算式出錯，可能不會建出完整的樹)
    - 輸出postfix(運算式沒有出錯)
- function 的列表極有用到的結構在hw10_function.h 中
- 主程式在hw10.cpp 中
- function 的實作在 hw10_function.cpp 中
  - `node build_tree();` :建樹
  - `void preorder(node *ptr);` : 前序走訪
  - `void addq(node *ptr);` : 實作 add queue
  - `node *deleteq();`: 實作 delete queue
  - `void levelorder(node *ptr);` : 階序走訪
  - `int postOrderEval(node *ptr);` : 後序走訪，計算樹終節點的值，最後會傳根節點的值，也就是運算式的計算結果


## 輸出入介面說明

- 執行程式後，會顯示一個選項功能表
  - 開始: 首先要選擇功能(1) ，從鍵盤輸入 1 即可
  - 離開: 選擇功能(5)終止程式碼
- (2) 輸出對應 prefix 運算式
- (3) 輸出對應二元運算樹之 level order 走訪順序
- (4) 要求使用者為所有變數填入整數，最後輸出計算結果
  - 使用者在終端上會看到 :
    ```
    請指定整數
    A:
    ```
  - 接著從鍵盤上輸入一整數即可