#include <bits/stdc++.h>

using namespace std;

#define ull         unsigned long long
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define allr(v)     (v).rbegin(), (v).rend()
#define pb          push_back
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

void hussein() {
	improve;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/
class RandomizedSet {
    unordered_map<int, int> hashMap; // {el, indx in arr}
    vector<int> v;
   public:
    RandomizedSet() {
        
    }

    bool insert(int val) {
		bool notFound = hashMap.count(val);

	    if (!notFound) {
	      hashMap[val] = v.size();
	      v.push_back(val);
	    }

	    return !notFound;
    }

    bool remove(int val) {
		bool found = hashMap.count(val);
        // cout << v << endl;
	    if (found) {
	      auto idx = hashMap[val];
	      v[idx] = v.back();
	      v.pop_back();
	      hashMap[v[idx]] = idx;
	      hashMap.erase(val);
	    }
        // cout << v<<endl<<endl;
	    return found;
    }

    int getRandom() {
		auto idx = rand() % (v.size() == 0 ? 1 : v.size());
	    return v[idx];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */