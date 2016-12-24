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
    
    //Helper methods
    int size();
    
private:
    //Class variables
    LymphNode *head;
    LymphNode *end;
    int count = 0;
    
    //Methods
    LymphNode* search(LymphNode *cancerNode, Type data);
    void cleanup (LymphNode *cancerNode);
};

/*
 *  Constructor methods
 */
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


/*
 *  Creates a new node and inserts the node at the end of the list
 */
template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::insert(Type data){
    
    LymphNode *cancerNode = new LymphNode(data);
    
    if (count <= 0){
        head = cancerNode;
        end = cancerNode;
    }
    else{
        end -> setNext(cancerNode);
        end = cancerNode;
    }
    
    count++;
    cleanup(cancerNode);
    
};

/*
 *  Creates a new node and inserts the node after a specific node in the list
 */
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

/*
 *  Creates and inserts a new node in the beginning of the list
 */
template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::insertBeginning(Type data){
    LymphNode *cancerNode = new LymphNode(data);
    
    cancerNode-> next = head;
    head = cancerNode;
    count++;
    
    cleanup(cancerNode);
    
};

/*
 *  Removes a specific element from the list
 */
template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::remove(Type data){
    
    LymphNode *placeholder = search(head, data);
    LymphNode *cancerNode = placeholder -> getNext();
    
    if (placeholder -> getData() == data)
        head = placeholder->getNext();
    else if (placeholder -> getNext() -> getNext() != nullptr)
        placeholder -> setNext(placeholder -> getNext() -> getNext());
    else{
        end = placeholder;
        placeholder -> setNext(nullptr);
    }

    
    count--;
    
    cleanup(cancerNode);
    cleanup(placeholder);
};


/*
 *  Pops the first node in the list
 */
template <class LymphNode, class Type>
Type LinkedList<LymphNode, Type>::removeBeginning(){
    LymphNode *cancerNode = head;
    head = head->getNext();
    count--;
    
    Type temp = cancerNode->getData();
    cleanup(cancerNode);
    return temp;
}


/*
 *  Returns the size of the list
 */
template <class LymphNode, class Type>
int LinkedList<LymphNode, Type>::size(){ return count; }

/*
 *  Private method that recusively searches the list for specific data, or returns a nullptr.
 */
template <class LymphNode, class Type>
LymphNode* LinkedList<LymphNode, Type>::search(LymphNode *cancerNode, Type searchData){
    
    if (cancerNode -> getData() == searchData)
        return cancerNode;
    else if (cancerNode -> getNext() == NULL || cancerNode -> getNext() -> getData() == searchData)
        return cancerNode;
    else
        cancerNode = search(cancerNode -> getNext(), searchData);
    
    return cancerNode;
}

/*
 * Calls the search method and checks if the list contains the requested search data
 */
template <class LymphNode, class Type>
bool LinkedList<LymphNode, Type>::contains(Type data){

    LymphNode *cancerNode = search(head, data);
    
    if (cancerNode -> getData() == data){
        cleanup(cancerNode);
        return true;
    }
    else if (cancerNode->getNext() && cancerNode->getNext()->getData() == data){
        
        cleanup(cancerNode);
        return true;
    }
    else{
        cleanup(cancerNode);
        return false;
    }
    
    
}

/*
 *  Appends the list to a string and returns it to be printed
 */
template <class LymphNode, class Type>
std::string LinkedList<LymphNode, Type>::printList(){
    
    LymphNode *cancerNode = head;
    std::string returnString;
    
    while (cancerNode != NULL)
    {
        returnString.append(std::to_string(cancerNode->getData()) + " ");
        cancerNode = cancerNode -> getNext();
    }
    
    cleanup(cancerNode);
    
    return returnString;
}


/*
 *  Method to cleanup unneeded pointers
 */
template <class LymphNode, class Type>
void LinkedList<LymphNode, Type>::cleanup(LymphNode *cancerNode){
    cancerNode = nullptr;
    delete cancerNode;
}


#endif /* UnorderedLinkedList_h */
