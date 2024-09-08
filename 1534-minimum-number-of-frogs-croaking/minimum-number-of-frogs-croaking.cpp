class Solution {
public:
    int minNumberOfFrogs(string a) {
        int maxi = 0;
        int sum = 0;
        string s = "croak";
        multiset<char> m;
        for(int i = 0;i<a.length();i++){
            if(a[i]=='c'){
                sum++;
                m.insert(a[i]);
            }
            else if(a[i]=='r'){
                if(m.find('c')==m.end()){
                    return -1;
                }
                m.erase(m.find('c'));
                m.insert('r');
            }
            else if(a[i]=='o'){
                if(m.find('r')==m.end()){
                    return -1;
                }
                m.erase(m.find('r'));
                m.insert('o');

            }
            else if(a[i]=='a'){
                if(m.find('o')==m.end()){
                    return -1;
                }
                m.erase(m.find('o'));
                m.insert('a');

            }
            else if(a[i]=='k'){
                if(m.find('a')==m.end()){
                    return -1;
                }
                m.erase(m.find('a'));
                sum--;
            }
            maxi = max(maxi,sum);
        }
        if(m.size()>0) return -1;
        return maxi;

    }
};