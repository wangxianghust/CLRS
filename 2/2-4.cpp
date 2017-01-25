#include <iostream>

using namespace std;

template<unsigned N>
void Merge(int (&A)[N], int p, int q, int r, int &ret){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1];
    int R[n2];

    for(int i=0; i<n1; ++i){
        L[i] = A[p+i];
    }
    for(int j=0; j<n2; ++j){
        R[j] = A[q+j+1];
    }

    int i=0;
    int j=0;
    int k=p;
    while((i<n1)&&(j<n2)){
        if(L[i]>R[j]){
            A[k++] = R[j++];
            ret += n1-i;
        }else{
            A[k++] = L[i++];
        }
    }

    if(i<n1){
        for(; i<n1; ){
            A[k++] = L[i++];
        }
    } else {
        for(; j<n2; ){
            A[k++] = R[j++];
        }
    }
}

template<unsigned M>
int FindInversionNum(int (&A)[M], int p, int r, int &ret){
    if(p < r){
        int mid = (p+r)/2;
        FindInversionNum(A,p,mid,ret);
        FindInversionNum(A,mid+1,r,ret);
        Merge(A,p,mid,r,ret);
        cout << "test "  << ret << endl;
    }
    return ret;
}

int main(){
    //int A[] = {1,2,3,0};
    int A[] = {7,8,1,2,3,4,5,6,17,0,100};
    int size = sizeof(A)/sizeof(A[0]);
    int ret = 0;
    FindInversionNum(A,0,size-1,ret);
    for(auto i : A){
        cout << i << "--->";
    }
    cout << endl;
    cout << ret << endl;
}
