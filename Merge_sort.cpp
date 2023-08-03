#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int arr[N];
void merge(int l, int r, int mid)
{
    int L = (mid - l) + 1;
    int R = r - mid;
    int LA[L + 1];
    int RA[R + 1];
    for(int i = l, j = 0; i <= mid; i++,j++)
    {
        LA[j] = arr[i];
    }
    for(int i = mid + 1, j = 0; i<=r; i++,j++)
    {
        RA[j] = arr[i];
    }
    LA[L] = INT_MAX;
    RA[R] = INT_MAX;

    int lp = 0, rp = 0;
    for(int i = l; i<= r; i++)
    {
        if(LA[lp] <= RA[rp]) {
            arr[i] = LA[lp++];
        }
        else {
            arr[i] = RA[rp++];
        } 
    }
}
void mergeSort(int l, int r)
{
    if(l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    int n; cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(0, n -1);
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}    