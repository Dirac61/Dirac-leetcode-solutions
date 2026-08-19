class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> v;
        v.resize(numCourses,0);
        for (int i = 0; i < prerequisites.size(); i++) {
            v[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int count=0;count<numCourses;count++) {

            auto a = find(v.begin(), v.end(), 0);
            if (a != v.end()) {

                auto b = m.find(a-v.begin());
                if (b != m.end()) {
                    for (int i : b->second) {

                        v[i]--;
                    }
                }
                *a=-1;
            }
            else if (count<numCourses) {
                return false;
            }
        }
        return true;
    }
};