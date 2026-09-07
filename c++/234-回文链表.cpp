class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* p = head;
        ListNode* centre=head;
        ListNode* tail;
        for (; ;) {
            length++;
            if (length % 2 == 0) {
                centre = centre->next;
            }
            if (p->next==nullptr) {
                tail = p;
                break;
            }
            p = p->next;
        }
        p = centre->next;
        centre->next = nullptr;
        for (;;) {
            if (p == nullptr) {
                break;
            }
            ListNode* temp = p->next;
            p->next = centre;
            centre = p;
            p = temp;
        }
        p = head;
        for (;;) {
            if (p->val != tail->val) {
                break;
            }
            // cout<<p->val<<" "<<tail->val<<endl;
            p = p->next;
            tail = tail->next;
            if (p == nullptr || tail == nullptr) {
                return true;
            }
        }
        return false;
    }
};