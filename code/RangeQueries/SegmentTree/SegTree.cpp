const int N = 1e6+5;

struct SegTree {
    SegTree *L, *R;
    int fr, to;
    
    SegTree (int fr, int to):
        fr(fr), to(to){
            if(fr == to){
                //Calc base values
                L = R = NULL;
            }else if (fr < to){
                L = new SegTree(fr, (fr+to)/2);
                R = new SegTree((L->to)+1, to);
                //Calc value: L->value + R->value
            }
        }

    void propagate (){
        //Propagation operation
    }

    void update(int l, int r){
        propagate();

        if(l == fr && r == to){
            //Change before prop? ex: change ^= true;
            propagate();
            return;
        }
        if(r < R->fr){
            L->update(l,r);
            R->propagate();
        }else if(l > L->to){
            R->update(l,r);
            L->propagate();
        }else{
            L->update(l, L->to);
            R->update(R->fr, r);
        }
        //Calc values, ex: num_on = L->num_on + R->num_on;
    }
};