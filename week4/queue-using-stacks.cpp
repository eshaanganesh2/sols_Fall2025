class MyQueue {
public:
    stack<int>stk1;
    stack<int>stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        int result=peek();
        stk2.pop();
        return result;
    }
    
    int peek() {
        int result;
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            result=stk2.top();
        }
        else{
            result=stk2.top();
        }
        return result;
    }
    
    bool empty() {
        return stk1.empty()&&stk2.empty();
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
