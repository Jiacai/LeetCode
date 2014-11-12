class MinStack {
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || minstk.top() >= x) {
            minstk.push(x);
        }
    }

    void pop() {
        int x = stk.top();
        stk.pop();
        if (x == minstk.top()) {
            minstk.pop();
        }
        
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};
