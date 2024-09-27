class MyCalendarTwo {
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // Check if the new event would cause a triple booking
        for (auto& [o_start, o_end] : overlaps) {
            if (max(o_start, start) < min(o_end, end)) {
                return false; // Triple booking found, return false
            }
        }
        
        // Check for overlaps with already booked events and add to overlaps list
        for (auto& [e_start, e_end] : events) {
            int overlap_start = max(e_start, start);
            int overlap_end = min(e_end, end);
            if (overlap_start < overlap_end) {
                overlaps.push_back({overlap_start, overlap_end});
            }
        }
        
        // Book the new event
        events.push_back({start, end});
        return true; // Successfully booked
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
