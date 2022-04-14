class TweetCounts {
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        user[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int length = 0;
        if (freq == "minute")
            length = 60;
        else if (freq == "hour")
            length = 60 * 60;
        else
            length = 60 * 60 * 24;
        vector<int> ans((endTime - startTime) / length + 1);
        auto begin = user[tweetName].lower_bound(startTime);
        auto end = user[tweetName].upper_bound(endTime);
        for (; begin != end; ++begin) {
            ++ans[(*begin - startTime) / length];
        }
        return ans;
    }
private:
    map<string, multiset<int>> user;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
