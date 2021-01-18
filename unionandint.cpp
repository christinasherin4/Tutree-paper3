
#include <algorithm>
#include <iostream>
using namespace std;

int bins(int arr[], int l, int r, int x);
void pUnion(int arr1[], int arr2[], int m, int n)
{
    if (m > n) {
        int* tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;

        int temp = m;
        m = n;
        n = temp;
    }
    sort(arr1, arr1 + m);
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    for (int i = 0; i < n; i++)
        if (bins(arr1, 0, m - 1, arr2[i]) == -1)
            cout << arr2[i] << " ";
}
void pInt(int arr1[], int arr2[], int m, int n)
{
    if (m > n) {
        int* tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;

        int temp = m;
        m = n;
        n = temp;
    }
    sort(arr1, arr1 + m);
    for (int i = 0; i < n; i++)
        if (bins(arr1, 0, m - 1, arr2[i]) != -1)
            cout << arr2[i] << " ";
}
int bins(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return bins(arr, l, mid - 1, x);
        return bins(arr, mid + 1, r, x);
    }
    return -1;
}
int main()
{
    int arr1[] = { 1,3,4,5,7 };
    int arr2[] = { 2,3,5,6 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nUnion of two arrays is \n";
    pUnion(arr1, arr2, m, n);
    cout << "\nIntersection of two arrays is \n";
    pInt(arr1, arr2, m, n);
    int array1[] = {2,5,6};
    int array2[] = {4,6,8,10};
     cout << "\nUnion of two arrays is \n";
    pUnion(array1, array2, m, n);
    cout << "\nIntersection of two arrays is \n";
    pInt(arr1, arr2, m, n);
    return 0;
}
