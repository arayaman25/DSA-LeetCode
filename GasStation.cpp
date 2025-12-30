#include<iostream>
using namespace std;
    long double Maxi(vector<int>& arr) {
        long double maxi = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            maxi = max(maxi, (long double)(arr[i + 1] - arr[i]));
        }
        return maxi;
    }

    int GasStn(vector<int>& arr, long double dist) {
        int count = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            long double gap = arr[i + 1] - arr[i];
            count += (int)(ceil(gap / dist)) - 1;
        }
        return count;
    }

    long double minimiseMaxDistance(vector<int>& arr, int k) {
        long double low = 0;
        long double high = Maxi(arr);
        while (high - low > 1e-6) {
            long double mid = (low + high) / 2.0;

            if (GasStn(arr, mid) > k)
                low = mid;      
            else
                high = mid;     
        }
        return high;
    }
