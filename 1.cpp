class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (m.find(temp) != m.end()) {
                result.push_back(m[temp]);
                result.push_back(i);
                return result;
            }
            m[nums[i]] = i;
        }
    return result;
    }
};
