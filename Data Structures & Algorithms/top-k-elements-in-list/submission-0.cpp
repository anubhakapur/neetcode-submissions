class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int &n:nums)freq[n]++;
        vector<pair<int,int>>pairs;
        for(auto&it:freq){
            pairs.push_back({it.first,it.second});
        }
        sort(pairs.begin(),pairs.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(pairs[i].first);
        }
        return res;
    }
};
