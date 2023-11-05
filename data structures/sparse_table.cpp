template <typename T>
struct sparse_table{
      function <T(T, T)> op;
      vector <T> sp[32];
 
      sparse_table(const vector <T> &a, const function <T(T, T)> &op): op(op) {
            sp[0] = a;
            for (int i = 1; i <= __lg(a.size()); ++i){
                  sp[i].resize(a.size());
                  for (int j = 0; j + (1 << i) <= a.size(); ++j){
                        sp[i][j] = op(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
                  }
            }
      }
 
      T get(int l, int r){ // get result on [l, r]
            int z = __lg(r - l + 1);
            return op(sp[z][l], sp[z][r - (1 << z) + 1]);
      }
};
