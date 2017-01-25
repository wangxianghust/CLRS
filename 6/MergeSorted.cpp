// answer for problem 6.5-9
// But there are some problems, I will see it later
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template<typename T>
void print(vector<T> &A){
    for(auto i : A)
        cout << i << " ";
    cout << endl;
}

void print(vector<pair<int,int> > &A){
    for(auto i : A)
        cout << i.first << "-" << i.second << " ";
    cout << endl;
}


template<typename T>
void print(vector<T> &A, int count, string info){
    cout << "-----" << info << "-----" << endl;
    for(int i = 0; i < count; ++i)
        cout << A[i] << " ";
    cout << endl;
}


int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

int parent(int i){
    return (i-1)/2;
}

struct heap{
    heap(){}
    heap(vector<pair<int,int> > v, int size):vec(std::move(v)), heap_size(size) {}
    vector<pair<int,int> > vec;
    int heap_size;
};

void MinHeapity(heap &H, int i){
    vector<pair<int,int> > &A = H.vec;
    int l = left(i);
    int r = right(i);
    int smallest;
    if(A[l].second < A[i].second && l < H.heap_size){
        smallest = l;
    } else {
        smallest = i;
    }    

    if(A[r].second < A[smallest].second && r < H.heap_size){
        smallest = r;
    }
    
    if(smallest != i){
        swap(A[i], A[smallest]);
        MinHeapity(H, smallest);
    }
}

void BuildMinHeap(heap &H){
    int size = H.heap_size;
    for(int i = size/2; i >= 0; --i){
        MinHeapity(H, i);
    }
}

/*
vector<int> HeapSort(vector<int> &A){
    heap H;
    H.vec = A;
    H.heap_size = A.size();
    BuildMinHeap(H);
    //print(H.vec);

    while(H.heap_size > 1){
        swap(H.vec[H.heap_size-1], H.vec[0]);
        --H.heap_size ;
        MinHeapity(H, 0);
        //print(H.vec);
    }
    return H.vec;
}
*/

pair<int,int> HeapMin(heap &H){
    return H.vec[0];
}

pair<int,int> HeapExtractMax(heap &H){
    if(H.heap_size < 1) return{-1,-1};
    auto key = H.vec[0];
    H.vec[0] = H.vec[H.heap_size-1];
    --H.heap_size;
    MinHeapity(H, 0);
    return key;
}

void HeapDesKey(heap &H, int i, int key){
    if(key > H.vec[i].second){
        cout << "error, key is bigger than old" << endl;
        return ;
    }
    H.vec[i].second = key;
    while(parent(i) >= 0 && H.vec[i].second < H.vec[parent(i)].second){
        swap(H.vec[i], H.vec[parent(i)]);
        i = parent(i);
        //print(H.vec);
    }
}

void MinHeapInsert(heap &H, pair<int,int> key){
    ++H.heap_size;
    H.vec[H.heap_size-1].second = INT_MAX;
    H.vec[H.heap_size-1].first = key.first;
    HeapDesKey(H, H.heap_size-1, key.second);
}

void HeapDelete(heap &H, int i){
    auto last = H.vec[H.heap_size-1];
    --H.heap_size;
    auto delete_node = H.vec[i];
    H.vec[i] = last;
    if(last.second >= delete_node.second){
        MinHeapity(H, i);
    } else {
        HeapDesKey(H, i, last.second);
    }
}

vector<pair<int,int> > process(vector<int> &A, int index){
    vector<pair<int,int> > ret;
    for(auto ele : A){
        ret.push_back({index, ele});
    }
    return ret;
}


int main(){
    vector<int> v1{1,2,3,4,5};
    vector<int> v2{3,6,9,12};
    vector<int> v3{5,7,15,16,20};
    
    // data pre-process, give every element a index to denote which list it belongs to.
    vector<vector<pair<int,int>>> vs;
    vs.push_back(process(v1,0));
    vs.push_back(process(v2,1));
    vs.push_back(process(v3,2));

    vector<pair<int,int>> ret;

    if(1){
        vector<pair<int,int> > data;
        //heap H(data,data.size());
        heap H(data, 14);
        BuildMinHeap(H);
        print(H.vec);
        auto max = HeapExtractMax(H);
        ret.push_back(max);
        for(int i=0; i<3; ++i){
            for(int j=0; j<vs[i].size(); ++j){
                MinHeapInsert(H,vs[i][j]);
            }
        }

        for(int i=0; i<H.heap_size; ++i){
            auto max = HeapExtractMax(H);
            ret.push_back(max);

        }
        
        print(ret);
    }



/*
    vector<int> A = {10,2,6,53,81,90,23,45,2,12};
    auto ret = HeapSort(A);
    //print(ret);
    heap H(A, A.size());
    BuildMinHeap(H);
    print(H.vec);
    cout << HeapMin(H) << endl;
    cout << HeapExtractMax(H) << endl;
    print(H.vec, H.heap_size, "state");
    HeapDesKey(H, 5, 0);
    MinHeapInsert(H, -2);
    print(H.vec, H.heap_size, "MinHeapInsert");

    HeapDelete(H, 8);
    print(H.vec, H.heap_size, "Delete 81");
    HeapDelete(H, 0);
    print(H.vec, H.heap_size, "Delete 0");
    */
}

