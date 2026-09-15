class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(m<n)return false;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)freq[s1[i]-'a']++;
        int i=0,j=0;
        vector<int>f(26,0);
        for(;j<n;j++){
            f[s2[j]-'a']++;
        }
        j--;
        while(j<m){
            bool found=true;
            for(int k=0;k<26;k++){
                if(freq[k]!=f[k]){
                    found=false;break;
                }
            }
            if(found){ cout<<i; return true;}
            f[s2[i]-'a']--;
            i++;
            j++;
            if(j<m)f[s2[j]-'a']++;
        }
        return false;
    }
};
