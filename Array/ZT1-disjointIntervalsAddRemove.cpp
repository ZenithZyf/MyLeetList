// function for add
vector<vector<int>> add(vector<vector<int>>& intervals, int from, int to) {
    // vector to store the new disjoint interval
    vector<vector<int>> ans;
    // a flag to check whether the [from, to] interval has been added or not
    bool flag = false;
    
    // go through the original intervals once
    for (int i = 0; i < intervals.size(); ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (from > end) {
            // if current interval ends before from
            ans.push_back(intervals[i]);
            continue;
        } 
        
        if (to < start) {
            // under the situation that from < intervals[i][1]
            // if current interval starts early than to
            // then [[from, to], intervals[i]] must be disjoint
            // push [from, to] to answer and set the flag to true
            ans.push_back({from, to});
            flag = true;
            // we just need to add all remaining intervals
            for (int j = i; j < intervals.size(); ++j)
                ans.push_back(intervals[j]);
            break;
        }
        
        // under the situation that current interval and [from, to] has intersections
        // we just need to combine them as a 'new' [from, to]
        // and move on to next iteration
        from = std::min(from, start);
        to = std::max(to, end);
    }
    
    // in case that [from, to] is not added
    if (!flag)
        ans.push_back({from, to});
    
    return ans;
}

// function for remove
vector<vector<int>> remove(vector<vector<int>>& intervals, int from, int to) {
    // vector to store the new disjoint interval
    vector<vector<int>> ans;

    // go through the original intervals once
    for (int i = 0; i < intervals.size(); ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        
        if (from >= end || to <= start) {
            // if current interval ends before from or starts after to
            ans.push_back(intervals[i]);
        } else if (from > start && to < end) {
            // if current interval contains the interval to be removed
            ans.push_back({start, from});
            ans.push_back({to, end});
        } else if (from > start && to >= end) {
            // if current interval and the interval to be removed
            // has an intersection
            ans.push_back({start, from});
        } else if (from <= start && to < end) {
            // if current interval and the interval to be removed
            // has an intersection
            ans.push_back({to, end});
        }
    }
    
    return ans;
}
