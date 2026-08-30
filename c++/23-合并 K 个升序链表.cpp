class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2) {

        ListNode dummy(0);
        ListNode* p = &dummy;
        if (p1 == nullptr) {
            return p2;
        }
        if (p2 == nullptr) {
            return p1;
        }
        for (; p1 != nullptr || p2 != nullptr;) {

            if (p2 != nullptr && (p1 == nullptr || p1->val > p2->val)) {

                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else if (p1 != nullptr && (p2 == nullptr || p2->val >= p1->val)) {

                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }

        }
        return dummy.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        return mergeRange(lists,0,lists.size()-1);
    }
    ListNode* mergeRange(vector<ListNode*>& l, int left, int right) {
        if (left == right) {
            return l[left];
        }
        return merge(mergeRange(l, left, (left + right) / 2), mergeRange(l, (left + right) / 2+1, right));
    }
};