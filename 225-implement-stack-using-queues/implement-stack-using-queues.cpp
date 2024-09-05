class MyStack {
public:

// Method 1 : using 2 queue
// Step 1: push x in q2;
// Step 2: transfer q1 -> q2;
// Step 3: transfer q2 -> q1;


// Method 2 : using 1 stack
// Step 1: normally push in q
// Step 2: reverse the queue from starting to q.size()-1;


//----------------- Method 2 ------------

queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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