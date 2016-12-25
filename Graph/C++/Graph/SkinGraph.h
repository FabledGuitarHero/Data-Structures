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
    //Class Variables
    LinkedList<LymphNode<int>, int> *AdjArray[10];
    
    //Constructor
    SkinGraph();
    
    //Class methods
    void addAdj(T vert, T adj);
    void addVert(T vert);
    void removeVert(T vert);
    void print();

private:
    //Class variables
    T vert;
    T adjacent;
    int size;
};

/*
 *  Constructor method - reads in a file and builds an Unweighed Nondirectional
 *    Adjacency graph utilizing Singly Linked List Chaining in an array.
 */
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


/*
 *  Method prints each LinkedList in the array
 */
template <class T>
void SkinGraph<T>::print(){
    for (int i = 1; i <= size; i++){
        if (AdjArray[i] != nullptr)
            std::cout << "Vert: " << i << " Adjacencies: " << AdjArray[i] -> printList() << std::endl;
    }
}


/*
 *  Adds a new adjacency to a specified vertex.  If vertex does not exist, creates it.
 */
template <class T>
void SkinGraph<T>::addAdj(T vert, T adj){
    
    if (!AdjArray[vert] -> contains(adj))
    {
        if (AdjArray[adj] == NULL)
            addVert(adj);
        
        AdjArray[vert] -> insert(adj);
        AdjArray[adj] -> insert(vert);
    }
    
}


/*
 *  Method that adds a vertex to the Adj List
 */
template <class T>
void SkinGraph<T>::addVert(T vert){
    if (AdjArray[vert] == NULL){
        AdjArray[vert] = new LinkedList<LymphNode<int>, int>();
        size++;
    }
}


/*
 *  Removes a vertex from the Adj List
 */
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
