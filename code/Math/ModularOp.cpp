const int MOD = 998244353;

int add ( int A, int B ) { return A+B<MOD? A+B: A+B-MOD; }
int mul ( int A, int B ) { return ll(A)*B % ll(MOD); }
int sub ( int A, int B ) { return add ( A, MOD-B ); }