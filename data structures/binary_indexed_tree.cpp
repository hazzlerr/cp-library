template <typename T>
struct bit{
      int n;
      vec <T> t;
      bit(int z): n(z + 5), t(z + 5) {}
      void upd(int p, T x){
            for (p += 3; p < n; p += p & -p){
                  t[p] += x;
            }
      }
      T get(int r){
            T res = 0;
            for (r += 3; r > 0; r -= r & -r){
                  res += t[r];
            }
            return res;
      }
};
