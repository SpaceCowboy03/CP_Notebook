const int N = 1e5+5;
int dsu[N];
int cc;

int find (int node){
    if(dsu[node] == -1) return node;
    return dsu[node] = find(dsu[node]);
}

bool connected(int A, int B){
    return find(A)==find(B);
}

void join (int A, int B){
    A = find(A);
    B = find(B);
    dsu[A] = B;
    cc--;
}

memset(dsu, -1, sizeof dsu);