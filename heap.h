class element{
    public:
        int key;
        element(int num);
        element();
};

class heap{
    public:
        int capacity;
        int size;
        element* H;

        heap();
        heap(int cap);
        heap Initialize(int n);
        void BuildHeap(heap *h, element A[], int n);
        void Insert(heap *h, int flag, int k);
        element DeleteMin(heap *h, int flag);
        void DecreaseKey(heap h, int flag, int index, int value);
        void PrintHeap(heap h);
        int Parent(int i);
        int Left(int i);
        int Right(int i);
        void MinHeapify(element A[], int i, int size);
        void HeapifyUp(element A[], int i);
        void Resize(int newSize, element A[]);

};

