// sum of XOR of all pairs in c++ by calcuting the contribution of each bit

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        long long ans = 0;
        
        for(int bit = 0; bit < 32; bit++){
            long long ones = 0;
            
            for(int i = 0; i < n; i++){
                if(arr[i] & (1 << bit)){
                    ones++;
                }
            }
            long long zeros = n - ones;
            
            ans += (ones * zeros * (1LL << bit));
        }
        
        return ans;
    }
};