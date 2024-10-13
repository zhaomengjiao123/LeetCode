// 最小栈  设计 一个支持常熟时间内检索到最小元素的栈
// 用辅助栈  每个元素入栈之前 对应保存它及它之前的最小值


#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


class MinStack
{

stack<int> x_stack;
stack<int> min_stack;

public:
    MinStack(){
        min_stack.push(INT_MAX);
    }

    void push(int x){
        // 放入的时候 同步放入当前最小的值
        x_stack.push(x);
        min_stack.push(min(min_stack.top(),x));
    }
    void pop(){
        x_stack.pop();
        min_stack.pop();
    }

    int top(){
        return x_stack.top();
    }
    int getMin(){
        return min_stack.top();
    }
    ~MinStack();
};

MinStack::MinStack(/* args */)
{
}

MinStack::~MinStack()
{
}
