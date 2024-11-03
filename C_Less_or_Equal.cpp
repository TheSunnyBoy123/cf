#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp) // pass array, length and exp
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n) // pass array and length
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    radixsort(&arr[0], n);

    if (k == 0){
        if (arr[0] == 1){
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
        }
    } else if (k == n){
        cout << arr[n-1] << endl;
    } else if (arr[k-1] == arr[k]){
        cout << -1 << endl;
    } else {
        cout << arr[k-1] << endl;
    }
}


int main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();
}


/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

*/








