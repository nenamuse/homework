// Created by Erica Quintero on 9/15/25
#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "exchanges.h"   // your own templated linked list (no vector)

using namespace std;

template <typename T>
struct Participant {
    T name;
    LinkedList<T> met;    // track people this participant has met in order
    bool finished = false;
    int finishStep = -1;  // interaction number when they finished
};

// helper to find participant index in array
template <typename T>
int findParticipant(Participant<T>* arr, int count, T name) {
    for (int i = 0; i < count; i++) {
        if (arr[i].name == name) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    if (!input.is_open()) {
        cerr << "Error: cannot open input file" << endl;
        return 1;
    }

    int numParticipants;
    input >> numParticipants;

    // store all participants in an array
    Participant<string>* people = new Participant<string>[numParticipants];

    // read ahead to gather participant names
    // since first line after count is a pair, we’ll store them dynamically
    string a, b;
    int totalRead = 0;

    // first pass: collect names
    string names[200];  // enough buffer for participants
    int nameCount = 0;

    while (input >> a >> b) {
        // add a if not already in names
        bool found = false;
        for (int i = 0; i < nameCount; i++) {
            if (names[i] == a) {
                found = true;
                break;
            }
        }
        if (!found) names[nameCount++] = a;

        // add b if not already in names
        found = false;
        for (int i = 0; i < nameCount; i++) {
            if (names[i] == b) {
                found = true;
                break;
            }
        }
        if (!found) names[nameCount++] = b;
    }

    // assign names to participants
    for (int i = 0; i < numParticipants; i++) {
        people[i].name = names[i];
    }

    // reset file to re-read pairs
    input.clear();
    input.seekg(0);
    input >> numParticipants;  // skip first line

    // process interactions
    int step = 0;
    int finishedCount = 0;

    while (input >> a >> b && finishedCount < 3) {
        step++;

        int idxA = findParticipant(people, numParticipants, a);
        int idxB = findParticipant(people, numParticipants, b);

        // add each other if not already met
        if (!people[idxA].met.contains(b)) {
            people[idxA].met.insert(b);
        }
        if (!people[idxB].met.contains(a)) {
            people[idxB].met.insert(a);
        }

        // check if A finished
        if (!people[idxA].finished && people[idxA].met.size() == numParticipants - 1) {
            people[idxA].finished = true;
            people[idxA].finishStep = step;
            finishedCount++;
        }

        // check if B finished
        if (!people[idxB].finished && people[idxB].met.size() == numParticipants - 1) {
            people[idxB].finished = true;
            people[idxB].finishStep = step;
            finishedCount++;
        }
    }

    // now collect finishers in order of finishing
    for (int rank = 1; rank <= 3; rank++) {
        int bestStep = 1e9;
        int winnerIndex = -1;

        for (int i = 0; i < numParticipants; i++) {
            if (people[i].finished && people[i].finishStep < bestStep) {
                // avoid reusing same participant
                bool alreadyPrinted = false;
                for (int j = 1; j < rank; j++) {
                    // simple check if already used
                }
                bestStep = people[i].finishStep;
                winnerIndex = i;
            }
        }

        if (winnerIndex != -1) {
            output << rank << ": " << people[winnerIndex].name << " -> "
                   << people[winnerIndex].met.toString() << endl;

            // mark step very high so they won’t be picked again
            people[winnerIndex].finishStep = 1e9;
        }
    }

    delete[] people;
    input.close();
    output.close();
    return 0;
}

