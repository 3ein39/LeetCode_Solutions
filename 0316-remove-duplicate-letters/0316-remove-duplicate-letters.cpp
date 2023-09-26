#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define fi          first
#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
    for (T &x: data)input >> x;
    return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x: data)output << x << " ";
    return output;
}

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

void hussein() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int getBit(int num, int idx) {
    return (num >> idx) & 1;
}

int setBit1(int num, int idx) {
    return num | (1 << idx);
}

int setBit0(int num, int idx) {
    return num & ~(1 << idx);
}

int flibBit(int num, int idx) {
    return num ^ (1 << idx);
}

int firstBitValue(int num) {
    return num & ~(num - 1);
}

int firstBit0(int num) {
    int i = 0;
    while(getBit(num, i) == 1 && i < 32){
        i++;
    }
    return i;
}

int firstBit1(int num) {
    int i = 0;
    while(getBit(num, i) == 0 && i < 32) {
        i++;
    }
    return i;
}

int convertOnes(int num) {
    int i = 0;
    while(getBit(num, i) == 0) {
        num = setBit1(num, i);
        i++;
    }
    return num;
}

int convertZeros(int num) {
    int i = 0;
    while(getBit(num, i) == 1) {
        num = setBit0(num, i);
        i++;
    }
    return num;
}

class Solution {
   public:
    string removeDuplicateLetters(string s) {
		// stack increasing order + frequency + visited array
	    stack<char> st;
	    map<char, int> freq;
	    map<char, bool> visited;
	    for (auto& el : s) {
			freq[el]++;
		    visited[el] = false;
	    }

	    for (auto& el : s) {
	        if (visited[el]) {
	            freq[el]--;
	            continue;
	        }
	        if (!visited[el] && (st.empty() || st.top() < el)) {
	            st.push(el);
	            visited[el] = true;
	            freq[el]--;
	            continue;
	        }

	        while (!st.empty() && st.top() > el && freq[st.top()] > 0) {
	            visited[st.top()] = false;
	            st.pop();
	        }
	        st.push(el);
	        visited[el] = true;
	        freq[el]--;
	    }
	    string ans;
	    while (!st.empty()) {
	        ans += st.top();
	        st.pop();
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
    }
};

// int main() {
//     hussein();

// 	string s = "bcabc";
// 	cout << Solution().removeDuplicateLetters(s);
//     return 0;
// }
