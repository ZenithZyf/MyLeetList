class MovingAverage {
public:
    MovingAverage(int size) {
        size_ = size;
        sum_ = 0;
    }
    
    double next(int val) {
        if (qval_.size() >= size_) {
            sum_ -= qval_.front();
            qval_.pop();
        }
        qval_.push(val);
        sum_ += val;
        return sum_ / qval_.size();
    }
private:
    queue<int> qval_;
    int size_;
    double sum_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
