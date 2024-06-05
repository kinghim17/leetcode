typedef long long ll;
vector<ll> printFirstNegativeInteger(ll A[], ll N, ll K) {
        
        deque<ll> deq;
        vector<ll> result;
        
        for(ll i = 0; i<K; i++) {
            if(A[i] < 0)
                deq.push_back(i);
        }
        
        for(int i = K; i<N; i++) {
            if(!deq.empty()) {
                result.push_back(A[deq.front()]);
            } else {
                result.push_back(0);
            }
            
            while(!deq.empty() && deq.front() < i-K+1) {
                deq.pop_front();
            }
            
            if(A[i] < 0)
                deq.push_back(i);
        }
        
        if(!deq.empty())
            result.push_back(A[deq.front()]);
        else
            result.push_back(0);
            
        return result;
        
 }