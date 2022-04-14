class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        vector<int> time = getTime(timestamp, "Second", true);
        mp[time] = id;
    }
    
    vector<int> retrieve(string start, string end, string gra) {
        vector<int> start_time = getTime(start, gra, false);
        vector<int> end_time = getTime(end, gra, true);
        map<vector<int>, int>::iterator it1 = mp.lower_bound(start_time);
        map<vector<int>, int>::iterator it2 = mp.upper_bound(end_time);
        vector<int> ret;
        for (; it1 != it2; ++it1) {
            ret.push_back(it1->second);
        }
        return ret;
    }
private:
    vector<int> getTime(const string& s, const string &gra, bool is_end) const {
        int index = getIndex(gra);
        istringstream iss(s);
        vector<int> time(6, 0);
        int value = 0;
        char c = ':';
        for (int i = 0; i <= index; ++i) {
            iss >> value;
            time[i] = value;
            iss >> c;
        }
        if (is_end) {
            for (int i = index + 1; i <= 5; ++i) {
                time[i] = getMax(i);
            }
        }
        return time;
    }
    int getIndex(const string& gra) const {
        if (gra == "Year") {
            return 0;
        } else if (gra == "Month") {
            return 1;
        } else if (gra == "Day") {
            return 2;
        } else if (gra == "Hour") {
            return 3;
        } else if (gra == "Minute") {
            return 4;
        } else {
            return 5;
        }
    }
    int getMax(int index) const {
        switch(index) {
            case 1:
                return 12;
            case 2:
                return 31;
            case 3:
                return 23;
            case 4:
                return 59;
            default:
                return 59;
        }
    }
    map<vector<int>, int> mp;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
