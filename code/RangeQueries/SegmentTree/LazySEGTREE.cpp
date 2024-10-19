const int N = 500'005;
const int MOD = 998244353;

int add ( int A, int B ) { return A+B<MOD? A+B: A+B-MOD; }
int mul ( int A, int B ) { return ll(A)*B % ll(MOD); }
int sub ( int A, int B ) { return add ( A, MOD-B ); }

int n, q, h;

int sum[2*N];
pii lazy[2*N];
int lengths[2*N];

pii combine ( pii A, pii B ) {
    return {mul(A.ff, B.ff), add(mul(A.ss, B.ff), B.ss)};
}

void apply(int p, pii value) {
    sum[p] = add(mul(sum[p], value.ff), mul(lengths[p], value.ss));
    if (p < n) lazy[p] = combine(lazy[p], value);
}

void build_t() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
    sum[i] = add(sum[i<<1], sum[i<<1|1]);
    lengths[i] = lengths[i<<1]+lengths[i<<1|1];
    lazy[i] = {1,0};
  }
}

void build(int p) {
  while (p > 1){
    p >>= 1;
    if(lazy[p] == pii(1,0)) sum[p] = add(sum[p<<1], sum[p<<1|1]);

  }
}

void push(int p) {
  for (int s = h-1; s > 0; --s) {
    int i = p >> s;
    if (lazy[i] != pii(1,0)) {
      apply(i<<1, lazy[i]);
      apply(i<<1|1, lazy[i]);
      lazy[i] = {1,0};
    }
  }
}

void modify(int l, int r, pii value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  push(l0);
  push(r0 - 1);
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1)res = add(res, sum[l++]);
    if (r&1)res = add(sum[--r], res);
  }
  return res;
}

//Initialization:
scanf ( "%d%d", &n, &q );
h = sizeof(int) * 8 - __builtin_clz(n);
//cout << "h: " << h << endl;

for ( int i = n; i < 2*n; ++i ){
    scanf ( "%d", &sum[i] );
    lengths[i] = 1;
}
    

build_t();