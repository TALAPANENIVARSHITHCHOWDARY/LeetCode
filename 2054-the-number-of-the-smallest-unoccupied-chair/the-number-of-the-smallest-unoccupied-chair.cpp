class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();

    // Step 1: Sort friends by their arrival times and track their original index.
    vector<pair<int, int>> friends;
    for (int i = 0; i < n; ++i) {
        friends.push_back({times[i][0], i});  // {arrival_time, friend_index}
    }
    sort(friends.begin(), friends.end());  // Sort by arrival times

    // Step 2: Min-heap to manage available chairs.
    priority_queue<int, vector<int>, greater<int>> availableChairs;  // Min-heap for available chairs
    for (int i = 0; i < n; ++i) {
        availableChairs.push(i);  // Initially, all chairs are available
    }

    // Step 3: Min-heap to manage leaving times. {leaving_time, chair_number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingHeap;

    // Step 4: Process friends as they arrive
    for (auto& friendData : friends) {
        int arrivalTime = friendData.first;
        int friendIndex = friendData.second;

        // Free up chairs that are now available (friends who have left)
        while (!leavingHeap.empty() && leavingHeap.top().first <= arrivalTime) {
            int freedChair = leavingHeap.top().second;
            leavingHeap.pop();
            availableChairs.push(freedChair);  // Add the chair back to the available pool
        }

        // Assign the smallest available chair to the current friend
        int assignedChair = availableChairs.top();
        availableChairs.pop();

        // Check if this is the target friend
        if (friendIndex == targetFriend) {
            return assignedChair;  // Return the chair assigned to the target friend
        }

        // Push this friend's leaving time and chair to the leaving heap
        leavingHeap.push({times[friendIndex][1], assignedChair});
    }

    return -1;  // Just a fallback, this line should never be reached
   
    }
};