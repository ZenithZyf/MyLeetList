class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        route_.clear();
        trips_.clear();
        
        for (const auto& t : tickets)
            trips_[t[0]].push_back(t[1]);
        
        for (auto& t : trips_) {
            auto& destinations = t.second;
            std::sort(begin(destinations), end(destinations));
        }
        
        visit("JFK");
        
        return vector<string>(route_.crbegin(), route_.crend());
    }
    
private:
    unordered_map<string, deque<string>> trips_;
    vector<string> route_;
    
    void visit(const string& src) {
        auto& dsts = trips_[src];
        while (!dsts.empty()) {
            const string dst = dsts.front(); dsts.pop_front();
            visit(dst);
        }
        route_.push_back(src);
    }
};
