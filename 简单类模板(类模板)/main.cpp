//
//  main.cpp
//  简单类模板(类模板)
//
//  Created by Jacky on 2020/12/28.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个列表类，该列表包含属性：数值列表（用长度为100的数组表示），数据长度（实际的数据个数）；包含的方法：初始化、插入、删除、打印，方法定义为：

 1）初始化，接受外来参数，把数据保存在数值列表中，未使用的列表部分全部初始化为-1

 2）插入，接受外来参数的插入位置和插入数值，插入位置从0开始计算，注意从插入位置开始，原有数据都要往后移动一位，且数据长度+1

 3）删除，接受外来参数的删除位置，删除位置从0开始计算，注意从删除位置后一位开始，原有数据都要往前移动一位，且数据长度-1

 4）打印，把包含的数据按位置顺序输出一行，数据之间单个空格隔开

 使用类模板的方法，使得这个类支持整数int类型和浮点数double类型

 输入
 第一行先输入参数n表示有n个数据，接着输入n个整数

 第二行输入两个参数，表示插入位置和插入数值，数值为整数

 第三行输入删除位置

 第四行先输入参数n表示有n个数据，接着输入n个浮点数

 第五行输入两个参数，表示插入位置和插入数值，数值为浮点数

 第六行输入删除位置

 输出
 针对头三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的整数数据

 针对接着的三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的浮点数数据

 样例输入
 5 11 22 33 44 55
 2 888
 4
 5 1.1 2.2 3.3 4.4 5.5
 2 88.8
 3
 样例输出
 11 22 888 33 55
 1.1 2.2 88.8 4.4 5.5
 提示
 */

#define N 100
#include <iostream>
using namespace std;

template <typename T>
class List {
    T data[N];
    int length;

public:
    List() {
        for (int i = 0; i < N; i++) {
            data[i] = -1;
        }
        cin >> length;
        for (int i = 0; i < length; i++) {
            cin >> data[i];
        }
    }
    void insert(int place, T numeric) {
        for (int i = length-1; i >= place; i--) {
            data[i+1] = data[i];
        }
        data[place] = numeric;
        length++;
    }
    void remove(int delPlace) {
        for (int i = delPlace; i < length-1; i++) {
            data[i] = data[i+1];
        }
        data[length-1] = -1;
        length--;
    }
    void display() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    int place, n;
    double d;
    
    List<int> p1;
    cin >> place >> n;
    p1.insert(place, n);
    cin >> place;
    p1.remove(place);
    p1.display();
    
    List<double> p2;
    cin >> place >> d;
    p2.insert(place, d);
    cin >> place;
    p2.remove(place);
    p2.display();
    return 0;
}
