class MyCalendar {
private:
    vector<pair<int, int>> bookings;  // To store booked intervals as pairs of (start, end)
    
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        // Check if the new event conflicts with any existing event
        for (const auto& booking : bookings) {
            // booking.first = start of existing event
            // booking.second = end of existing event
            if (max(booking.first, start) < min(booking.second, end)) {
                // Overlap detected
                return false;
            }
        }
        
        // No overlap, so we can safely book the event
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
