#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::stack<int> st;
        std::unordered_map<int, int> mep;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mep[nums2[i]] = -1;
            } else {
                mep[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = mep[nums1[i]];
        }

        return nums1;
    }
};
