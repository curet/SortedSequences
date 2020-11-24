// JOSE C. S. CURET

// glosary
/*
    Files: Sequences.h   [Struct, functions prototypes and glosary]
           Sequences.cpp [Functions definition]
           main.cpp      [main funcion]
    
    Purpose: A program that takes a file of random numbers and normalize them.
             Then get the mean and standard deviation.
             Save that progress and then use Bubble and Selection Sorting
             algorithms to rearrange the sequences to save them at the bottom
             in the same file.



 * ***********
 *  Variables
 * ***********
 *   
 *   struct Sequences                        // structure containing variables and vectors related to genate and transform sequences
 *   int numberOfSequences;                  // receive the number of sequences the user wants to process
 *   string IDs;                             // receive a string of IDS from the file is being read
 *   vector <double> randomSequences;        // receive generated random sequences from file
 *   double clicks;                          // receive clicks (time it took per sequences) to be generated
 *   double maximum;                         // receive largest number of the file per sequence
 *   int rows;                               // count rows of file
 *   vector <double> normalizedSequences;    // receive normalized sequences after processed
 *   double mean;                            // get the calculated mean per sequence
 *   double standardDeviation;               // get the calculated standard deviation per sequence
 *   double smallestNumber;                  // get the smallest number of the normalized sequence
 *   vector <int> coordinates;               // get the position of the smallest number
 *   double BubbleOrdRecord;                 // get the time it took the bubble algorithm that ordered records
 *   double SelectOrdRecord;                 // get the time it took the selection algorithm that ordered records
 *   double BubbleOrdSecuencias;             // get the time it took the bubble algorithm that ordered sequences
 *   double SelectOrdSecuencias;             // get the time it took the selection algorithm that ordered sequences
 *   string dataiLesen;                      // get the name of the file is going to be read
 *   ifstream readFile;                      // open the file to read
 *   string repeatProgram;                   // get the user iput Y or y to repeat program
 *   oftream saveDataFile;                   // open the file to be saved
 *   string saveData;                        // get the name of the file where things are going to be saved
 *   double duration;                        // calculate the duration of the algorithms
 *   bool swapped;                           // get false or true of bubble algorithm was swapped
 *   double time;                            // get time from the clocks of duration of sequences
 *   m.push_back(Sequences());               // open a space in the structure vect 'm'
 *   vector <Sequences> m;                   // definition of the vector of structure Sequences
 *   const int COL                           // get a contant size for the columns
 *   int choice;                             // save choice in getInput function on how to process file, continue original input, new input or read the whole file
 *   int sequencesToread;                    // get the user input whether to read a specific amount or the whole file
 * 
 * 
 * ***********
 *  Functions
 * ***********
 * 
 *   void getInput();                        // receive user input of file to read and number of sequences to generate
 *   void getSequences();                    // get the sequences from the file into randomSequences variable
 *   void normalizeSequences();              // normalize received sequences and save it into vector normalizedSequences
 *   void getMean();                         // calculate the mean per sequence
 *   void getStandardDeviation();            // calculate the standard deviation per sequence
 *   void getSmallestNumber();               // get the smallest number of the normalized sequences
 *   void saveNormalized();                  // save normalize sequences with mean and standard deviation in a file
 *   void bubbleValues();                    // order sequences on each row
 *   void selectionValues();                 // order sequences on each row
 *   void selectionSequences();              // order sequences using mean as reference
 *   void bubbleSequences();                 // order sequences using mean as reference
 *   void saveBubbleValues();                // save sorted numbres by bubble algorithm (per sequence) in a file
 *   void saveSelectionvalues();             // save sorted numbres by selection algorithm (per sequence) in a file
 *   void saveBubbleSequences();             // save sorted numbres by bubble algorithm (per mean) in a file
 *   void saveSelectionSequences();          // save sorted numbres by selection algorithm (per mean) in a file
 *   void processData();                     // execute the funcions normalizeSequences, getMean, getStandarDeviation and getSmallestNumber
 *   void runTime();                         // display the running time of each algorithm per situation
 *   void onFile();                          // save all save.. functions into the file 
 *   void inputSave();                       // receive input for file to be saved.
 *   void sortingSaveFormat();               // contains the output format for the sorting sequences table
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#ifndef SEQUENCES_H
#define SEQUENCES_H

const int COL = 10;

// struct declaration

struct Sequences{

    int numberOfSequences;
    string IDs;
    vector <double> randomSequences;
    double clicks;
    double maximum;
    int rows;
    vector <double> normalizedSequences;
    double mean;
    double standardDeviation;
    double smallestNumber;
    vector <int> coordinates;
    double BubbleOrdRecord;
    double SelectOrdRecord;
    double BubbleOrdSecuencias;
    double SelectOrdSecuencias;
};

// functions prototypes

void getInput(vector <Sequences> &m, ifstream &readFile, string &dataiLesen);
void getSequences(vector <Sequences> &m, ifstream &readFile, string &dataiLesen);
void normalizeSequences(vector <Sequences> &m);
void getMean(vector <Sequences> &m);
void getStandardDeviation(vector <Sequences> &m);
void getSmallestNumber(vector <Sequences> &m);
void saveNormalized(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void bubbleValues(vector <Sequences> &m);
void selectionValues(vector <Sequences> &m);
void selectionSequences(vector <Sequences> &m);
void bubbleSequences(vector <Sequences> &m);
void saveBubbleValues(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void saveSelectionvalues(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void saveBubbleSequences(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void saveSelectionSequences(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void processData(vector <Sequences> &m);
void runTime(vector <Sequences> &m);
void onFile(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);
void inputSave(ofstream &saveDataFile, string &saveData);
void sortingSaveFormat(vector <Sequences> &m, ofstream &saveDataFile, string &saveData);

#endif
