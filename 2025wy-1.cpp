/**
 * @file 2025wy-1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/***
 * 小易是一名资深的《金融大亨》模拟经营类型游戏的玩家。某天，他在游戏中意外触发了一个隐藏任务——“时空回溯"”。在这个任务中，小易回到了游戏中的过去，并且凭借他对未来股市的记忆，清楚地知道在接下来的N天中，M支优质股票每天的股价。
在这个游戏中，玩家每天可以选择将手中持有的股票出售兑换成现金，并可以选择以当天股价买入另一支股票，或者选择持有现金不买入。但任务规定，在最后一天结算后，手中必须是持有现金的状态。由于游戏中的股价对小易是透明的，他每天都会将所有资金投入获利期望最大的一支股票，如果当天所有股票都无法获利，那么他会选择持有现金不买入。
现在，小易手里有一些启动资金，但游戏中的股市情况多变，他希望能够在N天后，从可预知股价的这M支股票中获取最大的利益。你能帮他计算一下N天后他手中能有多少现金，并且列出这N天中小易的股票买卖情况吗?
输入：
第一行为三个正整数N、M和K，分别表示天数、不同的股票支数和小易手中的启动资金。接下来有Ⅳ行数据，每行M个正实数W表示当天每支股票每股的单价（规定买入的股数可以不为整数)。
对于所有数据，满足1≤N≤ 20，1 ≤M≤ 20000,1 ≤K≤100,1 ≤ Wi≤ 50。
输出描述
第一行输出一个正实数，表示小易最终能获取到的现金数量，保留4位小数。接下来N行输出每天小易的股票买卖情况，每行输出两个整数×、Y，分别表示以当天价格小易抛售了哪支股票的股份，买入了哪支股票，其中规定如果小易当天做出了买或者卖的操作，则两个整数范围是0
≤×，Y<M。若当天没做买或者卖的操作，则在对应位置填-1。

 */

//  #include <iostream>
//     #include <vector>
//     #include <algorithm>
//     #include <iomanip>
//     using namespace std;
// int main(){
//     int N, M, K;
//     cin >> N >> M >> K;
//     vector<vector<double>> prices(N, vector<double>(M));
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             cin >> prices[i][j];
//         }
//     }
//     vector<double> cash(N+1, 0.0); // 第i天手中的现金
//     vector<vector<double>> stock(N+1, vector<double>(M,0.0)); // 第i天手中的股票
//     vector<int> buy_stock(N,-1); // 第i天买入的股票
//     vector<int> sell_stock(N,-1); // 第i天卖出的股票
//     cash[0] = K;
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             // 如果昨天有现金，今天买入股票
//             if(cash[i]/prices[i][j]>stock[i][j]){
//                 stock[i+1][j] = cash[i]/prices[i][j];
//                 cash[i+1] = 0;
//                 buy_stock[i] = j;
//             }else{
//                 stock[i+1][j] = stock[i][j];
//             }
            
//         }
//         //如果昨天有股票 今天就卖掉
//         double max_value = 0;
//         int sell_index =-1;
//         for (int j = 0; j < M; j++)
//         {
//             /* code */
//             double value = stock[i+1][j]*prices[i][j];
//             if(value>max_value){
//                 max_value = value;
//                 sell_index = j;
//             }
//         }
//         cash[i+1] = max_value;
//         if (sell_index!=-1)
//         {
//             /* code */
//             sell_stock[i] = sell_index;
//         }  
//     }
//     cout << fixed << setprecision(4) << cash[N] << endl;
//     for (int i = 0; i < N; ++i) {
//         cout << sell_stock[i] << " " << buy_stock[i] << endl;
//     }
//     return 0;
    
// }


// #include <iostream>
// #include <vector>
// #include <iomanip>

// using namespace std;

// int main() {
//     int N, M;
//     double K;
//     cin >> N >> M >> K;

//     vector<vector<double>> prices(N, vector<double>(M));
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             cin >> prices[i][j];
//         }
//     }

//     vector<double> cash(N + 1, 0);
//     vector<int> stock(N + 1, -1);
//     vector<vector<int>> operations(N, vector<int>(2, -1));

//     cash[0] = K;
//     stock[0] = -1;

//     for (int i = 1; i <= N; ++i) {
//         double max_cash = cash[i - 1];
//         int sell_stock = -1;
//         int buy_stock = -1;

//         // 如果前一天持有股票，可以选择卖出
//         if (stock[i - 1] != -1) {
//             double sell_price = prices[i - 1][stock[i - 1]];
//             double current_cash = cash[i - 1] + sell_price;
//             if (current_cash > max_cash) {
//                 max_cash = current_cash;
//                 sell_stock = stock[i - 1];
//                 buy_stock = -1;
//             }
//         }

//         // 遍历所有股票，选择买入
//         for (int j = 0; j < M; ++j) {
//             double buy_price = prices[i - 1][j];
//             if (cash[i - 1] >= buy_price) {
//                 double current_cash = cash[i - 1] - buy_price;
//                 if (current_cash > max_cash) {
//                     max_cash = current_cash;
//                     sell_stock = -1;
//                     buy_stock = j;
//                 }
//             }
//         }

//         cash[i] = max_cash;
//         stock[i] = buy_stock;
//         operations[i - 1][0] = sell_stock;
//         operations[i - 1][1] = buy_stock;
//     }

//     cout << fixed << setprecision(4) << cash[N] << endl;
//     for (int i = 0; i < N; ++i) {
//         cout << operations[i][0] << " " << operations[i][1] << endl;
//     }

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <iomanip>
// using namespace std;

// int main() {
//     int N, M;
//     double K;
//     cin >> N >> M >> K;

//     vector<vector<double>> prices(N, vector<double>(M));
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             cin >> prices[i][j];
//         }
//     }

//     double cash = K;
//     vector<double> stocks(M, 0.0);
//     vector<pair<int, int>> trades(N, {-1, -1});

//     for (int day = 0; day < N; ++day) {
//         int best_stock = -1;
//         double max_profit = 0.0;

//         // Find the best stock to buy today
//         for (int stock = 0; stock < M; ++stock) {
//             double profit = (day > 0) ? prices[day][stock] - prices[day - 1][stock] : 0.0;
//             if (profit > max_profit) {
//                 max_profit = profit;
//                 best_stock = stock;
//             }
//         }

//         // If there is a profitable stock, sell all stocks and buy the best stock
//         if (best_stock != -1) {
//             // Sell all stocks
//             for (int i = 0; i < M; ++i) {
//                 cash += stocks[i] * prices[day][i];
//                 stocks[i] = 0.0;
//             }

//             // Buy the best stock
//             stocks[best_stock] = cash / prices[day][best_stock];
//             cash = 0.0;

//             // Record the trade
//             trades[day] = {best_stock, best_stock};
//         }
//     }

//     // On the last day, sell all stocks to get cash
//     for (int i = 0; i < M; ++i) {
//         cash += stocks[i] * prices[N - 1][i];
//         stocks[i] = 0.0;
//     }

//     // Output the final cash and trades
//     cout << fixed << setprecision(4) << cash << endl;
//     for (const auto& trade : trades) {
//         cout << trade.first << " " << trade.second << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
    double K;
    cin >> N >> M >> K;

    vector<vector<double>> prices(N, vector<double>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> prices[i][j];
        }
    }

    double cash = K;
    int current_stock = -1; // -1表示持有现金
    int prev_stock = -1;
    vector<pair<int, int>> operations;

    for (int i = 0; i < N; ++i) {
        int sell_stock = -1;
        int buy_stock = -1;

        // 必须卖出当前持有的股票（如果有）
        if (current_stock != -1) {
            cash *= prices[i][current_stock] / prices[i-1][current_stock];
            sell_stock = current_stock;
            current_stock = -1;
        }

        // 如果是最后一天，不能买入
        if (i == N - 1) {
            operations.emplace_back(sell_stock, -1);
            break;
        }

        // 寻找次日收益率最高的股票
        double max_ratio = 0.0;
        int best_k = -1;
        for (int k = 0; k < M; ++k) {
            double ratio = prices[i+1][k] / prices[i][k];
            if (ratio > max_ratio) {
                max_ratio = ratio;
                best_k = k;
            }
        }

        if (max_ratio > 1.0) {
            // 买入最佳股票
            buy_stock = best_k;
            current_stock = best_k;
        } else {
            buy_stock = -1;
        }

        operations.emplace_back(sell_stock, buy_stock);
    }

    // 输出结果
    cout << fixed << setprecision(4) << cash << endl;
    for (auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}


