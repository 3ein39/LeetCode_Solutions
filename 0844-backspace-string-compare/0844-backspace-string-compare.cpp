#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        for (auto& el : s) {
            if (el == '#') {
                if (!a.empty()) a.pop();
            }
            else 
                a.push(el);
        }
        
        for (auto& el : t) {
            if (el == '#') {
                if (!b.empty()) b.pop();
            }
            else 
                b.push(el);
        }
        
        string s1, s2;
        while (!a.empty()) {
            s1.push_back(a.top());
            a.pop();
        }
        
        while (!b.empty()) {
            s2.push_back(b.top());
            b.pop();
        }
        
        return s1 == s2;
    }
};
