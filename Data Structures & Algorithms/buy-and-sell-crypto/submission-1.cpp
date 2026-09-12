class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int n=prices.size();
        int costPrice=prices[0];
        for(int i=0;i<n;i++){
            costPrice=min(costPrice,prices[i]);
            res=max(res,prices[i]-costPrice);
        }
        return res;
    }
};
