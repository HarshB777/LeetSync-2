const long long int MX = 100000;
vector<bool> isPrime(MX+1,true);
bool isPrimeComputed = false;

void pre()
{
    if (isPrimeComputed)
        return;
    isPrime[1] = false;
    isPrime[0] = false;
    
    for (long long int p = 2; p < MX; p++)
        for (long long int j = p*p; j < MX; j += p)
        {
            isPrime[j] = false;
        }
}


class Solution {
public:
    int nonSpecialCount(int l, int r) {
        pre();
        
        float l1 = sqrt(l);
        float r1 = sqrt(r);

        int le = ceil(l1);
        int ri = floor(r1);

        cout<<"le = "<<le<<" ri = "<<ri<<endl;
        int ans = r-l+1;
        cout<<"ans = "<<ans<<endl;
        for (int k = le; k <= ri; k++)
        {
            if (isPrime[k])
            {
                cout<<"for k = "<<k<<endl;
                ans--;
            }
        }
        
        return ans;
    }
};