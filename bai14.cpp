#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int uuTien(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    string in, out = "";
    stack<char> st;

    cout << "Nhap bieu thuc trung to: ";
    cin >> in;

    for (int i = 0; i < in.length(); i++) {
        char c = in[i];
        if (isalnum(c)) out += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top();
                st.pop();
            }
            st.pop(); // bo dau (
        } else {
            while (!st.empty() && uuTien(st.top()) >= uuTien(c)) {
                out += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        out += st.top();
        st.pop();
    }

    cout << "Bieu thuc hau to: " << out << endl;
    return 0;
}

