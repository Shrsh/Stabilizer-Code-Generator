/*
 * Author : Harsh Shukla
 * 12-04-2019
 */




#include<iostream>
#include<stdio.h>
#include<graph.h>
#include<stabilizer_generate.h>

using namespace std;



int main(){
    cout << "Graph Input Process" << endl;
    graph* tree = new graph();
    cout << "Initialising Complete Tree" <<endl;
    node* stabilizer_tree = tree->completetree();
//    cout << "Printing the Tree" <<endl;
//    cout << "=================" <<endl;
//    tree->printtree(stabilizer_tree);

//    Stabilizer Codes Generation
    stabilizer_generator* code = new stabilizer_generator();
    code->initialize_stabilizer_generation(stabilizer_tree);
    delete tree;
    return 0;

}



