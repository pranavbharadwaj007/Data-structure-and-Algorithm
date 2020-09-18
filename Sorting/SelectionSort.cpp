#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int>& arr, int size) {
    for (int i=0;i<size-1;i++) {
        int mapped=i;
        for (int j=i+1;j<size;j++) {
            if (arr[j]<arr[mapped]) {
                mapped=j;
            }
        }
        swap(arr[i], arr[mapped]);
    }
}
int main() {
    int size;
    cin>>size;
    vector<int>vec;
    for (int i=0;i<size;i++) {
        int p;
        cin>>p;
        vec.push_back(p);

    }
    selection_sort(vec, size);
    for (int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}