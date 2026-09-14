class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=1;
        vector<int>freq(26,0);
        int i=0,j=0;
        int maxFreq=1;
        int totalFreq=0;
        while(j<s.length()){
            freq[s[j]-'A']++;
            totalFreq++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            while(totalFreq-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
                totalFreq--;
                maxFreq=0;
                for(int i=0;i<26;i++)maxFreq=max(maxFreq,freq[i]);
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};
