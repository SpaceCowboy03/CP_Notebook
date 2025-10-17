ll MOD;
const int MAX_N = 2;

struct Matrix {ll mat[MAX_N][MAX_N];};

ll mod(ll a, ll m) {return ((a%m)+m)%m;}

Matrix matMul(Matrix a, Matrix b){
    Matrix ans;
    rep(i,MAX_N){
        rep(j, MAX_N){
            ans.mat[i][j] = 0;
        }
    }
    rep(i,MAX_N){
        rep(k,MAX_N){
            if(a.mat[i][k] == 0) continue;
            rep(j, MAX_N){
                ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
        }
    }
    return ans;
}

Matrix matPow(Matrix base, ll p){
    Matrix ans;
    rep(i,MAX_N)
        rep(j,MAX_N)
            ans.mat[i][j] = (i==j);
    
    while(p){
        if(p&1) ans = matMul(ans,base);
        base = matMul(base,base);
        p >>= 1;
    }
    return ans;
}

int main(){
    /*Fib(n) mod 2 ^ m*/ 
    ll n, m;
    MOD = binpow(2,m);
    Matrix mat;
    mat.mat[0][0] = 1;
    mat.mat[0][1] = 1;
    mat.mat[1][0] = 1;
    mat.mat[1][1] = 0;

    Matrix aa = matPow(mat, n);

    cout << aa.mat[0][1] << endl;

}