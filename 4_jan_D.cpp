#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct SegmentTree {
    int n;
    vector<int> maxTree, minTree;

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        maxTree.resize(4 * n);
        minTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            maxTree[node] = arr[start];
            minTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
        }
    }

    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            maxTree[node] = value;
            minTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node + 1, start, mid);
            } else {
                update(idx, value, 2 * node + 2, mid + 1, end);
            }
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
        }
    }

    pair<int, int> query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) {
            return {INT_MIN, INT_MAX};
        }
        if (L <= start && end <= R) {
            return {maxTree[node], minTree[node]};
        }
        int mid = (start + end) / 2;
        auto left = query(L, R, 2 * node + 1, start, mid);
        auto right = query(L, R, 2 * node + 2, mid + 1, end);
        return {max(left.first, right.first), min(left.second, right.second)};
    }

    void update(int idx, int value) {
        update(idx, value, 0, 0, n - 1);
    }

    pair<int, int> query(int L, int R) {
        return query(L, R, 0, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        SegmentTree segTree(arr);

        auto calculateMaxConvenience = [&]() {
            int maxConvenience = INT_MIN;
            for (int l = 0; l < n; ++l) {
                for (int r = l; r < n; ++r) {
                    auto [maxVal, minVal] = segTree.query(l, r);
                    int convenience = maxVal - minVal - (r - l);
                    maxConvenience = max(maxConvenience, convenience);
                }
            }
            return maxConvenience;
        };

        cout << calculateMaxConvenience() << endl;

        for (int i = 0; i < q; ++i) {
            int p, x;
            cin >> p >> x;
            segTree.update(p - 1, x);
            cout << calculateMaxConvenience() << endl;
        }
    }

    return 0;
}












// new solution 





#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

constexpr i64 inf = 1E18;
struct Info {
    i64 len;
    i64 maxl;
    i64 maxr;
    i64 minl;
    i64 minr;
    i64 ans;
    Info() : len(0), maxl(-inf), maxr(-inf), minl(inf), minr(inf), ans(0) {}
    Info(int x, int i) : len(1), maxl(x + i), maxr(x - i), minl(x - i), minr(x + i), ans(0) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.len = a.len + b.len;
    c.maxl = std::max(a.maxl, b.maxl);
    c.maxr = std::max(a.maxr, b.maxr);
    c.minl = std::min(a.minl, b.minl);
    c.minr = std::min(a.minr, b.minr);
    c.ans = std::max({a.ans, b.ans, a.maxl - b.minr, b.maxr - a.minl});
    return c;
}
void solve() {
    int n, q;
    std::cin >> n >> q;
    
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        seg.modify(i, Info(a, i));
    }
    std::cout << seg.rangeQuery(0, n).ans << "\n";
    for (int i = 0; i < q; i++) {
        int p, x;
        std::cin >> p >> x;
        p--;
        seg.modify(p, Info(x, p));
        std::cout << seg.rangeQuery(0, n).ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}