//
//  main.cpp
//  向量5（友元类）
//
//  Created by Jacky on 2020/12/28.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述


 在向量CVector类的代码上，定义n阶矩阵类CMatrix，包含私有数据成员M存储矩阵数据，n存储矩阵阶数。

 将CMatrix定义为CVector的友元类。

 为CMatrix添加成员函数：CVector Multi(const CVector &V1)，计算n阶矩阵与n维向量V1的乘积。

 为CMatrix添加成员函数，判定矩阵与向量V1是否可计算乘积。

 为CMatrix添加需要的构造函数、析构函数和其它成员函数。

 主函数输入数据，测试矩阵与向量的乘积。

 附：n阶矩阵包含n*

 输入
 测试次数t

 对每组测试数据，格式如下

 第一行，矩阵阶数n 向量维数m

 n阶矩阵

 m维向量

 输出
 对每组测试数据，若矩阵与向量不能计算乘积，输出error；否则输出计算结果

 样例输入
 1
 3
 1 0 0
 0 1 0
 0 0 1
 3
 1 2 3
 样例输出
 1 2 3
 提示
 */

#include <iostream>
using namespace std;

class CMatrix;

class CVector {
    int *data;
    int n;

public:
    friend class CMatrix;
    CVector(int _n) : n(_n) {
        data = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
    }
    CVector(int _n, int a[]) : n(_n) {
        data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = a[i];
        }
    }
    void print() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    ~CVector() {
        delete[] data;
    }
};

class CMatrix {
    int **M;
    int n;

public:
    CMatrix(int _n) : n(_n) {
        M = new int *[n];
        for (int i = 0; i < n; i++) {
            M[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
    }
    bool isMultipliable(const CVector &V1) {
        return n == V1.n;
    }
    CVector Multi(const CVector &V1) {
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            for (int j = 0; j < n; j++) {
                a[i] += V1.data[j] * M[i][j];
            }
        }
        return CVector(n, a);
    }
    ~CMatrix() {
        for (int i = 0; i < n; i++) {
            delete [] M[i];
        }
        delete[] M;
    }
};

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> n;
        CMatrix c(n);
        cin >> m;
        CVector v(m);
        if (c.isMultipliable(v)) {
            c.Multi(v).print();
        } else {
            cout << "error" << endl;
        }
    }
    return 0;
}
