class Solution {
public:
    int maximum (vector<int>& piles) {
    int m = 0;

    for (int i = 0;i<piles.size() ;i++) {
        m = max(m,piles[i]);
    }
    return m;
}
    
    int calculate (vector<int> &arr, int hrs) {
        int total = 0;
        for (int i=0; i<=arr.size()-1; i++) {
            total += ceil((double)arr[i]/(double)hrs);
        }

        return total;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
       int left = 1;
       int right = maximum(piles);
       int totalH = 0;

       while(left <= right) {
            int mid = (right+left) / 2;
            totalH = calculate(piles,mid);

            if(totalH > h) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
       }

       return left;
    }
};
