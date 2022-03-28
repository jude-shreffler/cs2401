/// stacks are last in first out, like a tower
#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    while (st.empty() == false) {
        st.pop();
    }

    return 0;
}