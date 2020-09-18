#include<iostream>
#include<vector>
using namespace std;
void bubble(vector<int>& vec, int size) {
    for (int i=0;i<size-1;i++) {
        bool swapped=false;
        for (int j=0;j<size-i-1;j++) {
            if (vec[j]>vec[j+1]) {
                swap(vec[j], vec[j+1]);
                swapped=true;
            }
        }
        if (swapped==false) {
            break;
        }
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
    bubble(vec, size);
    for (int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}