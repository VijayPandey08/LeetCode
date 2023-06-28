class Solution {
public:
    int strStr(string haystack, string needle) {
        
       int n = needle.length();
        int m = haystack.length();
        for(int i=0; i<m-n+1; i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j]!=needle[j]) break;
                if(j==n-1)  return i;
            }
        }

        return -1;
    }
};