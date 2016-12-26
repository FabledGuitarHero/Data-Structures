//
//  main.cpp
//  LinkedList
//
//  Created by Nate Henderson on 12/23/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularlyLinkedList.h"

int main(int argc, const char * argv[]) {
    std::cout << "Singly Linked List: " << std::endl;
    SinglyLinkedList<int> *tmp = new SinglyLinkedList<int>();
    
    tmp -> addFront(10);
    tmp -> addFront(20);
    tmp -> addEnd(5);
    tmp -> addEnd(3);
    std::cout << tmp -> print() << std::endl;
    
    tmp -> removeFront();
    std::cout << tmp -> print() << std::endl;
    tmp -> remove(5);
    std::cout << tmp -> print() << std::endl;
    
    std::cout << "Doubly Linked List: " << std::endl;
    DoublyLinkedList<int> *tmp2 = new DoublyLinkedList<int>();
    tmp2 -> addFront(10);
    tmp2 -> addEnd(15);
    tmp2 -> addFront(5);
    std::cout << tmp2 -> print() << std::endl;
    
    tmp2 ->removeFront();
    std::cout << tmp2 -> print() << std::endl;
    tmp2 ->addFront(30);
    tmp2->remove(10);
    std::cout << tmp2 -> print() << std::endl;
    
    std::cout << "Circularly Linked List: " << std::endl;
    CircularlyLinkedList<int> *tmp3 = new CircularlyLinkedList<int>();
    tmp3 -> addFront(100);
    tmp3 -> addFront(110);
     std::cout << tmp3 -> print() << std::endl;
    tmp3 -> addEnd(120);
    tmp3 -> remove(110);
    std::cout << tmp3 -> print() << std::endl;
}
