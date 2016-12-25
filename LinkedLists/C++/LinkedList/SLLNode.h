//
//  SLLNode.h
//  LinkedList
//
//  Created by Nate Henderson on 12/23/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef SLLNode_h
#define SLLNode_h

template <class Type>
class SLLNode{
public:
    Type data;
    SLLNode *next;
    
    SLLNode();
    SLLNode(Type newData);
    SLLNode(Type newData, SLLNode<Type> *newNext);
    
    Type getData();
    SLLNode<Type>* getNext();
    
    void setData(Type newData);
    void setNext(SLLNode<Type>* newNext);
};

/*
 * Constructors
 */
template <class Type>
SLLNode<Type>::SLLNode(){
    data;
    next = nullptr;
}

template <class Type>
SLLNode<Type>::SLLNode(Type newData){
    data = newData;
    next = nullptr;
}

template <class Type>
SLLNode<Type>::SLLNode(Type newData, SLLNode<Type> *newNext){
    data = newData;
    next = newNext;
}

/*
 *  Accessor Methods
 */
template <class Type>
Type SLLNode<Type>::getData(){return data;}

template <class Type>
SLLNode<Type>* SLLNode<Type>::getNext(){ return next; }


/*
 *  Setter methods
 */
template <class Type>
void SLLNode<Type>::setNext(SLLNode<Type>* newNext){ next = newNext; }

template <class Type>
void SLLNode<Type>::setData(Type newData) { data = newData; }

#endif /* SLLNode_h */
