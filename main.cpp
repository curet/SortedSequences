// JOSE C. S. CURET
// main function

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

#include "Sequences.h"

using namespace std;

int main(){

    string repeatProgram;
    ifstream readFile;
    ofstream saveDataFile;
    string saveData;
    string dataiLesen;

    do{

        vector <Sequences> m;
        getInput(m, readFile, dataiLesen);
        processData(m);
        onFile(m, saveDataFile, saveData);
        runTime(m);

 
        cout <<"Would you like to process another file? (Y/n)\n";
        cin >> repeatProgram;
    
    }while(repeatProgram == "Y" || repeatProgram == "y");
    

    return 0;
}
