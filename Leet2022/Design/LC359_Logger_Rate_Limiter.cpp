class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < m_[message]) {
            return false;
        }
        m_[message] = timestamp + 10;
        return true;
    }
private:
    unordered_map<string, int> m_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
