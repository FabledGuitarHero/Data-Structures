//
//  DoublyLinkedList.h
//  LinkedList
//
//  Created by Nate Henderson on 12/25/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "DLLNode.h"


template <class Type>
class DoublyLinkedList{
public:
    DLLNode<Type> *head;
    DLLNode<Type> *end;
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
int DoublyLinkedList<Type>::getSize(){ return size; }

template <class Type>
DLLNode<Type>* DoublyLinkedList<Type>::getHead(){ return head; }

template <class Type>
DLLNode<Type>* DoublyLinkedList<Type>::getEnd(){ return end; }

template <class Type>
void DoublyLinkedList<Type>::addFront(Type data){
    DLLNode<Type> *tmp = new DLLNode<Type>(data, head, nullptr);
   
    (size == 0)? end = tmp : head -> prev = tmp;
    head = tmp;
    
    size++;
}

template <class Type>
void DoublyLinkedList<Type>::addEnd(Type data){
    DLLNode<Type> *tmp = new DLLNode<Type>(data, nullptr, end);
    end -> next = tmp;
    end = tmp;
    if (size == 0) head = tmp;
    size++;
}

template <class Type>
void DoublyLinkedList<Type>::removeFront(){
    head = head ->next;
    head -> prev = nullptr;
    size--;
}

template <class Type>
void DoublyLinkedList<Type>::remove(Type data){
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
DLLNode<Type>* DoublyLinkedList<Type>::search(Type data){
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
std::string DoublyLinkedList<Type>::print(){
    DLLNode<Type> *tmp = head;
    std::string printString = "";
    while (tmp != nullptr){
        printString.append(std::to_string(tmp -> data) + " ");
        tmp = tmp -> next;
    }
    
    return printString;
}

#endif /* DoublyLinkedList_h */
