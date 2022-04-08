class ExamRoom {
public:
    ExamRoom(int n) : N_(n) {}
    
    int seat() {
        int p = 0;
        int max_dist = s_.empty() ? 0 : *s_.begin();
        auto left = s_.begin();
        auto right = left;
        while (left != s_.end()) {
            ++right;
            int l = *left;
            int r = right != s_.end() ? *right : (2 * (N_ - 1) - *left);
            int d = (r - l) / 2;
            if (d > max_dist) {
                max_dist = d;
                p = l + d;
            }
            left = right;
        }
        s_.insert(p);
        return p;
    }
    
    void leave(int p) {
        s_.erase(p);
    }
    
private:
    const int N_;
    set<int> s_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
