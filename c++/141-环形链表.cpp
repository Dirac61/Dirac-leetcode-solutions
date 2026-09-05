class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast=head;
        ListNode* low = head;
        for (; fast != nullptr;) {
            fast = fast->next;
            if (fast == low) {
                return true;
            }
            if (fast == nullptr || fast->next==nullptr) {
                return false;
            }
            fast = fast->next;
            if (fast == low) {
                return true;
            }
            low = low->next;
            if (fast == low) {
                return true;
            }
        }
        return false;
    }
};