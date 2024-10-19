const int p = 283;
const int M = 1e9+7;
const int N = 1e6+1;

int P[N], h[N];

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= M;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}

void prepareP(int n){
    P[0] = 1;
    for(int i =1; i < n; ++i){
        P[i] = ((ll)P[i-1]*p) % M;
    }
}

void computeRollingHash(string T){
    for(int i=0; i < (int)T.size(); ++i){
        if(i!=0) h[i] = h[i-1];
        h[i] = (h[i]+((ll)(T[i]-'a'+1)*P[i])%M)%M;
    }
}

int hash_fast(int L, int R){
    if(L==0) return h[R];
    int ans = 0;
    ans = ((h[R]-h[L-1]) %M +M) %M;
    ans = ((ll)ans*binpow(P[L],M-2)) %M;
    return ans;
}