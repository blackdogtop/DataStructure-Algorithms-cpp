#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/subsets/

78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

输入: nums = [1,2,3]
输出:
[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]
*/


class Solution {
public:
    vector<vector<int> > res;

    void back_track(vector<int>& nums, vector<int>& path, int begin){
        res.push_back(path);

        for(int i = begin; i < nums.size(); i++){
            path.push_back(nums[i]);

            back_track(nums, path, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> path;
        int begin = 0;

        back_track(nums, path, begin);

        return res;
    }
};


int main(){
    vector<int> nums;
    for(int i = 1; i < 4; i++){
        nums.push_back(i);
    }
    vector<vector<int> > res = Solution().subsets(nums);
}