#include<bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i < (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define fi          first
#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define Node        ListNode

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

/*
struct Node {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, Node *next) : val(x), next(next) {}
};
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> stack;

        for (const auto &ast: asteroids) {
            check:
            if (stack.empty() || getSign(stack.top()) == getSign(ast) || (getSign(stack.top()) == -1 && getSign(ast) == 1)) stack.push(ast);
            else {
                if (stack.top() == ast * -1) stack.pop();
                else if (stack.top() > ast * -1) continue;
                else {
                    stack.pop();
                    goto check;
                }
            }
        }

        asteroids.clear();
        while (!stack.empty()) {
            asteroids.push_back(stack.top());
            stack.pop();
        }
        reverse(all(asteroids));
        return asteroids;
    }

    int getSign(int x) {
        if (x < 0) return -1;
        else return 1;
    }
};
/* --------------------------------------------------------------- */

