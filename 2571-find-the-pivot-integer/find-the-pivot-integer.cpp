class Solution {
public:
    int lsum(int x) {
        int sum = 0;
        for (int i = 1; i <= x; i++) {
            sum += i;
        }
        return sum;
    }

    int rsum(int x,int n) {
        int sum = 0;
        for (int i = n; i >= x; i--) {
            sum += i;
        }
        return sum;
    }

    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            int l = lsum(i);
            int r = rsum(i,n);
            if (l == r)
                return i;
        }

        return -1;
    }
};
