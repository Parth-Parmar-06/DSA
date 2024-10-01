#include<bits/stdc++.h>
using namespace std;
class Stack {
public: 
    stack<int> st;
    int mini = INT_MAX;
    void push(int ele) {
        if (st.empty()) {
            mini = ele;
            st.push(ele);
        } else if (ele >= mini) {
            st.push(ele);
        } else {
            st.push(2*ele-mini);
            mini = ele;
        }
    }
    void pop() {
        if (st.empty()) return;
        if (st.top()>=mini) {
            st.pop();
        } else {
            mini = 2*mini - st.top();
            st.pop();
        }
    }
    int getMin() {
        return mini;
    }
    int top() {
        if (st.empty()) return -1;
        if (st.top()>=mini) {
            return st.top();
        } else {
            return mini;
        }
    }
    bool empty() {
        return st.empty();
    }
};
int main() {
    Stack st;
    st.push(20);
    st.push(10);
    st.push(5);
    st.push(30);
    st.push(2);
    cout << st.getMin() << " ";
    st.pop();
    cout << st.getMin() << " ";
    st.pop();
    st.pop();
    cout << st.getMin() << " ";
}
