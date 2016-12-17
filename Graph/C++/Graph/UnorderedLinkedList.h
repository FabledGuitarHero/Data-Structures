//
//  UnorderedLinkedList.h
//  LinkedList
//
//  Created by Nate Henderson on 4/27/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef UnorderedLinkedList_h
#define UnorderedLinkedList_h

#include "LymphNode.h"

template <class LymphNode, class Type>
class LinkedList {
    
public:
    //Constructors
    LinkedList();
    LinkedList(Type data);
    
    //Class methods
    std::string printList();
    void insert(Type data);
    void insertAfter(Type data, Type newData);
    void insertBeginning(Type data);
    void remove(Type data);
    Type removeBeginning();
    bool contains(Type data);
    
    //Helper classes
    int size();
    
private:
    LymphNode *head;
    LymphNode *end;
    LymphNode* search(LymphNode *cancerNode, Type data);
    int count = 0;
    void cleanup (LymphNode *cancerNode);
    
};

template <class LymphNode, class Type>
LinkedList<LymphNode, Type>::LinkedList(){ head = nullptr; };

template <class LymphNode, class Type>
LinkedList<LymphNode, Type>::LinkedList(Type data){
    LymphNode *cancerNode = new LymphNode(data);
    
    head = cancerNode;
    end = cancerNode;
    
    count++;
    
    cleanup(cancerNode);
};

template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::insert(Type data){
    
    LymphNode *cancerNode = new LymphNode(data);
    
    if (count <= 0){
        head = cancerNode;
        end = cancerNode;
    }
    else{
        end -> next = cancerNode;
        end = cancerNode;
    }
    
    count++;
    
    cleanup(cancerNode);
    
};


template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::insertAfter(Type data, Type newData){

    LymphNode *cancerNode = new LymphNode(newData);
    LymphNode *placeholder = search(head, data);
    
    cancerNode -> next = placeholder -> next;
    placeholder -> next = cancerNode;
    
    if (cancerNode -> next == nullptr)
        end = cancerNode;
    count++;
    
    cleanup(cancerNode);
    cleanup(placeholder);
    
};


template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::insertBeginning(Type data){
    LymphNode *cancerNode = new LymphNode(data);
    
    cancerNode-> next = head;
    head = cancerNode;
    count++;
    
    cleanup(cancerNode);
    
};


template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::remove(Type data){
    
    LymphNode *placeholder = search(head, data);
    LymphNode *cancerNode = placeholder -> next;
    
    if (placeholder -> data == data)
        head = placeholder->next;
    else if (placeholder -> next -> next != nullptr)
        placeholder -> next = placeholder -> next -> next;
    else{
        end = placeholder;
        placeholder -> next = nullptr;
    }

    
    count--;
    
    cleanup(cancerNode);
    cleanup(placeholder);
};


template <class LymphNode, class Type>
Type LinkedList<LymphNode, Type>::removeBeginning(){
    LymphNode *cancerNode = head;
    head = head->next;
    count--;
    
    Type temp = cancerNode->data;
    cleanup(cancerNode);
    return temp;
}

template <class LymphNode, class Type>
int LinkedList<LymphNode, Type>::size(){
    return count;
}

template <class LymphNode, class Type>
LymphNode* LinkedList<LymphNode, Type>::search(LymphNode *cancerNode, Type searchData){
    
    if (cancerNode -> data == searchData)
        return cancerNode;
    else if (cancerNode -> next == NULL || cancerNode -> next -> data == searchData)
        return cancerNode;
    else
        cancerNode = search(cancerNode -> next, searchData);
    
    return cancerNode;
}

template <class LymphNode, class Type>
bool LinkedList<LymphNode, Type>::contains(Type data){

    LymphNode *cancerNode = search(head, data);
    
    if (cancerNode -> data == data){
        cleanup(cancerNode);
        return true;
    }
    else if (cancerNode->next && cancerNode->next->data == data)
    {
        
        cleanup(cancerNode);
        return true;
    }
    else
    {
        cleanup(cancerNode);
        return false;
    }
    
    
}

template <class LymphNode, class Type>
std::string LinkedList<LymphNode, Type>::printList(){
    
    LymphNode *cancerNode = head;
    std::string returnString;
    
    while (cancerNode != NULL)
    {
        returnString.append(std::to_string(cancerNode->data) + " ");
        cancerNode = cancerNode ->next;
    }
    
    cleanup(cancerNode);
    
    return returnString;
}

template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::cleanup(LymphNode *cancerNode){
    cancerNode = nullptr;
    delete cancerNode;
}


#endif /* UnorderedLinkedList_h */
