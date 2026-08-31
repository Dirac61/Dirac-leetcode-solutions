class Solution {
public:
    pair<ListNode*, ListNode*> merge(ListNode* p1, ListNode* p2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        for (; p1 != nullptr || p2 != nullptr;) {
            // cout<<p1->val<<endl;
            // cout<<p2->val<<endl;
            if (p2!=nullptr&&(p1 == nullptr || p1->val > p2->val)) {
                // cout<<p2->val<<endl;
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else if (p1!=nullptr&&(p2 == nullptr || p2->val >= p1->val)) {
                // cout<<p1->val<<endl;
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }

        }
        return pair<ListNode*, ListNode*>(dummy.next, p);

    }
    ListNode* sortList(ListNode* head) {
        int size=0;
        int length = 1;
        ListNode* p = head;
        ListNode* h = new ListNode(0, head);
        ListNode* res = h;
        for (;p!=nullptr;) {
            size++;
            p = p->next;
        }

        for (; length < size;) {
            p = res->next;
            h=res;
            for (; p != nullptr;) {
                ListNode* p1 = p;
                for (int i = 0; p != nullptr; i++) {
                    if (i == length - 1) {
                        ListNode* temp = p;
                        p = p->next;
                        temp->next = nullptr;
                        break;
                    }
                    else {
                        p = p->next;
                    }
                }
                ListNode* p2 = p;
                for (int i = 0; p != nullptr; i++) {
                    if (i == length - 1) {
                        ListNode* temp = p;
                        p = p->next;
                        temp->next = nullptr;
                        break;
                    }
                    else {
                        p = p->next;
                    }
                }
                pair<ListNode*, ListNode*> entry = merge(p1, p2);
                entry.second->next = p;

                h->next = entry.first;

                h = entry.second;
                // cout << "切割链表" << endl;
            }
            length = length * 2;
            // cout << "下一组链表合并" << endl;
        }
        // cout<<res->next->val<<endl;
        return res->next;

    }
};