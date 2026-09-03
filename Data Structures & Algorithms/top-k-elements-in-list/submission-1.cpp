class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int &n:nums)freq[n]++;
        vector<vector<int>>buckets(n+1);
        for(auto&it:freq){
            buckets[it.second].push_back(it.first);
        }

        vector<int>res;
        for(int i=n;i>=0;i--){
            for(int n:buckets[i]){
                res.push_back(n);
                if(res.size()==k)return res;
            }
        }
        return res;
    }
};
