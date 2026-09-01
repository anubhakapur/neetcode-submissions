class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());
        int i=0,j=n-1;
        while(i<j){
            if(pairs[i].first+pairs[j].first==target)
                return {min(pairs[i].second,pairs[j].second),
                max(pairs[i].second,pairs[j].second)};
            else if (pairs[i].first+pairs[j].first>target)j--;
            else i++;
        }
        return {-1};
    }
};
