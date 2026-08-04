class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int size = nums1.size() + nums2.size();
        int pos1 = 0;
        int pos2 = 0;
        for (; v.size() <= size / 2;) {
            if (pos2==nums2.size()||(pos1<nums1.size()&&nums1[pos1] < nums2[pos2])) {
                v.push_back(nums1[pos1]);
                pos1++;
            }
            else {
                v.push_back(nums2[pos2]);
                pos2++;
            }
        }
        if (size % 2 == 0) {
            return (v[size / 2-1] + v[size / 2 ]) * 1.0 / 2;
        }
        else {
            return v[size / 2];
        }
    }
};