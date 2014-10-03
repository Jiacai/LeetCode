#include <stack>
#include <string>
using namespace std;
 
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            string &token = tokens[i];
            if (token == "+") {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int r = a + b;
                num_stack.push(r);
            } else if (token == "-") {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int r = b - a;
                num_stack.push(r);
            } else if (token == "*") {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int r = a * b;
                num_stack.push(r);
            } else if (token == "/") {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int r = b / a;
                num_stack.push(r);
            } else { // number
                bool neg = (token[0] == '-');
                int pos = 0;
                if (neg) {
                    pos = 1;
                }
                int r = 0;
                for (int k = pos; k < token.length(); k++) {
                    r = r * 10 + (token[k] - '0');
                }
                if (neg) {
                    r = -r;
                }
                num_stack.push(r);
            }
        }
        int result = num_stack.top();
        num_stack.pop();
        return result;
    }
 
private:
    stack<int> num_stack;
};