// max-profit-by-two-machine,  https://practice.geeksforgeeks.org/problems/max-profit-by-two-machine/1

class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        
        int n = a.size();
        
        vector<pair<int, int>> tasks;
        
        // {difference , idx}
        for(int i = 0; i < n; i++){
            tasks.push_back({abs(a[i] - b[i]), i});
        }
        
        // sort on basis of profit in desc
        sort(tasks.rbegin(), tasks.rend());
        
        int profit = 0;
        
        for(auto & t : tasks){
            
            int i = t.second; 
            
            if(a[i] >= b[i]){
                if(x > 0){
                    profit += a[i];
                    x--;
                }
                else{
                    profit += b[i];
                    y--;
                }
            }
            else{
                if(y > 0){
                    profit += b[i];
                    y--;
                }
                else{
                    profit += a[i];
                    x--;
                }
            }
        }
        return profit;
    }
};