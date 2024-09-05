class MyStack {
public:

// Method 1 : using 2 queue
// Step 1: push x in q2;
// Step 2: transfer q1 -> q2;
// Step 3: transfer q2 -> q1;


// Method 2 : using 1 stack
// Step 1: normally push in q
// Step 2: reverse the queue from starting to q.size()-1;


//----------------- Method 1 ------------
queue<int> q1;
queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return !q1.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */