class MyQueue {

// it has 2 methods 

// method 1 : heavy push
// step 1: s1 -> s2
// step 2: s1.push(x);
// step 3: s2 -> s1;

// method 2: heavy push , pop
// step 1: s1.push(x);
// if(!s2.empty()){
//   top , pop from here
// }
// else{
//    s1 -> s2;
//    sontinue your stuff;  
//}


// ------------- method 1 --------------

stack<int> s1;
stack<int> s2;


public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */