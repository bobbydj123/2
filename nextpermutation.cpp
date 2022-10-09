class NextPermutation {
public:
    void nextPermutation(vector<int>& v) {
        int ind=-1;
        for(int i = v.size()-1; i>=1; i--){
                if(v[i] > v[i-1]){
                        ind = i-1;
                        break;
                }
        }
        if(ind == -1){
                sort( v.begin(), v.end());
                return;
        }
        for(int i=v.size()-1 ; i>=0 ; i--){
                if(v[i] > v[ind]){
                        swap(v[i], v[ind]);
                        break;
                }
        }
        reverse(v.begin() + ind + 1, v.end());    
    }
};
