class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size_ = size;
        sum_ = 0;
    }
    
    double next(int val) {
        if (q_.size() >= size_) {
            sum_ -= q_.front(); q_.pop();
        }
        q_.push(val);
        sum_ += val;
        return sum_ / q_.size();
    }
private:
    queue<int> q_;
    int size_;
    double sum_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
