class MinStack {
public:
    stack<long> min;
    stack<long> assisted;
    MinStack() {

    }

    void push(int val) {
        min.push(val);
        if (assisted.empty()) {
            assisted.push(val);
            return;
        }
        if (assisted.top() < val) {
            assisted.push(assisted.top());
        }
        else {
            assisted.push(val);
        }
    }

    void pop() {
        min.pop();
        assisted.pop();
    }

    int top() {
        return min.top();
    }

    int getMin() {
        return assisted.top();
    }
};