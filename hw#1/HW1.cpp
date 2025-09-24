#// Created by Erica Quintero on 9/15/25
#include "ArgumentManager.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream fin(input);
    ofstream fout(output);

    int count = 0;
    fin >> count;
    cout << count << endl;

    // make an array list of type int that resizs itself
    // or an array list of type string that resizes itself


    int first, second = 0;
    //use a structure and contains a list of strings and create a typename for it
    //create an array list that resizes itself.

    while(fin >> first >> second) {
        cout << first << " " << second << endl;

    }



    return 0;


}
