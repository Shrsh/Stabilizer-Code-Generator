/*
 * Author : Harsh Shukla
 * 12-04-2019
 */


#include "graph.h"
#include<iostream>
#include<stdio.h>

using namespace std;

graph::graph(){
    cout << "Create the graph for generating Stabiliaer Code" << endl;
    cout << "===============================================" << endl;
    cout << "Enter the number of levels in the complete 5-ary tree" << endl;
    cin >> levels;
    return;
}

node* graph::createnode(){
    node* n = (node*)malloc(sizeof(node));
    if(n == NULL)
        cout << "Error, cannot be created" << endl;
    else{
        cout << "Creating a node" << endl;
        for(int i=0;i<4;i++)
            for(int j=0;j<5;j++)
               cin >> n->codes[i][j];
        cout << "node created"<<endl;
    }
    return n ;
}

node* graph::connecttree(node* x,int level){
    if(level <= 1){
        for(int j=0;j<5;j++)
            x->child[j] = NULL;
        return x;
    }
    else{
        for(int j=0;j<5;j++){
            x->child[j] = connecttree(createnode(),level-1) ;
        }
        return x;
    }
}

node* graph::completetree(){
    cout << "Total number of levels: " << levels <<endl;
    cout << "Initialising a Tree" <<endl;
    cout << "===================" <<endl;
    node* tree = connecttree(createnode(), levels);
    return tree;
}

void graph::printnode(node* root){
    for(int j=0; j<N;j++){
        for(int k=0;k<M;k++)
          cout << root->codes[j][k];
        cout << endl;
}
    return;
}

void graph::printtree(node *root){
     if(root == NULL)
         return ;
     else{
         printtree(root->child[0]);
         printtree(root->child[1]);
         printtree(root->child[2]);
         printtree(root->child[3]);
         cout<<"NODE CODE VALUES"<<endl;
         printnode(root);
     }
}

