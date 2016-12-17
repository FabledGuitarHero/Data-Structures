//
//  SkinGraph.h
//  Graph
//
//  Created by Nate Henderson on 4/30/16.
//  Copyright © 2016 Nate Henderson. All rights reserved.
//

#ifndef SkinGraph_h
#define SkinGraph_h

#include <fstream>
#include <iostream>
#import "UnorderedLinkedList.h"

template <class T>
class SkinGraph{
public:
    LinkedList<LymphNode<int>, int> *AdjArray[10];
    
    SkinGraph();
    
    void addEdge(T vert, T edge);
    void addVert(T vert);
    void removeVert(T vert);
    void print();

private:
    T vert;
    T adjacent;
    int size;
};

template <class T>
SkinGraph<T>::SkinGraph(){

    
    std::fstream graphDocument("graph.txt");
    if(graphDocument.is_open()){
        std::cout << "File successfully opened" << std::endl;
    }

    graphDocument >> size;
    
    for (int i = 0; i < size; i++){
        graphDocument >> vert;
        graphDocument >> adjacent;
        
        AdjArray[vert] = new LinkedList<LymphNode<int>, int>();
        
        while (adjacent != -999)
        {
            AdjArray[vert]->insert(adjacent);
            graphDocument >> adjacent;
        }
    }
    
}

template <class T>
void SkinGraph<T>::print(){
    for (int i = 1; i <= size; i++){
        if (AdjArray[i] != nullptr)
            std::cout << "Vert: " << i << " Adjacencies: " << AdjArray[i] -> printList() << std::endl;
    }
}

template <class T>
void SkinGraph<T>::addEdge(T vert, T edge){
    
    if (!AdjArray[vert] -> contains(edge))
    {
        if (AdjArray[edge] == NULL)
            addVert(edge);
        
        AdjArray[vert] -> insert(edge);
        AdjArray[edge] -> insert(vert);
    }
    
}

template <class T>
void SkinGraph<T>::addVert(T vert){
    if (AdjArray[vert] == NULL){
        AdjArray[vert] = new LinkedList<LymphNode<int>, int>();
        size++;
    }
}

template <class T>
void SkinGraph<T>::removeVert(T vert){
    int tempSize = AdjArray[vert] -> size();
    int temp;
    
    for (int i = 0; i < tempSize; i++){
        temp  = AdjArray[vert] -> removeBeginning();
        AdjArray[temp] -> remove(vert);
    }
    
    AdjArray[vert] = nullptr;
}



#endif /* SkinGraph_h */
