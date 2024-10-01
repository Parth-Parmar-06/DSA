#include<bits/stdc++.h>
using namespace std;
class Stack {
public:
    stack<pair<int,int>> st;
    void push(int ele) {
        if (st.empty()) st.push({ele, ele});
        else st.push({ele, min(ele, st.top().second)});
    }
    int getMin() {
        return st.top().second;
    }
    void pop() {
        st.pop();
    }
    int top() {
        st.top().first;
    }
    bool empty() {
        st.empty();
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
