class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int i=0,j=s.size()-1;
        while(i<j){
            char a=s[i],b=s[j];
            bool isaAlpha=false, isbAlpha=false;
            if(a>='A' && a<='Z'){
                a+=32;
                isaAlpha=true;
            }
            if(b>='A' && b<='Z'){
                b+=32;
                isbAlpha=true;
            }
            if((a>='a' && a<='z')|| (a>='0' && a<='9'))isaAlpha=true;
            if((b>='a' && b<='z')|| (b>='0' && b<='9'))isbAlpha=true;
            if(isaAlpha && isbAlpha){
                if(a!=b)return false;
                i++;j--;
            }
            if(!isaAlpha)i++;
            if(!isbAlpha)j--;
        }
        return true;
    }
};