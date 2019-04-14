#ifndef STABILIZER_GENERATE_H
#define STABILIZER_GENERATE_H

#include"graph.h"
#include<stdio.h>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;
class stabilizer_generator : protected graph{





protected:
    int leaves;
    char logical_x[5];
    char logical_z[5];
    std::string code_string;


public:


    void logical_X();
    void logical_Z();
    void logical_I();
    void print_leaf_stabilizers(node* root);
    void propagate_down_stabilizer(node* root, char logical_bit);
    void print_rest_stabilizers(node* root);
    void initialize_stabilizer_generation(node* root);
    void writefile(string str);
    void rightrotate(string &s, int d);
    void leftrotate(string &s, int d);
    stabilizer_generator();

};
#endif // STABILIZER_GENERATE_H
