#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == nullptr) return false;
            ListNode *tortoise = head;
            ListNode *hare = head;
    
            while (hare->next != nullptr && hare->next->next != nullptr) {
                hare = hare->next->next;
                tortoise = tortoise->next;
                if (tortoise == hare) return true;
            }
            return false;
            
        }
    };

int main () {
    return 0;
}