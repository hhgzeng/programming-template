namespace SegT {
    int tag[8 * N];
    int64_t wsum[8 * N], sum[8 * N];
    void add(int p, int l, int r, int v) {
        sum[p] += v * (r - l);
        wsum[p] += 1ll * v * (r - l) * (l + r + 1) / 2;
        tag[p] += v;
    }
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, l, m, tag[p]);
        add(2 * p + 1, m, r, tag[p]);
        tag[p] = 0;
    }
    void pull(int p) {
        sum[p] = sum[2 * p] + sum[2 * p + 1];
        wsum[p] = wsum[2 * p] + wsum[2 * p + 1];
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
            return add(p, l, r, v);
        push(p, l, r);
        int m = (l + r) / 2;
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    int64_t query(int p, int l, int r, int x) {
        if (l >= x)
            return sum[p] * x;
        if (r <= x)
            return wsum[p];
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x) + query(2 * p + 1, m, r, x);
    }
    int get(int p, int l, int r, int x) {
        if (r - l == 1)
            return sum[p];
        int m = (l + r) / 2;
        push(p, l, r);
        if (x < m) {
            return get(2 * p, l, m, x);
        } else {
            return get(2 * p + 1, m, r, x);
        }
    }
}
namespace LCT {
    int ch[2 * N][2], p[2 * N], endp[2 * N], mn[2 * N], mx[2 * N];
    bool isroot(int t) {
        return ch[p[t]][0] != t && ch[p[t]][1] != t;
    }
    bool pos(int t) {
        return ch[p[t]][1] == t;
    }
    void pull(int t) {
        mn[t] = std::max(0, ch[t][0] ? mn[ch[t][0]] : SAM::len[SAM::link[t]]);
        mx[t] = ch[t][1] ? mx[ch[t][1]] : SAM::len[t];
    }
    void rotate(int t) {
        int k = !pos(t);
        int q = p[t];
        ch[q][!k] = ch[t][k];
        if (ch[t][k])
            p[ch[t][k]] = q;
        p[t] = p[q];
        if (isroot(q)) {
            endp[t] = endp[q];
        } else {
            ch[p[q]][pos(q)] = t;
        }
        ch[t][k] = q;
        p[q] = t;
        pull(q);
    }
    void splay(int t) {
        while (!isroot(t)) {
            int q = p[t];
            if (!isroot(q))
                rotate(pos(t) == pos(q) ? q : t);
            rotate(t);
        }
        pull(t);
    }
    void access(int t, int len) {
        for (int i = t, u = 0; i; u = i, i = p[i]) {
            splay(i);
            if (ch[i][1])
                endp[ch[i][1]] = endp[i];
            ch[i][1] = 0;
            pull(i);
            if (u)
                SegT::rangeAdd(1, 0, n, endp[i] - mx[i], endp[i] - mn[i], -1);
            ch[i][1] = u;
            pull(i);
        }
        splay(t);
        endp[t] = len;
        SegT::rangeAdd(1, 0, n, len - mx[t], len - mn[t], 1);
    }
    void cut(int t) {
        splay(t);
        if (ch[t][0]) {
            endp[ch[t][0]] = endp[t];
            p[ch[t][0]] = p[t];
            p[t] = 0;
            ch[t][0] = 0;
            pull(t);
        } else {
            p[t] = 0;
        }
    }
    void link(int t, int x) {
        p[t] = x;
    }
}