//
//  CircularlyLinkedList.h
//  LinkedList
//
//  Created by Nate Henderson on 12/25/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef CircularlyLinkedList_h
#define CircularlyLinkedList_h

#include "DLLNode.h"


template <class Type>
class CircularlyLinkedList{
public:
    DLLNode<Type> *head;
    int size;
    
    int getSize();
    DLLNode<Type>* getHead();
    DLLNode<Type>* getEnd();
    
    void setSize();
    void setHead();
    void setEnd();
    
    void addFront(Type data);
    void addEnd(Type data);
    void removeFront();
    void remove(Type data);
    DLLNode<Type>* search(Type data);
    std::string print();
    
};

template <class Type>
int CircularlyLinkedList<Type>::getSize(){ return size; }

template <class Type>
DLLNode<Type>* CircularlyLinkedList<Type>::getHead(){ return head; }

template <class Type>
DLLNode<Type>* CircularlyLinkedList<Type>::getEnd(){ return head -> prev; }

template <class Type>
void CircularlyLinkedList<Type>::addFront(Type data){
    head = new DLLNode<Type>(data, head, head);
    if (!(size == 0))
        head -> prev -> next = head;
    size++;
}

template <class Type>
void CircularlyLinkedList<Type>::addEnd(Type data){
    DLLNode<Type> *tmp = new DLLNode<Type>(data, head, head->prev);
    if (size == 0) head = tmp;
    else{
        head->prev->next = tmp;
        head->prev = tmp;
    }
    size++;
}

template <class Type>
void CircularlyLinkedList<Type>::removeFront(){
    head = head ->next;
    head -> prev = nullptr;
    size--;
}

template <class Type>
void CircularlyLinkedList<Type>::remove(Type data){
    if (head->data == data){
        head = head -> next;
        head -> prev = nullptr;
    }
    else{
        DLLNode<Type> *tmp = search(data);
        tmp -> prev -> next = tmp -> next;
        tmp -> next -> prev = tmp -> prev;
    }
    size--;
}

template <class Type>
DLLNode<Type>* CircularlyLinkedList<Type>::search(Type data){
    DLLNode<Type> * tmp = head;
    while (tmp->next != nullptr){
        if (tmp -> data == data)
            return tmp;
        else
            tmp = tmp->next;
    }
    
    return nullptr;
}

template <class Type>
std::string CircularlyLinkedList<Type>::print(){
    DLLNode<Type> *tmp = head;
    std::string printString = "";
    for (int i = 0; i < size; i++){
        printString.append(std::to_string(tmp -> data) + " ");
        tmp = tmp -> next;
    }
    
    return printString;
}

#endif /* CircularlyLinkedList_h */
