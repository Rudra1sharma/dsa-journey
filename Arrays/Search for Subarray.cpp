// using KMP algorithm; search for subarray in an array

class Solution {
  public:
  
    vector<int> buildLPS(vector<int>& b){
        int m = b.size();
        
        vector<int> lps(m, 0);
        
        int len = 0;
        int i = 1;
        
        while(i < m){
            if(b[i] == b[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        
        vector<int> lps = buildLPS(b);
        
        vector<int> ans;
        
        int i = 0; // for a
        int j = 0; // for b
        
        while(i < n){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            // full-match found
            if(j == m){
                ans.push_back(i - m);
                j = lps[j - 1];
            }
            else if(i < n && a[i] != b[j]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};