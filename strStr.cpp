#include <iostream>
#include <vector>
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
        if(haystack.size() != needls.size()) {
            return false;
        }

        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] != needls[i]) {
                return false;
            }
        }

        return true;
    }

    int strStr(string haystack, string needle) {

        if(needle.empty()) {
            return 0;
        }

        if(needle.size() > haystack.size()) {
            return -1;
        }

        for(int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            if(is_equal(haystack.substr(i, needle.size()), needle) == true) {
                return i;
            }
        }

        return -1;
    }
};

int main(){
    string haystack = "hello";
    string needle = "ll";
    int pos = Solution().strStr(haystack, needle);
    cout << pos << endl;
}