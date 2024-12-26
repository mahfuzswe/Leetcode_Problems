#include<bits/stdc++.h>
using namespace std;


int findSumAfterDiv(int arr[], int n, int div){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+= (arr[i]/div);
        // for ceiling add one more
        if(arr[i] % div != 0){
            sum += 1;
        }
    }
    return sum;
}

int findMinDivisor(int arr[], int n, int thres){
    int low = 1, high = *max_element(arr, arr+n);
    int ans = high;
    while(low <= high){
        int mid = (low + high) / 2;

        // mid is giving <= thres
        // but i'm looking for even smaller , hence do
        // a search on the left
        if(findSumAfterDiv(arr, n, mid) <= thres){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int thres; cin >> thres;

    cout << findMinDivisor(arr, n, thres) << '\n';

    return 0;
}