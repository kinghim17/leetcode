class Solution {
public:
    const int mod = 1e9 + 7;
    long long modpow(long long b, long long p){
        long long ans = 1;
        for (; p; p>>=1){
            if (p&1)
                ans = ans * b%mod;
            b = b * b % mod;
        }
        return ans;
    }
    int makeStringSorted(string s) {
        long long ans = 0;
        map<int, long long> freq; 
        for (char& c: s){
            freq[c - 'a']++;
        }
        vector<long long> fact(s.size() + 1, 1ll);
        for (int i = 1; i <= s.size(); i++){
            fact[i] = (fact[i - 1] * i)%mod;
        }
        int l = s.size();
        for (char c: s){
            l--;
            long long t = 0, rev = 1;
            for (int i = 0; i < 26; i++){
                if (i < c - 'a')
                    t += freq[i];
                rev = (rev * fact[freq[i]])%mod;
                
            }
            ans += (t*fact[l]%mod) * modpow(rev, mod - 2);
            ans %= mod;
            freq[c - 'a']--;
        }
        return ans;
    }
};
//modular inverse
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    const int CHAR_RANGE = 256;

    // Function to compute all factorials % MOD up to n
    vector<long long> precomputeFactorials(int n) {
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        return fact;
    }

    // Function to compute modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, int mod) {
        long long result = 1, base = a;
        int power = mod - 2;
        while (power) {
            if (power % 2) result = (result * base) % mod;
            base = (base * base) % mod;
            power /= 2;
        }
        return result;
    }

    int makeStringSorted(string s) {
        int n = s.length();
        vector<long long> fact = precomputeFactorials(n);
        vector<long long> invFact(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            invFact[i] = modInverse(fact[i], MOD);
        }

        vector<int> count(CHAR_RANGE, 0);
        long long res = 0;

        // Count frequency of each character
        for (char ch : s) {
            count[ch]++;
        }

        // Traverse the string and compute result
        for (int i = 0; i < n; ++i) {
            for (int ch = 0; ch < s[i]; ++ch) {
                if (count[ch] == 0) continue;

                // Calculate permutations if ch is the current character
                long long permutations = fact[n - i - 1];
                count[ch]--;

                // Divide by factorial of counts of remaining characters
                for (int j = 0; j < CHAR_RANGE; ++j) {
                    if (count[j] > 0) {
                        permutations = (permutations * invFact[count[j]]) % MOD;
                    }
                }

                res = (res + permutations) % MOD;
                count[ch]++;
            }
            count[s[i]]--;
        }

        return res;
    }
};


//use fenwick tree