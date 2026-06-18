class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hPos = (hour + (double)((minutes / 60.0) * 5.0) / 5.0) * 5;
        double mPos = minutes;

        return min(abs(hPos - mPos), 60 - abs(hPos - mPos))  * 6;
    }
};