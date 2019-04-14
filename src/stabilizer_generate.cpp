/*
 * Author : Harsh Shukla
 * 12-04-2019
 */

#include "graph.h"
#include "stabilizer_generate.h"
#include <math.h>
#include<bits/stdc++.h>
#include <string>

using namespace std;

stabilizer_generator::stabilizer_generator(){
    cout << "Stabilizer Code Generation" <<endl;
    cout << "==========================" << endl;
}

void stabilizer_generator::propagate_down_stabilizer(node *root, char logical_bit){
    if (root->child[0] == NULL || root->child[1] == NULL || root->child[2] == NULL || root->child[3] == NULL || root->child[4] == NULL){
        if(logical_bit == 'X')
            logical_X();
        else if (logical_bit == 'Z')
            logical_Z();
        else
            logical_I();
    }
    else {
        if (logical_bit = 'X'){
            propagate_down_stabilizer(root->child[0], 'X');
            propagate_down_stabilizer(root->child[1], 'X');
            propagate_down_stabilizer(root->child[2], 'X');
            propagate_down_stabilizer(root->child[3], 'X');
            propagate_down_stabilizer(root->child[4], 'X');
        }

        else if (logical_bit = 'Z'){
            propagate_down_stabilizer(root->child[0], 'Z');
            propagate_down_stabilizer(root->child[1], 'Z');
            propagate_down_stabilizer(root->child[2], 'Z');
            propagate_down_stabilizer(root->child[3], 'Z');
            propagate_down_stabilizer(root->child[4], 'Z');
        }
        else{
            propagate_down_stabilizer(root->child[0], 'I');
            propagate_down_stabilizer(root->child[1], 'I');
            propagate_down_stabilizer(root->child[2], 'I');
            propagate_down_stabilizer(root->child[3], 'I');
            propagate_down_stabilizer(root->child[4], 'I');
        }

    }
}

void stabilizer_generator::logical_X(){
    code_string.append("XXXXX");
}

void stabilizer_generator::logical_Z(){
    code_string.append("ZZZZZ");
}

void stabilizer_generator::logical_I(){
    code_string.append("IIIII");

}

void stabilizer_generator::leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void stabilizer_generator::rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}


void stabilizer_generator:: writefile (string str){

}


void stabilizer_generator::initialize_stabilizer_generation(node *root){
    cout << "Results will be written out in the form of a text file" <<endl;
    cout << "======================================================" <<endl;
    cout << "======================================================" <<endl;
    print_leaf_stabilizers(root);
    ofstream myfile;
    myfile.open ("results_non_leaf.txt");
    myfile << "NON LEAF STABILIZERS" << endl;
    myfile << "" <<endl;
    for (int i=0;i<4;i++){
        propagate_down_stabilizer(root->child[0],root->codes[i][0]);
        propagate_down_stabilizer(root->child[1],root->codes[i][1]);
        propagate_down_stabilizer(root->child[2],root->codes[i][2]);
        propagate_down_stabilizer(root->child[3],root->codes[i][3]);
        propagate_down_stabilizer(root->child[4],root->codes[i][4]);
        myfile << code_string << endl;
        code_string.clear();
    }
    myfile.close();
    cout << " THE END" << endl;

}

void stabilizer_generator::print_leaf_stabilizers( node *root){
    ofstream myfile;
    myfile.open ("results.txt");
//    cout << "printing leaf stabilizer" <<endl;
   // int no_of_leaves = pow(5,levels);
    char code[4][25] = {};
    while(root->child[0] != NULL)
        root = root->child[0];
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            code[i][j] = root->codes[i][j];
        }
        char *c = "IIIIIIIIIIIIIIIIIIII";
        strcat(code[i],c);
        string final_string = code[i];
        myfile << final_string << endl;
    }
    myfile << "" <<endl;
    for(int j=1; j<= 4 ; j++){
       for(int i=0;i<4;i++){
            string s;
            for(int l=0;l<25;l++)
                s.push_back(code[i][l]);
            rightrotate(s, 5*j);
            myfile << s << endl;
        }
       myfile << "" <<endl;
     }
    myfile.close();
}
