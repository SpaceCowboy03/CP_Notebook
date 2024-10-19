int cribe[N];

for(int i=2; i < N; i++){
    if(!cribe[i]){
        for(int k=i+i; k<N; k+=i){
            cribe[k] = i;
        }
    }
}