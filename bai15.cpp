#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string pfx;
    cout << "Nhap bieu thuc hau to: ";
    cin >> pfx;

    stack<int> st;

    for (int i = 0; i < pfx.length(); i++) {
        char c = pfx[i];
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int kq = 0;
            if (c == '+') kq = a + b;
            if (c == '-') kq = a - b;
            if (c == '*') kq = a * b;
            if (c == '/') kq = a / b;
            st.push(kq);
        }
    }

    cout << "Ket qua: " << st.top() << endl;
    return 0;
}
