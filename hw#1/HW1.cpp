#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include <string>

using namespace std;

struct handshakes{
    int person1;
    int person2;
    int person3; 
    int person4; 
    int person5; 
};


int Win(const handshakes interactions[], int numInteractions, int numPerson)
{
  
    int* interaction_tracker = new int[numPerson];
    for (int i = 0; i < numPerson; i++) {
      interaction_tracker [interactions[i].person1]++;
      interaction_tracker [interactions[i].person2]++;
      interaction_tracker [interactions[i].person3]++;
      interaction_tracker [interactions[i].person4]++;
      interaction_tracker [interactions[i].person5]++;
        if (interaction_tracker[i] == numPerson - 1) {
            delete[] interaction_tracker;
            return i;
        }
    }
  return -1;
};

int main(int argc, char* argv[]){
      ArgumentManager am(argc, argv);
      ifstream inputFile(am.get("input2.txt"));
      ofstream outputFile(am.get("ans2.txt"));
    //ifstream input(am.get("input2.txt")); 
   //ofstream out(am.get("ans2.txt"));
      
      const int max_handshakes = 10000;//allow room for up to 10,000 interactions
      handshakes interactions[max_handshakes];

      int numPerson;
      int index = 0;
      int person1;
      int person2;
      int person3; 
      int person4;
      int person5;
  
      inputFile >> numPerson; 
      while (inputFile >> person1 >> person2 >> person3 >>person4 >>          person5) {
          interactions[index].person1 = person1; 
          interactions[index].person2 = person2;
          interactions[index].person3 = person3; 
          interactions[index].person4 = person4; 
          interactions[index].person5 = person5;
          index++;
      }

      inputFile.close();
      int winner = Win(interactions, index, numPerson);
      if (winner != -1) {
          cout << "The winner is person, " << winner << endl;
      } 
    else{
      cout << "womp. womp." << endl; 
    }
      return 0;
}