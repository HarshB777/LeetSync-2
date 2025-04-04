class Solution {
private:
    vector<int> vec;
    int goal;
    int size;
    int floor_value = INT_MIN;
    int floor_index = -1;
    int low, mid, high;

    void recFindInsert() {
        low = 0, high = size -1;

        while (low <= high) {
            mid = (low + high) / 2;

            if (vec[mid] == goal){
                floor_value = goal;
                floor_index = mid-1;
                return;
            }
            else if (vec[mid] > goal) {
                high = mid - 1;
            }
            else {
                if (vec[mid] >= floor_value) {
                    floor_value = vec[mid];
                    floor_index = mid;
                }
                low = mid + 1;
            }
        }



    }

    int findInsert() {
        floor_value = INT_MIN;
        floor_index = -1;
        recFindInsert();

        return floor_index+1;
    }


public:
    int searchInsert(vector<int>& nums, int target) {
        vec = nums;
        goal = target;
        size = vec.size();

        return findInsert();
    }
};