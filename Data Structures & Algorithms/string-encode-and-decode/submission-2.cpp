#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(int i=0;i<strs.size();i++){
            res+=to_string(strs[i].length())+"#"+strs[i];
        }
        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        for(int i=0;i<s.length();i++){
            int j=i;
            while(j<s.length() && s[j]!='#')j++;
            int len=stoi(s.substr(i,j-i));
            string temp=s.substr(j+1,len);
            res.push_back(temp);
            i=j+len;
        }
        return res;
    }
};
