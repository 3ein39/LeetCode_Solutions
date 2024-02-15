#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lp(n) for (ll i = 0; i < (n); ++i)
#define lp1(n) for (ll i = 1; i <= (n); ++i)
#define tc         \
  ll testcase;     \
  cin >> testcase; \
  while (testcase--)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define watch(num) cout << #num << ": " << num << "\n";
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define improve                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
	for (T &x : data) input >> x;
	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
	for (const T &x : data) output << x << " ";
	return output;
}

void hussein() {
	improve;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
class Trie {
  public:
	// hashmap for storing the graph
	unordered_map<int, Trie*> tree;
	bool isLeaf;
	Trie() {
		isLeaf = false;
	}

	void insert(string word, int idx = 0) {
		// base case
		if (idx == word.size()) {
			isLeaf = true;
		}
		else {
			// ascii of the char
			int char_ascii = word[idx] - 'a';
			if (!tree.count(char_ascii))
				tree[char_ascii] = new Trie();
			tree[char_ascii]->insert(word, idx + 1);
		}
	}

	bool search(string word, int idx = 0) {
		if (idx == word.size()) {
			return isLeaf;
		}
		int char_ascii = word[idx] - 'a';
		if (!tree.count(char_ascii))
			return false;
		return tree[char_ascii]->search(word, idx + 1);
	}

	bool startsWith(string word, int idx = 0) {
		if (idx == word.size()) {
			return true;
		}
		int char_ascii = word[idx] - 'a';
		if (!tree.count(char_ascii))
			return false;
		return tree[char_ascii]->startsWith(word, idx + 1);
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// int main() {
// 	hussein();

// 	// test the trie
// 	Trie* obj = new Trie();
// 	obj->insert("apple");
// 	cout << obj->search("apple") << endl;   // returns true
// 	cout << obj->search("app") << endl;     // returns false
// 	cout << obj->startsWith("app") << endl; // returns true
// 	obj->insert("app");
// 	cout << obj->search("app") << endl; // returns true


// 	return 0;
// }
