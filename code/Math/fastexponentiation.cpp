ll binpow(ll a, ll b) {
    /*si se necesita la potencia modulo m: aplicar el modulo a todas
    las multiplicaciones y a 'a' al antes del loop*/
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}