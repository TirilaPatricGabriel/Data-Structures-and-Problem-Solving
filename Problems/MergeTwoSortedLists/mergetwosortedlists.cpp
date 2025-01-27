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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* head = new ListNode(), *curr;
        curr = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->val = list1->val;
                list1 = list1->next;
            } else {
                curr->val = list2->val;
                list2 = list2->next;
            }

            if (list1 != nullptr || list2 != nullptr) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        while (list1 != nullptr) {
            curr->val = list1->val;
            list1 = list1->next;

            if (list1 != nullptr) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        while (list2 != nullptr) {
            curr->val = list2->val;
            list2 = list2->next;
            if (list2 != nullptr) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        return head;
    }
};

int main () {
    return 0;
}