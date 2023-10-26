#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Node {
        public:
         Node* next;
         int val, min;

         Node(Node* next, int val, int min) {
            this->val = val;
            this->next = next;
            this->min = min;
        }
    };

class MinStack {
    Node* head;
    Node* tail;
    int mn;
public:
    MinStack() {
        // sz = 0;
        head = nullptr;
        
    }
    
    void push(int val) {
        // mn = min(val, mn);
        
       if (head != nullptr)
             head = new Node(head, val, min(head->min, val));
        else 
            head = new Node(nullptr, val, val);
        
    }
    
    void pop() {
        // sz - 1
        head = head->next;
    }
    
    int top() {
        // tail
        return head->val;
    }
    
    int getMin() {
        // tail
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
