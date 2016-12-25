//
//  main.cpp
//  LinkedList
//
//  Created by Nate Henderson on 12/23/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#include <iostream>
#include "SinglyLinkedList.h"
//#include "SLLNode.h"

int main(int argc, const char * argv[]) {
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
}
