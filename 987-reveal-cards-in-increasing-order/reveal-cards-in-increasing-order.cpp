class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // int i=0; // TO ITERATE DECK
        // int j=0; // TO ITERATE RESULT
        // vector<int> temp(deck.size(),0); // ISME ANSWER STORE KRUNGA
        // sort(deck.begin(),deck.end());  // DECK KO SORT KRO..
        // bool flag = false; // EK FLAG BANA DIA KI Jth index pe answer bharunga nahi
        // while(i<deck.size()){ // deck ka hr ek element jab daal denge tab answer ban jaaega
        //     if(temp[j]==0){ // temp vector mein pehle se sab zero kar dia tha.. ab jab zero hoga tab hi dalenge
        //         if(flag==false){ // plus plag bhi false hona chahiye tab hi dalenge
        //             temp[j]=deck[i];
        //             i++; // main deck mein aage badh jaao jab daldo ek cheez
        //         }
        //         flag=!flag; // frr flag ko vapas se set kr do opposite, taki agli baar na dalo ya alternate krke hi dalo
        //     }
        //     j = (j+1)%deck.size(); // Jth index ko ese bdhana h ki ek loop mein rkhna h
        // }
        // return temp; 
// approach 2

queue<int> dq;
vector<int> ans(deck.size());

sort(deck.begin(),deck.end());

for(int i=0; i<deck.size(); i++){
    dq.push(i);
}

for(int i=0; i<deck.size(); i++){
    int val = dq.front();
    dq.pop();

    ans[val]= deck[i];

    if(!dq.empty()){
    dq.push(dq.front());
    dq.pop();
    }

}
return ans;

    }
};