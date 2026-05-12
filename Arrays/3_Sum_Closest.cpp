// 3 sum closest in c++

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n-2; i++) {

            int l = i + 1;
            int r = n - 1;
            
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(target - sum) < abs(target - result)){
                    result = sum;
                }

                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return result;
    }   
};