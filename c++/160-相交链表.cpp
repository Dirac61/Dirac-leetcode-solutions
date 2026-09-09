class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int l1=0;
        int l2=0;
        ListNode* p = headA;
        for (; p != nullptr;) {
            l1++;
            p = p->next;
        }
        p = headB;
        for (; p != nullptr;) {
            l2++;
            p = p->next;
        }
        ListNode* A = headA;
        ListNode* B = headB;
        if (l1 < l2) {
            for (int i = 0; i < l2 - l1; i++) {
                B = B->next;
            }
        }
        else {
            for (int i = 0; i < l1 - l2; i++) {
                A = A->next;
            }
        }
        for (int i = 0; i < l1 && i < l2; i++) {
            if (A == B) {
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return nullptr;
    }
};