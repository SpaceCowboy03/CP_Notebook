const int N = 200005;
int BIT[N];
 
void update(int idx, int val){
    for(; idx < N; idx += idx&(-idx)){
        BIT[idx]+=val;
    }
}
 
int query (int idx){
    ll ret = 0;
    for(; idx > 0; idx-=idx&(-idx)){
        ret += BIT[idx];
    }
    return ret;
}
 
int query (int left, int right){
    return query(right) - query(left-1);
}

int lower_find(int val){
    int id = 0;
    for(int i = 31-__builtin_clz(n); i >= 0; --i){
        int nid = id | ( 1 << i);
        if(nid <= n && BIT[nid] <= val){
            val -= BIT[nid];
            id = nid;
        }
    }
    return id;
}


iota(idx+1, idx+n+1,1);
sort(idx+1, idx+n+1, [](int i_a, int i_b) { return arr[i_a] > arr[i_b];});

//Update range [l,r] to v
update(l,v);
update(r+1,-v);

//Update specific value at pos k to u
ll prev = query(k)-query(k-1);
update(k,u);
update(k, -prev);

//Inversions
for(int i=1; i <=n; i++){
    forward[i] = query(values[i]);
    update(1,1);
    update(values[i],-1);
}
memset(BIT, 0, sizeof BIT);

for(int i=n; i >0 ; i--){
    backward[i] = query(values[i]);
    update(values[i]+1, 1);
}


//Dimension change
sort(difval, difval+ind);
map<int,int> idx;
int cnt = 0;
idx[difval[0]] = cnt;
cnt++;
for(int i=1; i < ind;  i++){
    if(difval[i] != difval[i-1]){
        idx[difval[i]] = cnt;
        cnt++;
    }
}