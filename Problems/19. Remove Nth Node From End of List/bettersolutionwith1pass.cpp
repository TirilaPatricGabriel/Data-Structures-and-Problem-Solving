#include <iostream>
#include <unordered_map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        unordered_map<int, ListNode*> map;

        ListNode* curr = head;
        int no = 0;
        while (curr != nullptr) {
            map[no] = curr;
            no++;
            curr = curr->next;
        }

        n = no - n;

        if (n == 0) head = head->next;
        else {
            curr = map[n-1];
            curr->next = curr->next->next;
        }

        return head;
    }
};

int main () {

    return 0;
}