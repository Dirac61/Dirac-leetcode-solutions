class MedianFinder {
public:
    multiset<int> s;
    MedianFinder() {

    }

    void addNum(int num) {
        s.insert(num);
    }

    double findMedian() {
        if (s.size() % 2 != 0) {
            auto a = s.begin();
                for (int i = 0; i < s.size() / 2; i++) {
                    a++;
            }
                return *a;
        }
        else {
            auto a = s.begin();
            int b=s.size() / 2-1;
            for (int i = 0; i < b; i++) {
                a++;
            }
            return (*(a++) + *a) / 2.0;
        }
    }

};