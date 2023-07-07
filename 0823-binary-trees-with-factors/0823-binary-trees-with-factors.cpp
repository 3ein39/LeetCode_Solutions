
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*

 Let's define cnt_trees(x): Return how many trees that has x as a root

 Then the answer is: the sum for all cnt_trees(x) for the input values

 Assume we have number like 12
 we know 12 = 1 * 12 = 2 * 6 = 3 * 4

 If we know that there are say 10 ways for F(3) and 20 ways for F(4)
 then we have F(3) * F(4) ways to make 12

 So the key idea is
 Find all pairs a, b such that x = a * b
 then accumulate F(a) * F(b)
 */

const int MOD = 1000000007;
typedef long long ll;

unordered_set<int> nums_set;
unordered_map<int, ll> memory;	// we can save in int, but will need casting

// Return how many trees that has x as a root
ll cnt_trees(int x) {	// O(N^2) where N is input array size
	if (memory.count(x))
		return memory[x];

	ll cnt = 1;	// use as a leaf

	// Find all my divisors x = a * b, then F(a) * F(b) are possible solutions
	for (auto i : nums_set)
		if (x % i == 0 && nums_set.count(x / i)) {	// x = a * b
			// Carefully handle overflows
			auto sub_trees = (cnt_trees(i) * cnt_trees(x / i)) % MOD;
			cnt += sub_trees;
			cnt %= MOD;
		}
	return memory[x] = cnt;
}

class Solution {
public:
	int numFactoredBinaryTrees(const vector<int> &A) {
		// leetcode share global variables between cases. you must clean
		nums_set.clear();
		memory.clear();
		nums_set.insert(A.begin(), A.end());

		ll sum = 0;
		for (auto x : nums_set) {
			sum += cnt_trees(x);
			sum %= MOD;
		}
		return sum;
	}
};

// int main() {
// 	cout<<Solution().numFactoredBinaryTrees({15,13,22,7,11});	// 5

// 	return 0;
// }
