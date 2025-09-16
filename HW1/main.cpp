// Created by Erica Quintero on 9/15/25
#include "ArgumentManager.h"
#include <fstream>
#include <iostream>

using namespace std;
const int NUM_VALUES = 15;
const int NUM_SUITS = 5;

void cardParser(int **, string, int, int);

int main(int argc, char *argv[]) {
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream fin(input);
    ofstream fout(output);


}