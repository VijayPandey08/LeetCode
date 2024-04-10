class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int i=0;
        int j=0;
        vector<int> temp(deck.size(),0);
        sort(deck.begin(),deck.end());
        bool flag = false;
        while(i<deck.size()){
            if(temp[j]==0){
                if(flag==false){
                    temp[j]=deck[i];
                    i++;
                }
                flag=!flag;
            }
            j = (j+1)%deck.size();
        }
        return temp;
    }
};