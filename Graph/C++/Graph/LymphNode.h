//
//  LymphNode.h
//  LinkedList
//
//  Created by Nate Henderson on 4/27/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef LymphNode_h
#define LymphNode_h

template <class Type>
struct LymphNode {
private:
    Type data;
    LymphNode<Type> *next;
public:
    LymphNode();
    LymphNode(Type newData);
    
    Type getData();
    LymphNode<Type>* getNext();
    void setData(Type data);
    void setNext(LymphNode *next);
};

/*
 * Constructors
 */
template <class Type>
LymphNode<Type>::LymphNode(){
    data;
    next = nullptr;
}

template <class Type>
LymphNode<Type>::LymphNode(Type newData){
    data = newData;
    next = nullptr;
}


/*
 * Accessor methods
 */
template <class Type>
Type LymphNode<Type>::getData(){ return this->data; }
template <class Type>
LymphNode<Type>* LymphNode<Type>::getNext(){ return next; }

/*
 * Setter methods
 */
template <class Type>
void LymphNode<Type>::setData(Type data){ this->data = data; }
template <class Type>
void LymphNode<Type>::setNext(LymphNode<Type> *next){ this->next = next; }


#endif /* LymphNode_h */
