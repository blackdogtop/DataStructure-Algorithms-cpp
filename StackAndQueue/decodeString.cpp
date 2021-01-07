#include <iostream>
#include <vector>
using namespace std;
/* https://leetcode-cn.com/problems/decode-string/
 *
 *给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像3a或2[4]的输入。
 *
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"*/


class Solution {
public:
    string decodeString(string s) {
    /* Stack
     * Complexity:
     *      time: O(n)
     *      space: O(n) */
    string res;
    vector<pair<int, string>> stack;
    int multi = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9'){
            multi = multi * 10 + (s[i] - '0');  // 减去0的ACSII值(48)
        }
        else if (s[i] == '['){
            stack.push_back(make_pair(multi, res));
            multi = 0;
            res = "";
        }
        else if(s[i] == ']'){
            int cur_multi = stack.back().first;
            string last_res = stack.back().second;
            stack.pop_back();
            for (int j = 0; j < cur_multi; ++j){
                last_res += res;
            }
            res = last_res;
        }
        else{
            res = res + s[i];
        }
    }
    return res;
    }
};

int main(){
    string test = "3[a]2[bc]";
    Solution s;
    string res = s.decodeString(test);
    cout << res << endl;
}