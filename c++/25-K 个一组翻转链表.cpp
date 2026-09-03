class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* h=new ListNode(0,head);
        ListNode* res = h;
        ListNode* t = nullptr;
        ListNode * p = head;
        for (int i=1;; i++) {
            if (i % k == 0) {
                t = p->next;
                ListNode* l1 = h->next;
                ListNode* l2 = l1->next;
                ListNode* l4 = l1;
                l1->next = t;
                for (;;) {

                    if (l2 != t) {
                        // cout<<l1->val<<" "<<l2->val<<endl;
                        ListNode* l3 = l2->next;
                        l2->next = l1;
                        l1 = l2;
                        l2 = l3;
                    }
                    else {
                        break;
                    }
                }

                h->next = l1;
                h = l4;
                p=h;
                // cout<<h->val<<endl;
            }
            if (p->next == nullptr) {
                return res->next;
            }
            else {
                p = p->next;
            }
        }
        return res->next;
    }
};