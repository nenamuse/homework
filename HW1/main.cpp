// Created by Erica Quintero on 9/15/25
#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
#include <interactions.h>

using namespace std;


int main(int argc, char *argv[]) {
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream fin(input);
    ofstream fout(output);


   Interactions<int> list;



    return 0;


}
