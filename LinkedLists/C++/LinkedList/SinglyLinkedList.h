//
//  SinglyLinkedList.h
//  LinkedList
//
//  Created by Nate Henderson on 12/23/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h
#include "SLLNode.h"

template <class Type>
class SinglyLinkedList{
public:
    SLLNode<Type> *head;
    SLLNode<Type> *end;
    int size;
    
    int getSize();
    SLLNode<Type>* getHead();
    SLLNode<Type>* getEnd();
    
    void setSize();
    void setHead();
    void setEnd();
    
    void addFront(Type data);
    void addEnd(Type data);
    void removeFront();
    void remove(Type data);
    SLLNode<Type>* search(Type data);
    std::string print();
    
};

template <class Type>
int SinglyLinkedList<Type>::getSize(){ return size; }

template <class Type>
SLLNode<Type>* SinglyLinkedList<Type>::getHead(){ return head; }

template <class Type>
SLLNode<Type>* SinglyLinkedList<Type>::getEnd(){ return end; }

template <class Type>
void SinglyLinkedList<Type>::addFront(Type data){
    SLLNode<Type> *tmp = new SLLNode<Type>(data, head);
    head = tmp;
    if (size == 0) end = tmp;
    size++;
}

template <class Type>
void SinglyLinkedList<Type>::addEnd(Type data){
    SLLNode<Type> *tmp = new SLLNode<Type>(data, nullptr);
    end -> next = tmp;
    end = tmp;
    if (size == 0) head = tmp;
    size++;
}

template <class Type>
void SinglyLinkedList<Type>::removeFront(){
    head = head ->next;
    size--;
}

template <class Type>
void SinglyLinkedList<Type>::remove(Type data){
    SLLNode<Type> *tmp = search(data);
    if (head->data == data)
        head = head -> next;
    else
        (tmp -> next -> next != nullptr) ? tmp -> next = tmp -> next -> next : tmp -> next = nullptr;
    size--;
}

template <class Type>
SLLNode<Type>* SinglyLinkedList<Type>::search(Type data){
    SLLNode<Type> * tmp = head;
    while (tmp->next != nullptr){
        if (tmp -> next -> data == data)
            return tmp;
        else
            tmp = tmp->next;
    }
    
    return nullptr;
}

template <class Type>
std::string SinglyLinkedList<Type>::print(){
    SLLNode<Type> *tmp = head;
    std::string printString = "";
    while (tmp != nullptr){
        printString.append(std::to_string(tmp -> data) + " ");
        tmp = tmp -> next;
    }
    
    return printString;
}
#endif /* SinglyLinkedList_h */
