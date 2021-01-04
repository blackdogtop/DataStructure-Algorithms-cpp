#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /* Complexity:
         *      time: O(n)
         *      space: O(n) - 最差 */
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"|| tokens[i] == "/"){
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(n2 + n1);
                if (tokens[i] == "-") st.push(n2 - n1);
                if (tokens[i] == "*") st.push(n2 * n1);
                if (tokens[i] == "/") st.push(n2 / n1);
            }
            else{
                st.push(stoi(tokens[i]));  // 字符串转int
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};


int main(){
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    int res = s.evalRPN(tokens);
    cout << res;
}