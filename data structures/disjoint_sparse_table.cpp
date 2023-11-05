template <typename T>
struct dsparse_table{
      function <T(T, T)> op;
      vector <T> sp[32];

      dsparse_table(const vector <T> &a, const T &identity_element, const function <T(T, T)> &op): op(op){
            int n = a.size();
            for (int h = 0; h <= __lg(n); ++h){
                  sp[h].resize(n + 1, identity_element);
                  for (int st = 1 << h, le = 1 << h; st < n + le; st += (le << 1)){
                        for (int i = st + 1; i <= min(n, st + le); ++i){
                              sp[h][i] = op(sp[h][i - 1], a[i - 1]);
                        }
                        for (int i = min(n, st) - 1; i >= st - le; --i){
                              sp[h][i] = op(a[i], sp[h][i + 1]);
                        }
                  }
            }
      }

      T get(int l, int r){ // get result on [l, r]
            int h = __lg(l ^ (r + 1));
            return op(sp[h][l], sp[h][r + 1]);
      }
};
