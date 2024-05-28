//Approach-1
//T.C : O(k * log(num)) - TLE
//S.C : O(1)
class Solution {
public:
    typedef long long ll;
    
    ll getPrice(ll num, int x) {
        ll price = 0;
        
        while(num) {
            int xth_bit = ((1 << (x-1)) & num);
            
            if(xth_bit > 0) {
                price++;
            }
            
            num = (num >> x);
        }
        
        return price;
        
    }
    
    long long findMaximumNumber(long long k, int x) {
        int num = 1;
        int sum = 0;
        
        while(true) {
            int price = getPrice(num, x);
            if(sum+price <= k) {
                sum += price;
            } else
                break;
            num++;
        }
        
        return num-1;
    }
};


//Approach-2
//T.C : O(log(k) * log(num)) - Accepted
//S.C : O(1)
class Solution {
public:
    typedef long long ll;
    vector<ll> bitCount;

    void getBits(ll number) {
        if (number == 0)
            return;
        
        if (number == 1) {
            bitCount[0]++;
            return;
        }
        
        if (number == 2) {
            bitCount[0]++;
            bitCount[1]++;
            return;
        }

        ll bitLen          = log2(number);
        ll nearestPowerTwo = (1ll << bitLen);
        bitCount[bitLen]  += (number - nearestPowerTwo + 1);

        for (ll i = 0; i < bitLen; i++) {
            bitCount[i] += (nearestPowerTwo / 2);
        }

        number = number - nearestPowerTwo;
        getBits(number);
    }

    ll findMaximumNumber(ll threshold, int divisor) {
        ll low = 0, high = 1e15;
        
        ll result = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            bitCount = vector<ll>(65, 0);
            
            getBits(mid);

            ll accumulatedCount = 0;
            
            for (ll i = 0; i < log2(mid)+1; i++) {
                if ((i + 1) % divisor == 0) 
                    accumulatedCount += bitCount[i];
            }

            if (accumulatedCount <= threshold) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
}