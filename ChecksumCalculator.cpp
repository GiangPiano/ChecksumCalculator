// TODO
// 1. If the length of the two strings is not equal, then return -1.

#include<bits/stdc++.h>
using namespace std;

string Sum(string a, string b) {
    if(a.length() != b.length())
        return "Size not equal";

    string sum(a.length(), '0');
    int remain = (int) '0';
    for (int i = a.size() - 1; i >= 0; i--) {
        sum[i] = a[i] ^ b[i] ^ remain;
        remain = (a[i] & b[i]) | (remain & a[i]) | (remain & b[i]);
    }
    if (remain == '1')
        sum = Sum(sum, string(a.length() - 1, '0') + '1');
    return sum;
}

string Invert(string a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = (a[i] == '0') ? '1' : '0';
    }
    return a;
}

int main() {
    while (true) {
        string a, b;
        cout << "Enter first binary number: "; cin >> a;
        cout << "Enter second binary number: "; cin >> b;
        if (a.length() != b.length()) { 
            cout << "Size not equal\n";
            continue;
        }
        cout << "Result: " << Invert(Sum(a, b)) << '\n';
    }
}