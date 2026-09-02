class Solution{
public:
    Node * copyRandomList(Node * head) {
        unordered_map<Node*, int> m1;
        unordered_map<int, Node*> m2;
        Node* p1 = head;
        Node* h = new Node(0);
        Node* p2 = h;
        for (int i = 0; p1 != nullptr; i++) {
            p2->next = new Node(p1->val);
            m1.insert(pair<Node*, int>(p1, i));
            m2.insert(pair<int, Node*>(i, p2->next));
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = head;
        p2 = h->next;
        for (int i = 0; p1 != nullptr; i++) {
            if (p1->random == nullptr) {
                p2->random = nullptr;
            }
            else {
                p2->random = m2.find(m1.find(p1->random)->second)->second;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        return h->next;
    }
};