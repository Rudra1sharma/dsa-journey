// today potd

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt = 0;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1] ){
                cnt++;
            }
        }
        if(cnt == 1 && nums[n-1] == nums[n-2] && nums[n-1] == n-1){
            return true;
        }
        return false;
    }
};