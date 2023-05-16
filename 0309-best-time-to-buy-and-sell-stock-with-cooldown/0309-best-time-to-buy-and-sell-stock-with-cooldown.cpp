// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <climits>
using namespace std;

/*

This is a direct pick or leave problem, with 2 constraints to respect

What is our state?
	- We need to know the item idx (to apply pick or leave)
	- We need to know if we have a stock item or not  (2 cases)
		- According to the problem: you can sell if you have item
									you can buy if you don't have an item
									at any point of time: you have [0-1] item

	- Constraint: If we will buy, then the previous day CAN'T be sell
		- So part of our history is the transaction type which is 3 cases

So the state has the 3 items below in the DP

Let's state that again
	Like knapsack and LIS, we need to pass our history to the sub-calls
	History here includes: Do we have a stock item? What is the last transaction type?

Action cost:
	If you will buy, then -price. If you sell, then profit is the price


Now, apply pick or leave, respecting the 2 constraints

Tip: we can write the code in different ways.
I guess mine is easy to understand and get



 */

const int MAX = 5000 + 1;
int memory[MAX][2][3];
vector<int> prices;

enum {
	NOTHING = 0, SELL = 1, BUY = 2
};

class Solution {
public:
	int trade(int idx, int have_stock, int last_transaction) {
		if (idx == (int) prices.size())
			return 0;

		auto &ret = memory[idx][have_stock][last_transaction];
		if (ret != -1)
			return ret;

		int do_nothing = trade(idx + 1, have_stock, NOTHING);
		int buy = 0, sell = 0;

		if (have_stock)						// can sell
			sell = prices[idx] + trade(idx + 1, 0, SELL);
		if (last_transaction != SELL)	// can buy under 2 conditions
			buy = -prices[idx] + trade(idx + 1, 1, BUY);

		return ret = max(max(buy, sell), do_nothing);
	}

	int maxProfit(const vector<int> &prices_) {
		prices = prices_;
		memset(memory, -1, sizeof(memory));
		return trade(0, 0, NOTHING);
	}
};

// int main() {
// 	Solution s;
// 	cout << s.maxProfit( { 1, 2, 3, 0, 2 });

// 	return 0;
// }
