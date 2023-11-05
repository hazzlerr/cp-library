template <typename T>
struct bit{
      int n;
      vec <T> t;
      T ielement;
      bit(int z, const T &ielement): n(z + 5), ielement(ielement), t(z + 5, ielement) {}
      void upd(int p, T x){
            for (p += 3; p < n; p += p & -p){
                  t[p] += x;
            }
      }
      T get(int r){
            T res = ielement;
            for (r += 3; r > 0; r -= r & -r){
                  res += t[r];
            }
            return res;
      }
};
