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
    Type data;
    LymphNode<Type> *next;
    
    LymphNode();
    LymphNode(Type newData);
    
    Type getData();
    Type getNext();
    void setData(Type data);
    void setNext(LymphNode next);
};

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



#endif /* LymphNode_h */
