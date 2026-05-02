class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        vector<int> starts(n), ends(n);

        // Separate start times and end times
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }

        // Sort both arrays
        // starts -> when meetings begin
        // ends   -> when meetings finish
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;     // number of rooms required
        int endPtr = 0;    // points to earliest ending meeting

        // Traverse all meetings in order of start time
        for (int i = 0; i < n; i++) {

            // If current meeting starts before the earliest one ends
            if (starts[i] < ends[endPtr]) {
                // Overlap → need a new room
                rooms++;
            } else {
                // No overlap → one meeting has ended
                // reuse that room, move to next ending time
                endPtr++;
            }
        }

        // Total rooms needed = max simultaneous meetings
        return rooms;
    }
};