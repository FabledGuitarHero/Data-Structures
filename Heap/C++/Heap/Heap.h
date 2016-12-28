//
//  Heap.h
//  Heap
//
//  Created by Nate Henderson on 12/27/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include <vector>

class Heap{
public:
    Heap();
    int removeMin();
    void insert(int i);
    std::string printHeap();

private:
    std::vector<int> *heap;
    int size;
    
    int parent(int j);
    int left (int j);
    int right (int j);
    bool hasLeft(int j);
    bool hasRight(int j);
    
    void swap(int i, int j);
    int getSize();
    void bubbleUp (int index);
    void bubbledown (int index);
};

Heap::Heap(){
    size = 0;
    heap->reserve(1000);
}

int Heap::parent(int j) { return (j-1)/2; }
int Heap::left(int j) { return (j*2)+1; }
int Heap::right(int j) { return (j*2)+2; }
bool Heap::hasLeft(int j) { return (heap->at(left(j)) > 0); }
bool Heap::hasRight(int j) { return (heap->at(right(j))> 0); }

int Heap::getSize(){ return size; }

void Heap::insert(int i){
    if (size == 1000)
        std::cout << "Heap Full" << std::endl;
    else{
        heap->at(size) = i;
        bubbleUp(size);
        size++;
    }
}

void Heap::swap(int i, int j){
    int temp = heap->at(i);
    heap[i] = heap[j];
    heap->at(j) = temp;
}

void Heap::bubbleUp(int index){
    int parentIndex;
    if (index != 0){
        parentIndex = parent(index);
        if (heap->at(parentIndex) > heap->at(index)){
            swap(index, parentIndex);
            bubbleUp(parentIndex);
        }
    }
    
}

void Heap::bubbledown(int parentIndex){
    int leftIndex = left(parentIndex);
    int rightIndex = right(parentIndex);
    int newParent;
    
    if (rightIndex > getSize())
        if (leftIndex > getSize())
            return;
        else
            newParent = leftIndex;
    else
        (heap[leftIndex] <= heap[rightIndex])? newParent = leftIndex : newParent = rightIndex;
    
    //Swap and bubbledown again
    if (heap[parentIndex] >= heap[newParent]){
        swap(parentIndex, newParent);
        bubbledown(newParent);
    }
        
    
}

int Heap::removeMin(){
    int returnValue = heap->at(0);
    heap[0] = heap[size-1];
    heap->at(size-1) = 0;
    size--;
    bubbledown(0);
    
    return returnValue;
}

std::string Heap::printHeap(){
    std::string returnString = "";
    return returnString;
}



#endif /* Heap_h */
