class Solution {
public:
    vector<int> num;
    int trgt;
    
    int sz;
    int low, high, mid;

    int itrBinSearch() {
        low = 0, high = sz-1, mid = 0;

        while (low <= high) {
            mid = (low + high) / 2;

            if (num[mid] == trgt) {
                return mid;
            }
            else if (num[mid] <= trgt) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }


        return -1;
    }

    int doRecBinSearch(int low, int high) {
        mid = (low + high) / 2;

        if (low > high) {
            return -1;
        }


        cout << "called :: low = " <<low << " high  = "<<high<<endl<<"num mid = "<<num[mid]<<" trgt = "<<trgt<<endl<<endl;
        if (num[mid] == trgt) {
            cout << "called return mid :: "<<mid<<endl;
            return mid;
        }
        else if (num[mid] <= trgt) {
            cout << "calling :: low(mid+1) = " <<mid + 1 << " high  = "<<high<<endl;
            return doRecBinSearch(mid + 1, high);
        }
        else {
            cout << "calling :: low = " <<low << " high(mid-1)  = "<<mid-1<<endl;
            return doRecBinSearch(low, mid - 1);
        }

        

    }

    int recBinSearch() {
        low = 0, high = sz-1, mid = 0;
        return doRecBinSearch(low, high);
    }

    int search(vector<int>& nums, int target) {
        num = nums;
        trgt = target;
        cout << "setting trgt as :: "<<trgt<<endl;
        sz = nums.size();
        
        return itrBinSearch() \
        & recBinSearch();
    }
};