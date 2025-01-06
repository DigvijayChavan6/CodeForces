
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *tree;
int *arr;
int n;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return 0;
    }
    if (L <= start && end <= R) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, L, R);
    int p2 = query(2 * node + 1, mid + 1, end, L, R);
    return p1 + p2;
}

int main() {
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    tree = (int *)malloc(4 * n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    build(1, 0, n - 1);
    printf("Sum of values in given range = %d\n", query(1, 0, n - 1, 1, 3));
    update(1, 0, n - 1, 1, 10);
    printf("Updated sum of values in given range = %d\n", query(1, 0, n - 1, 1, 3));
    free(arr);
    free(tree);
    return 0;
}