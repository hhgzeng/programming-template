struct BasisAll {
    int n;
    bool zero;
    std::vector<i64> a;
    std::vector<i64> tmp;
    
    Basis(int n) : n(n), zero(false), a(n, 0), tmp(n, 0) {}
    
    void add(i64 x) {
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == 0) {
                    a[i] = x;
                    return;
                }
                x ^= a[i];
            }
        }
        zero = true;
    }
    
    bool query(i64 x) {
        for (int i = n - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (a[i] == 0) {
                    return false;
                } else {
                    x ^= a[i];
                }
            }
        }
        return true;
    }

    i64 queryMax() {
        i64 res = 0;
        for (int i = n - 1; i >= 0; i--) {
            res = std::max(res, res ^ a[i]);
        }
        return res;
    }

    i64 queryMin() {
        if (zero) return 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                return a[i];
            }
        }
        return 0;
    }

    i64 queryKMin(i64 k) {
        k -= zero ? 1 : 0;
        if (k == 0) {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] >> j & 1) {
                    a[i] ^= a[j];
                }
            }
            if (a[i] > 0) {
                tmp[cnt++] = a[i];
            }
        }
        if (k >> cnt >= 1)  {
            return -1;
        }
        i64 res = 0;
        for (int i = 0; i < cnt; i++) {
            if (k >> i & 1) {
                res ^= tmp[i];
            }
        }
        return res;
    }
};