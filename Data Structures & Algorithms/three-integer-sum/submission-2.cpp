class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=0-nums[i]-nums[j];
                if(mp.find(diff)!=mp.end()){
                    if(mp[diff]!=i && mp[diff]!=j){
                        vector<int>temp={nums[i],nums[j],diff};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
                mp[nums[j]]=j;
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};
