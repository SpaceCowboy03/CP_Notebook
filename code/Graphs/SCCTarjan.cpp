struct TarjanScc{
   vector<bool> marked;
   vector<int> id;
   vector<int> low;
   int pre;
   int count;
   stack<int> stck;
   vector<vector<int> >G;

   TarjanScc( vector<vector<int> >g, int V ){
       G=g;
       marked = vector<bool>(V, false);
       stck = stack<int>();
       id= low = vector<int>(V, 0);
       pre=count=0;
       for(int u=0; u<V; u++)
           if( !marked[u] ) dfs(u);
   }

   void dfs( int u ){
       marked[ u ] = true;
       low[ u ] = pre++;
       int min = low[ u ];

       stck.push( u );
       for( int w=0; w<G[u].size(); w++){
           if(  !marked[G[u][w]] ) dfs( G[u][w] );
           if( low[ G[u][w] ] < min ) min = low[ G[u][w] ];
       }
       if( min<low[u] ){
           low[u] = min;
           return;
       }
       int w;
       do{
           w = stck.top();stck.pop();
           id[ w ] = count;
           low[ w ]= G.size();
       }while( w != u );
       count++;
   }

   int getCount() { return count; }


   // are v and w strongly connected?
   bool stronglyConnected(int v, int w) {
       return id[v] == id[w];
   }

   // in which strongly connected component is vertex v?
   int getId(int v) { return id[v]; }
};

//Ejemplo de Uso
int main( ){
   int u, v, N, M, cas, k=0;
   for(cin>>cas; k<cas; k++){
       scanf("%d %d", &N, &M);
       //cin>>N>>M;
       vector<vector<int> >G(N);

       for(int i=0; i < M; i++){
           scanf("%d %d", &u, &v);
           //cin>>u>>v;
           u--;v--;
           G[u].PB(v);
       }

       TarjanScc tscc(G, N);
       //Encontrar cuantos nodos tienen grado de entrada 0
       vector<int>indegree(tscc.getCount(), 0);
       int idu, idv;
       for( u = 0; u < N; u++){
           idu = tscc.getId( u );
           for( v = 0; v < G[u].size(); v++){
               idv = tscc.getId( G[u][v] );

               if( idu!=idv ){
                   indegree[idv]++;
               }
           }
       }
       int res=0;
       for(int i=0; i<indegree.size(); i++){
           if(indegree[i]==0)res++;
       }
       printf("Case %d: %d\n",k+1,res);
   }
return 0;
}
