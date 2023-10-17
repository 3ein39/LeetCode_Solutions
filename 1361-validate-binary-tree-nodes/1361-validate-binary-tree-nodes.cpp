#include <bits/stdc++.h>
using namespace std;
class Solution {
    int n;
public:
    int findRoot(vector<int>& leftChild, vector<int>& rightChild) {
        // we can add them to a set for an O(1) checks
        unordered_set<int> childs;
        childs.insert(leftChild.begin(), leftChild.end());
        childs.insert(rightChild.begin(), rightChild.end());
        
        // iterate to check all nodes
        for (int i = 0; i < n; ++i) {
            if (childs.find(i) == childs.end())
                return i;
        }
        return -1;
    }

    bool validateBinaryTreeNodes(int n_, vector<int>& leftChild, vector<int>& rightChild) {
        n = n_;
        // bfs to check if seen nodes is == n
        // we need to fordt get the root, which is a number not present in the 2 arrs
        int root = findRoot(leftChild, rightChild);
        if (root == -1)
            return false;
            
        // bfs code
        queue<int> q;
        unordered_set<int> seen;
        
        q.push(root);
        seen.insert(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                
                
                int ne[] = {leftChild[node], rightChild[node]};
                for (auto& neghbour : ne) {
                    if (neghbour == -1) continue;
                    
                    if (seen.find(neghbour) != seen.end())
                         return false;
                    
                    q.push(neghbour);
                    seen.insert(neghbour);
                }
            }
        }
        return seen.size() == n;
    }
};