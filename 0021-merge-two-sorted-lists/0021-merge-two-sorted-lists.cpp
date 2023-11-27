#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
	for (T &x : data)input >> x;
	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
	for (const T &x : data)output << x << " ";
	return output;
}

void hussein() {
	improve;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}


// time  : O(n)
// space : O(n)
class Solution {
  public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head,* cur;
		
		if (!list1)
			return list2;
		if (!list2)
			return list1;

		if (list1->val <= list2->val)
			head = list1, list1 = list1->next;
		else
			head = list2, list2 = list2->next;

		cur = head;
		while (list1 && list2) {
			if (list1->val <= list2->val)
				cur->next = list1, cur = cur->next, list1 = list1->next;
			else
				cur->next = list2, cur = cur->next, list2 = list2->next;
		}

		while (list1)
			cur->next = list1, cur = cur->next, list1 = list1->next;

		while(list2)
			cur->next = list2, cur = cur->next, list2 = list2->next;

		return head;
	}
};

