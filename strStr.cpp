#include <iostream>
#include <string>

using namespace std;

/*
https://leetcode-cn.com/problems/implement-strstr/

28. 实现 strStr()
给定一个haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回-1

输入: haystack = "hello", needle = "ll"
输出: 2
*/

class Solution {
public:
    bool is_equal(string haystack, string needls) {
        /* Time complexity: O(n)*/
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] != needls[i]) {
                return false;
            }
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        /* 逐一比较子字符串
         * Complexity:
         *      time: O((m-n)n) m - haystack.size() n - needle.size()
         *      space: O(1) */
        if(needle.empty())
            return 0;
        if(needle.size() > haystack.size())
            return -1;
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0; i < m - n + 1; ++i) {
            if(is_equal(haystack.substr(i, n), needle))
                return i;
        }
        return -1;
    }

    int strStrTwoPtrs(string haystack, string needle){
        /* 双指针
         * Complexity:
         *      time: O((m-n)n) - 最差  m - haystack.size() n - needle.size()
         *      space: O(1) */
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        int m = haystack.size();
        int n = needle.size();
        int i = 0;
        while (i < m){
            if (haystack[i] == needle[0]){
                int index = i;
                int equalNum = 0;  // 相同元素数
                int j = 0;
                while (j < n && i < m){
                    if (haystack[i] != needle[j]){
                        i = i - equalNum + 1;  // 将i设为当前位置与相同元素数加一
                        break;
                    }
                    if (j == n - 1){
                        return index;
                    }
                    ++i;
                    ++j;
                    ++equalNum;
                }
            } else{
                ++i;
            }
        }
        return -1;
    }
};


int main(){
    string haystack = "hello";
    string needle = "ll";
    Solution s;
//    int pos = s.strStr(haystack, needle);  // 逐一比较子字符串
    int pos = s.strStrTwoPtrs(haystack, needle);  // 双指针
    cout << pos << endl;
}