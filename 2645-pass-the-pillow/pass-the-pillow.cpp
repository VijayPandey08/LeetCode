class Solution {
public:
    int passThePillow(int n, int time) {
        int temp = n-1;

        int dir = (time/temp);
        int rem = (time%temp);
        cout<<dir<<endl;
        cout<<rem<<endl;

        if(dir%2==0){
         return (rem+1);
        }
        else{
            return (n-rem);
        }

        return dir;
    }
};