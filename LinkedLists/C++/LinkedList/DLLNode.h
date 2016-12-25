//
//  DLLNode.h
//  LinkedList
//
//  Created by Nate Henderson on 12/25/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef DLLNode_h
#define DLLNode_h


template <class Type>
class DLLNode{
public:
    Type data;
    DLLNode *next;
    DLLNode *prev;
    
    DLLNode();
    DLLNode(Type newData);
    DLLNode(Type newData, DLLNode<Type> *newNext, DLLNode<Type> *newPrev);
    
    Type getData();
    DLLNode<Type>* getNext();
    DLLNode<Type>* getPrev();
    
    void setData(Type newData);
    void setNext(DLLNode<Type>* newNext);
    void setPrev(DLLNode<Type>* newPrev);
};

/*
 * Constructors
 */
template <class Type>
DLLNode<Type>::DLLNode(){
    data;
    next = nullptr;
    prev = nullptr;
}

template <class Type>
DLLNode<Type>::DLLNode(Type newData){
    data = newData;
    next = nullptr;
    prev = nullptr;
}

template <class Type>
DLLNode<Type>::DLLNode(Type newData, DLLNode<Type> *newNext, DLLNode<Type> *newPrev){
    data = newData;
    next = newNext;
    prev = newPrev;
}

/*
 *  Accessor Methods
 */
template <class Type>
Type DLLNode<Type>::getData(){return data;}

template <class Type>
DLLNode<Type>* DLLNode<Type>::getNext(){ return next; }

template <class Type>
DLLNode<Type>* DLLNode<Type>::getPrev(){ return prev; }


/*
 *  Setter methods
 */
template <class Type>
void DLLNode<Type>::setNext(DLLNode<Type>* newNext){ next = newNext; }

template <class Type>
void DLLNode<Type>::setData(Type newData) { data = newData; }

template <class Type>
void DLLNode<Type>::setPrev(DLLNode<Type>* newPrev) { prev = newPrev; }

#endif /* DLLNode_h */
