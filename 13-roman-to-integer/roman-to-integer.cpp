class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int total = 0;

        for(int i=0; i<s.length(); i++){
            if(i<=s.length()-1){
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')){
                total -= m['I'];
                continue;
                
            }
            if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){
                total -=  m['X'];
                continue;
            }
            if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                total -= m['C'];
                continue;
            }
            }
            total+=m[s[i]];
        }

        return total;
    }
};