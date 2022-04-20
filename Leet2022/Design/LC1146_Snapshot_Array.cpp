class SnapshotArray {
public:
    SnapshotArray(int length) {
        id_ = 0;
        vals_ = vector<map<int, int>>(length);
    }
    
    void set(int index, int val) {
        vals_[index][id_] = val;
    }
    
    int snap() {
        return id_++;
    }
    
    int get(int index, int snap_id) {
        auto it = vals_[index].upper_bound(snap_id);
        if (it == begin(vals_[index])) {
            return 0;
        }
        return prev(it)->second;
    }
private:
    int id_;
    vector<map<int, int>> vals_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
