#include "heap.h"
#include <iostream>
#include <array>
#include <cmath>
using namespace std;

heap::heap(){
    capacity = 0;
    size = 0;
}
    
heap::heap(int cap){
    capacity = cap;
    size = 0;
    H = new element[cap +1];
}

element::element(int num){
    key = num;
}

element::element(){
}

int heap::Parent(int i){
    return i/2;
}

int heap::Left(int i){
    return (2*i);
}

int heap::Right(int i){
    return (2*i + 1);
}

void heap::MinHeapify(element A[], int i, int size){
    int left = Left(i);
    int right = Right(i);
    int smallest = i;

    if(left <= size && A[left].key < A[i].key){
        smallest = left;
    }
    if(right <= size && A[right].key < A[smallest].key){
        smallest = right;
    }
    if(smallest != i){
        swap(A[i], A[smallest]);
        MinHeapify(A, smallest, size);
    }
}

void heap::HeapifyUp(element A[], int i){
    if(i == 1){
        return;
    }
    if(i && A[Parent(i)].key > A[i].key){
        swap(A[i], A[Parent(i)]);
        HeapifyUp(A, Parent(i));
    }
}

void heap::Resize(int newSize, element A[]){
    A = (element*) realloc(A, newSize);
}

heap heap::Initialize(int n){
    if(n <= 0){
        cout << "Can't Initialize heap, please enter a valid heap capacity.\n";
        heap h;
        return h;
    }
    heap *h = new heap(n);
    return *h;
}

void heap::BuildHeap(heap *h, element A[], int n){
    if(h->capacity == 0){
        cout << "Can't build heap, please initialize the heap first.\n";
        return;
    }
    if(n > h->capacity){
        cout << "Can't build heap, please increase the capacity of heap first.\n";
        return;
    }
    
    h->size = n;

    for(int i = 0; i < n+1; i++){
        h->H[i] = A[i];
    }
    
    for(int i = n/2; i >= 1; i--){
        MinHeapify(h->H, i, n);
    }
}

void heap::Insert(heap *h, int flag, int k){
    if(h->capacity == 0){
        cout << "Can't insert element, please initialize heap first.\n";
        return;
    }
    if(flag < 1 || flag > 2){
        cout << "Can't insert element, this is not a valid flag value.\n";
        return;
    }
    
    if(flag == 2){
        cout << "Before Insert: " << "\n";
        PrintHeap(*h);
    }

    if(h->size +1 > h->capacity){
        for(int i = 0; h->capacity <= h->size; i++){
            h->capacity = (int)pow(2, i);
        }
        h->H = (element*)realloc(h->H, h->capacity * sizeof(element));
    }
    
    h->size++;
    h->H[h->size].key = k;
    HeapifyUp(h->H, h->size);

    if(flag == 2){
        cout << "After Insert: " << "\n";
        PrintHeap(*h);
    }



}

element heap::DeleteMin(heap *h, int flag){
    if(h->capacity == 0){
        cout << "Can't delete min, please initialize the heap first.\n";
        element temp(-1234567);
        return temp;
    }
    if(h->size == 0){
        cout << "Can't delete min, heap is empty" << "\n";
        element temp(-1234567);
        return temp;
    }
    if(flag < 1 || flag > 2){
        cout << "Can't delete min, this is not a valid flag value.\n";
        element temp(-1234567);
        return temp;
    }

    if(flag == 2){
        cout << "Before deleting min: " << "\n";
        PrintHeap(*h);
    }

    element temp1(h->H[1].key);
    for(int i = 1; i < h->size; i++){
        h->H[i] = h->H[i+1];
    }
    h->size--;
    for(int i = h->size/2; i >= 1; i--){
        MinHeapify(h->H, i, h->size);
    }
    if(flag == 2){
        cout << "After deleting min: " << "\n";
        PrintHeap(*h);
    }
    return temp1;
}

void heap::DecreaseKey(heap h, int flag, int index, int value){
    if(h.capacity == 0){
        cout << "Can't decrease key, please initialize the heap first.\n";
        return;
    }
    if(h.size == 0){
        cout << "Can't decrease key, heap is empty.\n";
    }
    if(value > h.H[index].key){
        cout << "Can't decrease key, value is greater than current key.\n";
        return;
    }
    if(flag < 1 || flag > 2){
        cout << "Can't decrease key, this is not a valid flag value.\n";
    }
    
    if(flag == 2){
        cout << "Before Decrease Key: " << "\n";
        PrintHeap(h);
    }

    h.H[index].key = value;
    HeapifyUp(h.H, index);

    if(flag == 2){
        cout << "After Decrease Key: " << "\n";
        PrintHeap(h);
    }
}

void heap::PrintHeap(heap h){
    if(h.capacity == 0){
        cout << "Can't print heap, please initialize the heap first\n";
        return;
    }
    cout << "Capacity: " << h.capacity << "\n";
    cout << "Size: " << h.size << "\n";
    if(h.size == 0){
        return;
    }
    for(int i = 1; i < h.size +1; i++){
        cout << h.H[i].key << endl;
    }
    
}
