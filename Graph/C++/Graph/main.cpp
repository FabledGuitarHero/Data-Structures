//
//  main.cpp
//  Graph
//
//  Created by Nate Henderson on 4/30/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#include <iostream>
#include "SkinGraph.h"

int main(int argc, const char * argv[]) {
    
    SkinGraph<int> *myGraph = new SkinGraph<int>();
    std::cout << "Graph from file: " << std::endl;
    myGraph->print();
    std::cout << std::endl;
    
    
    myGraph -> addAdj(1, 5);
    myGraph -> addAdj(1, 6);
    myGraph -> addAdj(2, 6);
    
    std::cout << "After manual add: " << std::endl;
    myGraph -> print();
    std::cout << std::endl;
    
    std::cout << "After manual remove:" << std::endl;
    myGraph -> removeVert(1);
    myGraph -> print();
}
