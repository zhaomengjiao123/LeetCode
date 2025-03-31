/**
 * @file 2025hema-3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * 小红有一个长度为n的排列，你每次可以让一个数字加一的同时另一个数字减─，她想问你将这个排列变成递增排列的最小操作次数。你每次操作后都必须保证这些数依旧是一个排列。
排列的定义:长度为n的数组，其中1到n每个数都出现过且仅出现一次。例如[1,3,2]是排列，[1,3,5,3]则不是排列。
输入描述
第一行输入一个n(1<n≤1000)表示排列长度。
第二行输入长度为n的排列p(1≤pi≤n)，保证输入是一个排列。

输出描述
第一行输出一个正整数k表示操作次数。
接下来k行，每行输出两个整数i,j(1≤i,j≤n,i≠j)表示让第i个数字加一、第j个数字减一。
右多解时输出任音即可

排列的定义:长度为n的数组，其中1到n每个数都出现过且仅出现一次

 */
#include <iostream>
#include <vector>
using namespace std;

// 计算逆序对的数量（虽然这里没有直接用到，但可以用于验证）
int count_inversions(const vector<int>& arr) {
    int n = arr.size();
    int inversions = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

// 执行操作，将排列转换为递增排列
vector<pair<int, int>> perform_operations(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> operations;
    bool has_inversions;

    do {
        has_inversions = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    // 执行操作：将 arr[i] 减一，arr[j] 加一
                    arr[i]--;
                    arr[j]++;
                    operations.emplace_back(i + 1, j + 1); // 记录操作
                    has_inversions = true;
                    break; // 退出内层循环
                }
            }
            if (has_inversions) break; // 退出外层循环
        }
    } while (has_inversions);

    return operations;
}

int main() {
    int n;
    cin >> n; // 输入排列长度
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; // 输入排列
    }

    // 执行操作
    vector<pair<int, int>> operations = perform_operations(p);

    // 输出操作次数
    cout << operations.size() << endl;
    // 输出每一步操作
    for (const auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}
