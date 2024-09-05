class MyQueue
{

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


// ------------------------------- method 2 ----------------

    public:
        stack<int> s1,s2;
        
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int pop = -1;
        if (!s2.empty())
        {
            pop = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }

    int peek()
    {
        int top = -1;
        if (!s2.empty())
        {
            top = s2.top();
            
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            top = s2.top();
        }
        return top;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 *Your MyQueue object will be instantiated and called as such:
 *MyQueue* obj = new MyQueue();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->peek();
 *bool param_4 = obj->empty();
 */