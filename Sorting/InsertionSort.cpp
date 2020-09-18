#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>& arr, int size) {
    for (int i=1;i<size;i++) {
        int key=arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertion_sort(vec, size);
    for (int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}