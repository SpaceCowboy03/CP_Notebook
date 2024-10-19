//si b=0: es como si fuera oo o -oo
//si a=0: la fraccion es 0

struct frac{
    ll a,b;
    frac(ll_a, ll_b): a(_a), b(_b){
        if(b<0) a*=-1, b *=-1;
        if(b==0) a = 1; 
    }

    bool operator < (frac other){
        return a * other.b < b * other.a;
    }
};

map<frac,frac> mp;