int parent[MAX];
int rango[MAX];
int n;
void Init( int _n ){
   n = _n;
   for( int i = 0 ; i < n ; ++i ){
       parent[i] = i;
       rango[i] = 0;
   }
}

int Find( int x ){
   if( x == parent[ x ] )
       return x;
   else
       return parent[ x ] = Find( parent[ x ] );
}
void Union( int x , int y ){
   int xRoot = Find( x );
   int yRoot = Find( y );
   if( rango[ xRoot ] > rango[ yRoot ] )
       parent[ yRoot ] = xRoot;
   else{
       parent[ xRoot ] = yRoot;
       if( rango[ xRoot ] == rango[ yRoot ] )
           rango[ yRoot ]++;
   }
}
int countComponents(){
   int c = 0;
   for( int i=0; i<n; i++ )
       if( parent[i] == i )
           c++;
   return c++;
}
vector<int> getRoots(){
   vector<int> v;
   for( int i=0; i<n; i++ )
       if( i == parent[i] )
           v.push_back(i);
   return v;
}

int countNodesInComponent( int root ){
   int c = 0;
   for( int i=0; i<n; i++)
       if( Find(i) == root )
           c++;
   return c++;
}
bool sameComponent( int x, int y ){
   return Find(x) == Find(y);
}
