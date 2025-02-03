#include <iostream>

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

        ListNode* curr = head;
        int no = 0;
        while (curr != nullptr) {
            no++;
            curr = curr->next;
        }

        n = no-n;
        if (n == 0) head = head->next;
        else {
            curr = head;
            while (n > 1) {
                n--;
                curr = curr->next;
            }
            curr->next = curr->next->next;
        }

        return head;
    }
};

int main () {

    return 0;
}