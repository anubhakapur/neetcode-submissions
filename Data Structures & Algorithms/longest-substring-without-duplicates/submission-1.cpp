class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0;
        vector<int>freq(256,0);
        int i=0,j=0;
        while(j<n){
            while(freq[s[j]]>0){
                freq[s[i]]--;
                i++;
            }
            freq[s[j]]++;
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};
