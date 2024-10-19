const int N = 1e6+5;
int b[N];
int sz;

void borders(string p){
    b[0] = -1;
    p = '#'+p;
    for(int i=1; i <= sz; i++){
        int j=b[i-1];
        while(j>=0 && p[i] != p[j+1]) j = b[j];
        b[i] = j+1;
    }
}


//Encontrar periodos:
sz = s.size();
int aux = sz;
borders(s);

while(aux){
    cout << sz-b[aux] << " ";
    aux = b[aux];
}