class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        for (;;) {

            p1->val += p2->val;
            if (p1->val >= 10) {
                p1->val = p1->val % 10;
                if (p1->next != nullptr) {
                    p1->next->val++;
                    if (p1->next->val >= 10) {
                        ListNode* p3 = p1->next;
                        for (;p3!=nullptr;) {
                            if (p3->val >= 10) {
                                p3->val = p3->val % 10;
                                if (p3->next != nullptr) {
                                    p3->next->val++;
                                }
                                else {
                                    p3->next = new ListNode(1);
                                }
                            }
                            p3 = p3->next;
                        }
                    }
                }
                else {
                    p1->next = new ListNode(1);
                }
            }
            if (p1->next == nullptr) {
                p1->next = p2->next;
                break;
            }
            if (p2->next == nullptr) {
                break;
            }
            p1 = p1->next;
            p2 = p2->next;

        }
        return l1;
    }
};