const int N = 500005; //Number of nodes 
const int ALPHA = 26; // Number of characters

int trie[N][ALPHA];
set<int> final_s;
int last_n = 0;

bool is_already(string &s){
    int curr_node = 0;
    for(char it: s){
        if(trie[curr_node][it-'a'] == 0){
            trie[curr_node][it-'a'] = ++last_n;
        }
        curr_node = trie[curr_node][it-'a'];
    }
    bool is_alr = final_s.count(curr_node);
    final_s.insert(curr_node);
    return is_alr;
}