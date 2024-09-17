#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

// 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
      // 先定一个一个map
      map<int, int> map;
      vector<int> vec(2,-1);  // 定义一个容器，初始大小为2，值为-1
      // 从前往后开始遍历数据
      for(int i=0;i<nums.size();i++){
        // 如果在当前的map中找到了，就返回
            if(map.count(target-nums[i])>0){
                vec[0]=map[target-nums[i]];
                vec[1]=i;
                break;
            }
            // 否则的话就将当前的值放入到map中  将值和结果反过来放
            map[nums[i]]=i;

      }
      return vec;

}


int main(){
     vector<int> nums; // 定义一个整数向量
    int n; // 用于存储元素个数
    int target;

    // 读取元素个数
    cout << "Enter the number of elements: ";
    cin >> n;

    // 确保元素个数大于 0
    if (n <= 0) {
        cout << "Number of elements should be positive." << endl;
        return 1;
    }

    // 读取元素并将其存储到向量中
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    cout << "Result: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}