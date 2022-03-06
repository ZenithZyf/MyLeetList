class MaxStack {
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        v_.push_front(x);
        m_[x].push_back(v_.begin());
    }
    
    int pop() {
        int x = *v_.cbegin();
        m_[x].pop_back();
        if (m_[x].empty()) {
            m_.erase(x);
        }
        v_.erase(v_.cbegin());
        return x;
    }
    
    int top() {
        return *v_.cbegin();
    }
    
    int peekMax() {
        return m_.rbegin()->first;
    }
    
    int popMax() {
        int x = m_.rbegin()->first;
        auto it = m_[x].back();
        m_[x].pop_back();
        if (m_[x].empty()) {
            m_.erase(x);
        }
        v_.erase(it);
        return x;
    }
private:
    list<int> v_;
    map<int, vector<list<int>::iterator>> m_;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
