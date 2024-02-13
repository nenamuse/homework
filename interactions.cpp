#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

struct Handshake {
    int person1;
    int person2;
    int person3;
    int person4;
    int person5;
};

int findWinner(const Handshake* interactions, int numInteractions, int numPerson) {
    int* interactionsCount = new int[numPerson]();

    for (int i = 0; i < numInteractions; ++i) {
        interactionsCount[interactions[i].person1]++;
        interactionsCount[interactions[i].person2]++;
        interactionsCount[interactions[i].person3]++;
        interactionsCount[interactions[i].person4]++;
        interactionsCount[interactions[i].person5]++;
    }

    for (int i = 0; i < numPerson; ++i) {
        if (interactionsCount[i] == numPerson - 1) {
            delete[] interactionsCount;
            return i;
        }
    }

    delete[] interactionsCount;
    return -1;
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream inputFile(am.get("input"));
    ofstream outputFile(am.get("ans"));

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int numParticipants;
    inputFile >> numParticipants;

    const int maxInteractions = 10000;
    Handshake* interactions = new Handshake[maxInteractions];

    int index = 0;
    Handshake handshake;
    while (inputFile >> handshake.person1 >> handshake.person2 >> handshake.person3 >> handshake.person4 >> handshake.person5) {
        interactions[index++] = handshake;
    }

    inputFile.close();

    int winner = findWinner(interactions, index, numParticipants);
    if (winner != -1) {
        outputFile << "The winner is person " << winner << endl;
    } else {
        outputFile << "No winner found." << endl;
    }

    delete[] interactions;
    outputFile.close();

    return 0;
}