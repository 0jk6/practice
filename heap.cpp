//from coding jesus yt channel
#include <iostream>
#include <vector>

using namespace std;

/*
heap is similar to a binary tree, but nodes are represented as a vector
*/

class MaxHeap{
    private:
        int _size = 0;
        vector<int> arr = {-1}; //this will store elements of heap, arr[0] is a garbage value, and arr[1] is max element

        //private functions
        
        //given an index, it will give the parent
        int p(int i){return i/2;}; //in max heap, if a child's index is i, then it's parent will be at i/2
        
        //given an index, find the left child
        int l(int i){return i*2;}; //left child will be the current node's index multiplied by 2

        //given an index, find the right child, it will be at index mulitplied by 2 + 1
        int r(int i){return (i*2)+1;}

    public:
        //public functions
        bool isEmpty() const {return _size == 0;};
        int getMax() const {return arr[1];}; 
        void insertItem(int val);
        void shiftUp(int i); //to perform insertItem, we need this function
        int extractMax();
        void shiftDown(int i);
};

//implement the class functions


void MaxHeap::shiftUp(int i){
    //if index is greater than _size, then it is not possible
    if(i > _size) return;

    //when i is 1, then parent will be 0, and this arr[0] is garbage, so we should stop recursion here
    if(i == 1) return;

    //if current element is greater than it's parent, then we'll swap them
    if(arr[i] > arr[p(i)]){
        swap(arr[i], arr[p(i)]);
    }

    //recursively do this, until we get to index 1, where actual max value of entire heap exists
    shiftUp(p(i));
}


void MaxHeap::insertItem(int val){
    //we will only insert an item into the max heap when (_size+1) >= arr.size()
    if(_size + 1 >= arr.size()){
        arr.push_back(0); //add a placeholder zero
    }

    //now fill the item in place holder
    arr[++_size] = val;
    shiftUp(_size); //shift the inserted element to its proper position

    return;
}

void MaxHeap::shiftDown(int i){
    if(i > _size) return;

    int swapId = i;

    //if left child exists and is greater than the current node itself, then we'll swap
    if(l(i) <= _size && arr[i] < arr[l(i)]){
        swapId = l(i); //left child is greater, so update the swap id
    }

    //check with the swap id for right child
    if(r(i) <= _size && arr[swapId] < arr[r(i)]){
        swapId = r(i); //right child is greater, so update the swap id
    }

    if(swapId != i){
        swap(arr[i], arr[swapId]);
        //recursively do this
        shiftDown(swapId); //we'll swap down, go to children instead of parent like in shiftUp
    }
}

int MaxHeap::extractMax(){
    int maxNum = arr[1];

    //while extracting max, we'll swap it with the minimum number, and this exists at last of arr
    //and also decrease the size, because we are popping
    swap(arr[1], arr[_size--]);

    //and rearrange the heap, so shift down from position 1
    shiftDown(1);

    return maxNum;
}


int main(){
    //create a pointer
    /*MaxHeap* PriorityQueue = new MaxHeap();

    if(PriorityQueue->isEmpty())
        cout << "Yes, this is the correct answer\n";
    else
        cout << "Uh-oh, there's something wrong\n";

    PriorityQueue->insertItem(10);
    PriorityQueue->insertItem(120);
    PriorityQueue->insertItem(34);
    PriorityQueue->insertItem(41);
    PriorityQueue->insertItem(5);

    cout << PriorityQueue->getMax() << "\n";
    PriorityQueue->extractMax();
    cout << PriorityQueue->getMax() << "\n";*/

    MaxHeap pq;

    return 0;
}