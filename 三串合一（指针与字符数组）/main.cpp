//
//  main.cpp
//  三串合一（指针与字符数组）
//
//  Created by Jacky on 2020/9/27.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 输入三个字符串，通过指针读取各个字符串的子串（子串是指字符串中连续的一小部分），把它们合并成一个新字符串
 
 要求：
 
 1. 三个字符串的创建和输入可以使用数组，也可以不用
 
 2. 输入后，根据三个字符串的子串的长度，计算出新字符串的长度
 
 3. 使用动态数组的方法创建新的字符串，并且使用指针读取三个字符串的不同部分，并且复制到新字符串中，要求整个过程都不能使用数组下标
 
 4. 使用指针输出新的字符串
 
 输入
 第一行输入t表示有t个测试实例
 
 连续三行输入三个字符串，每个字符串都包含10个字符
 
 连续三行，每行输入数字a和b，表示每个子串的开始和结束位置。注意字符串的位置是按照一般意义从1开始计算，和编程中的数组位置不同。例如字符串abcdefg，开始位置是3，结束位置是5，那么子串就是cde
 
 依次输入t个实例
 
 输出
 每行输出合并后的新字符串
 
 样例输入
 2
 abcdefghij
 ABCDEFGHIJ
 aabbccddee
 3 5
 2 6
 8 10
 AABBCCDDEE
 ffgghhiijj
 FFGGHHIIJJ
 1 4
 5 8
 2 7
 样例输出
 cdeBCDEFdee
 AABBhhiiFGGHHI
 */

#define N 100
#include <iostream>
using namespace std;

struct str {
    char string[N];
    int min;
    int max;
} s[N];

int main() {
    int t, length, k;
    char *p;
    cin >> t;

    while (t--) {
        length = 0;
        k = 0;
        for (int j = 0; j < 3; j++) {
            cin >> s[j].string;
        }
        for (int j = 0; j < 3; j++) {
            cin >> s[j].min >> s[j].max;
            length += s[j].max - s[j].min + 1;
        }
        p = new char[length];
        for (int j = 0; j < 3; j++) {
            for (int a = s[j].min - 1; a < s[j].max; a++) {
                *(p + k++) = s[j].string[a];
            }
        }
        *(p + k) = '\0';
        cout << p << endl;
        delete[] p;
    }

    return 0;
}