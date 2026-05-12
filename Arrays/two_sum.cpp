// two sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            int val = target - nums[i];

            if(mp.find(val) != mp.end() && mp[val] != i){
                return {i, mp[val]};
            }
        }
        return {};
    }
};