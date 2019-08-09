class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int track_A=0,track_B=0;
        for(const auto &i:nums){
            int set_B=track_A&i;
            int resetting=track_A&track_B&i;
            track_B|=set_B;
            track_A|=i;
            track_A^=resetting;
            track_B^=resetting;
        }
        return track_A;
    }
};