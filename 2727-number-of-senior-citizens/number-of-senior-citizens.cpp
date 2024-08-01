class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;

        for (string here: details)
        {
            string sage = here.substr(11,2);
            int age = stoi(sage);

            age > 60? cnt++ : cnt+=0;
        }

        return cnt;
    }
};