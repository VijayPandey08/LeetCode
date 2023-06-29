class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        if(b==0){
            return a;
            ans=a;
    
        }
        if(a==0){
            return b;
            ans=b;
        }
        if(a==0&&b==0){
            return a;
            ans=a;
        }

        if(a<0 && b>0 || a>0 && b>0){
        for(int i=1; i<=b; i++){
            a++;
        }
        return a;
        ans=a;

        }

        if(b<0 && a>0){
        for(int i=1; i<=a; i++){
            b++;
        }
        return b;
        ans=b;
        }

        if(a<0 && b<0){
            for(int i=a; i<0; i++){
                b--;
            }
            return b;
            ans=b;
        }

        return ans;
    }
};