typedef complex<double> point;

/*Line Segment Intersection*/

double dot(const point &a, const point &b) { return real(conj(a) * b); }
double cross(const point &a, const point &b) { return imag(conj(a) * b); }

// returns intersection of infinite lines ab and pq (undefined if they are parallel)
point intersect(const point &a, const point &b, const point &p, const point &q)
{
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    return (d1 * q - d2 * p) / (d1 - d2);
}

int main(){
    vector<int> p(8);
    for(int i=0; i < 8; i++){
        cin >> p[i];
    }

    point a(p[0],p[1]), b(p[2],p[3]), c(p[4],p[5]), d(p[6],p[7]);

    point ans = intersect(a,b,c,d);
    cout << fixed << setprecision(2) << real(ans) << " " << imag(ans) << endl;

}