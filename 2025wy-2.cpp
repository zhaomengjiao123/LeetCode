/**
 * @file 2025wy-2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/***
 * 小易是一个热爱数学和编程的少年，最近他迷上了一款名为“2048"的数字游戏。这款游戏的规则简单却充满挑战:在一个4×4的矩阵中，每个格子要么是0(代表空位)，要么是2的x次方(如2,4，8，.... 2048)。玩家可以通过上、下、左、右四个方向的操作，将相同数字的格子合并，最终目标是得到2048这个数字。
小易不仅喜欢玩这款游戏，还喜欢研究它的算法。有一天，他突发奇想:如果矩阵的大小不是固定的4×4，而是任意的M×N，那么游戏会变成什么样呢?于是，他决定编写一个程序，模拟在任意大小的矩阵上进行一系列操作后的结果。
给定一个M×N (1 ≤M,N≤ 32，M行、N列)的矩阵，其中每个元素是2的×次方（范围[2,2048]以及0-代表空位)，不含有其它数字。现在给出一系列操作方向(上、下、左、右，序列长度不大于32)，需要求解按指定序列操作得到的最终结果。具体的操作规则有三种:
1.移动:在指定方向上，所有非零元素会向该方向移动，直到遇到矩阵边界或另一个非零元素。
2.合并:在移动过程中，如果两个相邻的元素数值相同，则它们会合并为一个元素，其值为原值的两倍。
3.堆积:合并后的元素会继续向指定方向移动，直到无法移动为止。
小易希望通过这个程序处理任意大小的矩阵。你能帮助他实现这个目标吗?
输入第一行为一个正整数T(T≤ 10)，表示有T组数据。每组数据第一行，第一个正整数C(C≤ 32)表示操作序列的长度，后面接C个正整数表示操作的序列，数字所代表的方向为:0-上、1-左、2-下、3-右。
接下来一行两个正整数M，N(1 ≤ M,N ≤ 32，M行、N列)。
接下来的M行:每行包含N个整数，表示矩阵中的元素，元素取值为:2范围[2,2048]以及0-代表空位。
输出描述
对于每组数据，输出最终的矩阵状态数值，如原始输入为M×N的矩阵，则输出也按M行数据每行Ⅳ个数字进行输出

 */

 #include <iostream>
#include <vector>
using namespace std;

void moveUp(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int j = 0; j < N; ++j) {
        vector<int> col(M, 0);
        int pos = 0;
        for (int i = 0; i < M; ++i) {
            if (matrix[i][j] != 0) {
                col[pos++] = matrix[i][j];
            }
        }
        for (int i = 0; i < pos - 1; ++i) {
            if (col[i] == col[i + 1]) {
                col[i + 1] *= 2;
                col[i] = 0;
                i++; // Skip the next element
            }
        }
        pos = 0;
        for (int i = 0; i < M; ++i) {
            if (col[i] != 0) {
                matrix[pos][j] = col[i];
                pos++;
            }
        }
        for (int i = pos; i < M; ++i) {
            matrix[i][j] = 0;
        }
    }
}

void moveDown(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int j = 0; j < N; ++j) {
        vector<int> col(M, 0);
        int pos = M - 1;
        for (int i = M - 1; i >= 0; --i) {
            if (matrix[i][j] != 0) {
                col[pos--] = matrix[i][j];
            }
        }
        for (int i = M - 1; i > 0; --i) {
            if (col[i] == col[i - 1]) {
                col[i - 1] *= 2;
                col[i] = 0;
                i--; // Skip the next element
            }
        }
        pos = M - 1;
        for (int i = M - 1; i >= 0; --i) {
            if (col[i] != 0) {
                matrix[pos][j] = col[i];
                pos--;
            }
        }
        for (int i = pos; i >= 0; --i) {
            matrix[i][j] = 0;
        }
    }
}

void moveLeft(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int i = 0; i < M; ++i) {
        vector<int> row(N, 0);
        int pos = 0;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] != 0) {
                row[pos++] = matrix[i][j];
            }
        }
        for (int j = 0; j < pos - 1; ++j) {
            if (row[j] == row[j + 1]) {
                row[j + 1] *= 2;
                row[j] = 0;
                j++; // Skip the next element
            }
        }
        pos = 0;
        for (int j = 0; j < N; ++j) {
            if (row[j] != 0) {
                matrix[i][pos++] = row[j];
            }
        }
        for (int j = pos; j < N; ++j) {
            matrix[i][j] = 0;
        }
    }
}

void moveRight(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int i = 0; i < M; ++i) {
        vector<int> row(N, 0);
        int pos = N - 1;
        for (int j = N - 1; j >= 0; --j) {
            if (matrix[i][j] != 0) {
                row[pos--] = matrix[i][j];
            }
        }
        for (int j = N - 1; j > 0; --j) {
            if (row[j] == row[j - 1]) {
                row[j - 1] *= 2;
                row[j] = 0;
                j--; // Skip the next element
            }
        }
        pos = N - 1;
        for (int j = N - 1; j >= 0; --j) {
            if (row[j] != 0) {
                matrix[i][pos--] = row[j];
            }
        }
        for (int j = pos; j >= 0; --j) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int C;
        cin >> C;
        vector<int> ops(C);
        for (int i = 0; i < C; ++i) {
            cin >> ops[i];
        }
        int M, N;
        cin >> M >> N;
        vector<vector<int>> matrix(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }
        for (int op : ops) {
            switch (op) {
                case 0:
                    moveUp(matrix);
                    break;
                case 1:
                    moveLeft(matrix);
                    break;
                case 2:
                    moveDown(matrix);
                    break;
                case 3:
                    moveRight(matrix);
                    break;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
