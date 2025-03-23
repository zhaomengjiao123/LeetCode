/**
 * @file 2025wy-3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/***
 * 在游戏《星际探险》中，主角小易是一名天才程序员，负责为游戏中的飞船设计燃料调配系统。飞船的燃料由四种不同的元素组成，分别用变量(x,y,z, w)表示。每种元素的含量必须在О到2500之间，以确保飞船的稳定运行。
飞船的燃料调配系统遵循一个四元一次方程:Ax + By + Cz+ Dw =N
其中，A,B,C,D是四种元素的能量系数，N是飞船所需的总能量值。小易的任务是找到一组满足方程的整数解(x,y,z, w)，并且确保每种元素的含量都在О到2500之间。
输入描述
输入包含五个整数A,B,C,D,N，分别表示方程中的系数和常数项。其中0≤A,B,C,D,N≤109
输出描述
输出四个整数x, y,z, w，表示方程的解，其中0≤x,y,Z,W≤ 2500。
如果存在多组解，输出字典序最小的那组解，当不存在这样的解时，输出-1。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int main(){
//     long long A, B, C, D, N;
//     cin >> A >> B >> C >> D >> N;
//     vector<vector<long long>> solutions;
//     long long x = -1, y = -1, z = -1, w = -1;
//     for (long long i = 0; i <= 2500; ++i) {
//         if (i * A > N) break;
//         for (long long j = 0; j <= 2500; ++j) {
//             if (i * A + j * B > N) break;
//             for (long long k = 0; k <= 2500; ++k) {
//                 if (i * A + j * B + k * C > N) break;
//                 long long l = N - i * A - j * B - k * C;
//                 if (l % D == 0) {
//                     l /= D;
//                     if (l <= 2500) {
//                         solutions.push_back({i, j, k, l});
//                         x = i;
//                         y = j;
//                         z = k;
//                         w = l;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     if (x == -1) {
//         cout << -1 << endl;
//     } else {
//         // sort(solutions.begin(), solutions.end());
//         // x = solutions[0][0];
//         // y = solutions[0][1];
//         // z = solutions[0][2];
//         // w = solutions[0][3];
//         cout << x << " " << y << " " << z << " " << w << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long A, B, C, D, N;
    cin >> A >> B >> C >> D >> N;

    vector<long long> solutions(4,-1);

    for (long long x = 0; x <= N/A; ++x) {
        for (long long y = 0; y <= (N-A*x)/B; ++y) {
            long long remaining = N - A * x - B * y;
            if (remaining < 0) continue;

            for (long long z = 0; z <= remaining/C; ++z) {
                long long tmp = remaining - C * z;
                if (tmp<0) continue;
                // long long w = (remaining - C * z) / D;
                // if (w >= 0 && w <= 2500 && C * z + D * w == remaining) {
                //     solutions.push_back({x, y, z, w});
                // }
                if (D == 0) {
                    if (tmp == 0) {
                        // w可以是任意值，但这里我们希望w尽可能小
                        long long w = 0;
                        // 检查是否是最小解
                        if (solutions[0] == -1 || 
                            x < solutions[0] ||
                            (x == solutions[0] && y < solutions[1]) ||
                            (x == solutions[0] && y == solutions[1] && z < solutions[2]) ||
                            (x == solutions[0] && y == solutions[1] && z == solutions[2] && w < solutions[3])) {
                                solutions[0] = x;
                                solutions[1] = y;
                                solutions[2] = z;
                                solutions[3] = w;
                        }
                    }
                } else {
                    long long w = tmp / D;
                    if (D * w == tmp && w >= 0) {
                        // 检查是否是最小解
                        if (solutions[0] == -1 || 
                            x < solutions[0] ||
                            (x == solutions[0] && y < solutions[1]) ||
                            (x == solutions[0] && y == solutions[1] && z < solutions[2]) ||
                            (x == solutions[0] && y == solutions[1] && z == solutions[2] && w < solutions[3])) {
                                solutions[0] = x;
                                solutions[1] = y;
                                solutions[2] = z;
                                solutions[3] = w;
                        }
                    }
                }
            
            }
        }
    }

    if (solutions.empty()) {
        cout << -1 << endl;
    } else {
        sort(solutions.begin(), solutions.end());
        cout << solutions[0] << " " << solutions[1] << " " << solutions[2] << " " << solutions[3] << endl;
    }

    return 0;
}