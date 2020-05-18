// JOSE C. S. CURET
// functions definitions

#include "Sequences.h"

void getInput(vector <Sequences> &m, ifstream &readFile, string &dataiLesen){

    cout <<"Enter the name of the file with extension you want to analize: ";
    cin >> dataiLesen;
    readFile.open(dataiLesen);

    while(readFile.fail()){
        readFile.clear();
        cout << "Input fail!\n";
        cout << "Try again!\n";
        cin >> dataiLesen;
        readFile.open(dataiLesen);
    }

    getSequences(m, readFile,dataiLesen);
    
    m.push_back(Sequences());
    int sequencesToread;
    cout<<"Do you want to read a specific amount of sequences or the whole file?\n";
    cout<<"\n[1]. A specific amount\n";
    cout<<"[2]. The whole file\n";
    cin >> sequencesToread;
    if(sequencesToread == 1){
        cout<<"Enter the number of sequences you want to analize: ";
        cin >> m[0].numberOfSequences;
    }
    else{
        m[0].numberOfSequences = m[0].rows;
    }

        int choice=-1;
    while(m[0].numberOfSequences > m[0].rows && choice != 1 && choice != 3 && choice != 2){
     
        cout <<"\nYou have chosen more than the "<< m[0].rows << " available sequences!\n";
        cout <<"\nExtra unavailable sequences might be saved as random symbols\n";
        cout <<"These are the options: ";
        cout <<"\n\n[1]. Continue with original input";
        cout <<"\n[2]. Enter new input";
        cout <<"\n[3]. Read the whole file\n";
        cin >> choice;

        if(choice == 1) {
            int temp = m[0].numberOfSequences;
            int zeros = abs(m[0].numberOfSequences - m[0].rows);
            for(int i=(m[0].rows-1); i<(m[0].rows+zeros); i++){
                for(int j=0; j<COL; j++){
                    m[i].randomSequences.push_back(0);
                }
            }
            m[0].numberOfSequences = temp;
        }
        if(choice == 2){
            cout<<"Enter the number of sequences you want to analize: ";
            cin >> m[0].numberOfSequences;

            if(m[0].numberOfSequences > m[0].rows){
                int temp = m[0].numberOfSequences;
            int zeros = abs(m[0].numberOfSequences - m[0].rows);
            for(int i=(m[0].rows-1); i<(m[0].rows+zeros); i++){
                for(int j=0; j<COL; j++){
                    m[i].randomSequences.push_back(0);
                }
            }
            m[0].numberOfSequences = temp;
            }

        }
    
        if(choice == 3){
            m[0].numberOfSequences = m[0].rows;
        } 
    }
}


void getSequences(vector <Sequences> &m, ifstream &readFile, string &dataiLesen){

    m.push_back(Sequences());
    m[0].rows =0;

    while(!readFile.eof()){
        m.push_back(Sequences());
        readFile >> m[m[0].rows].IDs;

        for (int k=0; k<COL; k++){   
    
         m[m[0].rows].randomSequences.push_back(k);
         readFile  >> m[m[0].rows].randomSequences[k];

        }    
        m.push_back(Sequences());
        readFile >> m[m[0].rows].clicks;

        m.push_back(Sequences());
        readFile >> m[m[0].rows].maximum;

    m[0].rows++;
    }

    readFile.close();

}


void normalizeSequences(vector <Sequences> &m){

    for(int i=0; i < m[0].numberOfSequences; i++){

        for (int j=0; j<COL; j++){
            m[i].normalizedSequences.push_back(j);
            m[i].normalizedSequences[j] = m[i].randomSequences[j] / m[i].maximum;

        }
    }

}


void getMean(vector <Sequences> &m){

    for(int i=0; i<m[0].numberOfSequences; i++){

        double getMean = 0;         
        for(int j=0; j<10; j++){
            getMean += m[i].normalizedSequences[j];
        }

        m.push_back(Sequences());
        m[i].mean= getMean/10;

    }
}


void getStandardDeviation(vector <Sequences> &m){

     for(int i=0; i<m[0].numberOfSequences; i++){

        m.push_back(Sequences());
        for(int j=0; j<10; j++){

            m[i].standardDeviation =
            sqrt(pow((m[i].normalizedSequences[j] -
            m[i].mean), 2)/m[0].numberOfSequences);

        }               
    }
}


void getSmallestNumber(vector <Sequences> &m){

        m.push_back(Sequences());
        m[0].smallestNumber = INFINITY;
        m[0].coordinates.resize(2);
    
    for(int i=0; i <m[0].numberOfSequences; i++){

        for(int j=0; j <m[i].normalizedSequences.size(); j++){

            if(m[0].smallestNumber > m[i].normalizedSequences[j]){
            m[0].smallestNumber = m[i].normalizedSequences[j];
            m[0].coordinates[1] = i, m[0].coordinates[2] = j;
                                                                                 
            }
        }
    }
}


void bubbleValues(vector <Sequences> &m){

    clock_t clicks;
    clicks = clock();
  
    m.push_back(Sequences());
    m[0].BubbleOrdSecuencias=0;
        bool swapped;
    do{
        swapped = false;
        for(int i=0; i<m[0].numberOfSequences; i++){
            for(int j=0; j<COL-1; j++){

                if(m[i].normalizedSequences[j] > m[i].normalizedSequences[j+1]){
                    swap(m[i].normalizedSequences[j], m[i].normalizedSequences[j+1]);
                    swapped = true;
                }
            }
        }
        clicks = clock() - clicks;

        m[0].BubbleOrdSecuencias = static_cast<double>(clicks)/
        static_cast<double>(CLOCKS_PER_SEC); 

    }while(swapped);

}


void selectionValues(vector <Sequences> &m){

     clock_t clicks;
    clicks = clock();

    m.push_back(Sequences());
    m[0].SelectOrdSecuencias=0;
    for (int i = 0; i < m[0].numberOfSequences; i++){

        double startScan, minIndex, minValue;
        for(startScan=0; startScan<(10-1); startScan++){
            minIndex = startScan;
            minValue = m[i].normalizedSequences[startScan];

            for(double index = startScan + 1; index < 10; index++){
                if(m[i].normalizedSequences[index] < minValue){
                    minValue = m[i].normalizedSequences[index];
                    minIndex = index;
                }
            }
            m[i].normalizedSequences[minIndex] = m[i].normalizedSequences[startScan];
            m[i].normalizedSequences[startScan] = minValue;
        
        }

        m[0].SelectOrdSecuencias = static_cast<double>(clicks)/
        static_cast<double>(CLOCKS_PER_SEC); 
    }
    
}


void selectionSequences(vector <Sequences> &m){
    
    clock_t clicks;
    clicks = clock();

    m.push_back(Sequences());
    m[0].SelectOrdRecord=0;

     double startScan, mindVal[COL], minIndex, minValue;
    for(int startScan=0; startScan < m[0].numberOfSequences-1; startScan++){
        minIndex = startScan;
        minValue = m[startScan].mean;

        for(int i=0; i<10; i++){
            mindVal[i] = m[startScan].normalizedSequences[i];
        }

        for(int index= startScan + 1; index < m[0].numberOfSequences; index++){
            if(m[index].mean < minValue){
                minValue = m[index].mean;
                minIndex = index;

                for(int i=0; i<10; i++){
                    mindVal[i] = m[index].normalizedSequences[i];
                }
            }
        }

        m[minIndex].mean = m[startScan].mean;
        m[startScan].mean = minValue;

        for(int i=0; i<10; i++){
            m[minIndex].normalizedSequences[i] = m[startScan].normalizedSequences[i];
            m[startScan].normalizedSequences[i] = mindVal[i];
        }

    }   
        m[0].SelectOrdRecord = static_cast<double>(clicks)/
        static_cast<double>(CLOCKS_PER_SEC); 

}


void bubbleSequences(vector <Sequences> &m){

    clock_t clicks;
    clicks = clock();

    m.push_back(Sequences());
    m[0].BubbleOrdRecord=0;

    for(int z=0; z<10; z++){

              double temp;
                bool swapped;
            do{
                swapped = false;
                for(int i=0; i< m[0].numberOfSequences -1; i++){
                    if(m[i].mean > m[i+1].mean){
                        temp = m[i].mean;
                        m[i].mean = m[i+1].mean;
                        m[i+1].mean = temp;
                        swapped = true;

                        for(int k=0; k<10; k++){
                            temp = m[i].normalizedSequences[k];
                            m[i].normalizedSequences[k] = m[i+1].normalizedSequences[k];
                            m[i+1].normalizedSequences[k] = temp;
                        }
                    }
                }
            }while(swapped);

        m[0].BubbleOrdRecord = static_cast<double>(clicks)/
        static_cast<double>(CLOCKS_PER_SEC);
    }
          
}


void runTime(vector <Sequences> &m){
    cout.precision(7);
    cout <<"+---------------+----------------------------------------+----------------------------------------------+\n";
    cout <<"|ALGORTIMO      |       Tiempo en ordenar cada           |      Tiempo promedio en ordenar cada         |\n";
    cout <<"|               |       record usando la media           |                secuencia                     |\n";
    cout <<"+---------------+----------------------------------------+----------------------------------------------+\n";
    cout <<"|BUBBLE         |"<<m[0].BubbleOrdRecord<< " secs on avg per "<< m[0].numberOfSequences<<" sequences"
    <<setw(14)<<m[0].BubbleOrdSecuencias<<setw(2)<< " secs on avg per "<< m[0].numberOfSequences<<" sequences\n";
    cout <<"+---------------+----------------------------------------+----------------------------------------------+\n";
    cout <<"|SELECTION      |"<<m[0].SelectOrdRecord<< " secs on avg per "<< m[0].numberOfSequences<<" sequences  "
    <<setw(12)<<m[0].SelectOrdSecuencias<< " secs on avg per "<< m[0].numberOfSequences<<" sequences\n";
    cout <<"+---------------+----------------------------------------+----------------------------------------------+\n";

}


void inputSave(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
    cout << "Enter the name of the file with extention where things are going to be saved: ";
    cin >> saveData;
    saveDataFile.open(saveData);

}


void saveNormalized(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){

    inputSave(m,saveDataFile, saveData);
    saveDataFile <<setw(102) <<"|         Normalized Sequences        |\n";

       saveDataFile.precision(7);
    saveDataFile << "data ID ";
    for (int i = 1; i <= 10; i++) {
        saveDataFile << setw(12) << "Value_" << i;
    }saveDataFile << setw(12) <<"Mean" << setw(13) <<"StdDev" << endl;

    saveDataFile << string(166, '-') << endl;

       for(int i=0; i <m[0].numberOfSequences; i++){
        
        if(i<9) saveDataFile << "data ID#" << "0"<<(i+1);
        else saveDataFile << "data ID#" << (i+1);

        for(int j=0; j <COL; j++){

            saveDataFile << setw(13) << m[i].normalizedSequences[j];
        }saveDataFile << setw(13) << m[i].mean << setw(13) << m[i].standardDeviation;
        saveDataFile << endl;
    }
    double row = (m[0].coordinates[1]+1), column = (m[0].coordinates[2]+1);
    saveDataFile << "\nMinimum value of all sequences is: " << m[0].smallestNumber
                 <<" found on column "<< column          
                 << " of sequence number " << row << endl;

}


void sortingSaveFormat(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
        saveDataFile.precision(7);
    saveDataFile << "data ID ";
    for (int i = 1; i <= 10; i++) {
        saveDataFile << setw(12) << "Value_" << i;
    }saveDataFile << setw(12) <<"Mean" << endl;

    saveDataFile << string(153, '-') << endl;

       for(int i=0; i <m[0].numberOfSequences; i++){
        
        if(i<9) saveDataFile << "data ID#" << "0"<<(i+1);
        else saveDataFile << "data ID#" << (i+1);

        for(int j=0; j <COL; j++){

            saveDataFile << setw(13) << m[i].normalizedSequences[j];
        }saveDataFile << setw(13) << m[i].mean;
        saveDataFile << endl;
    }
}


void saveBubbleValues(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
    
    bubbleValues(m);
    saveDataFile <<"\n\n+------------------------+\n";
    saveDataFile <<"|Bubble Sequences        |\n";
    sortingSaveFormat(m, saveDataFile, saveData);

}


void saveSelectionvalues(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
        
    selectionValues(m);
    saveDataFile <<"\n\n+------------------------+\n";
    saveDataFile <<"|Selection Sequences     |\n";
    sortingSaveFormat(m, saveDataFile, saveData);

}


void saveSelectionSequences(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
   
    selectionSequences(m);
    saveDataFile <<"\n\n+--------------------------+\n";
    saveDataFile <<"|Selection Record per mean |\n";
    sortingSaveFormat(m, saveDataFile, saveData);

}


void saveBubbleSequences(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
    
    bubbleSequences(m);
    saveDataFile <<"\n\n+-----------------------+\n";
    saveDataFile <<"|Bubble Record per mean |\n";
    sortingSaveFormat(m, saveDataFile, saveData);
    saveDataFile.close();
    
}

void processData(vector <Sequences> &m){
    normalizeSequences(m);
    getMean(m);
    getStandardDeviation(m);
    getSmallestNumber(m);

}

void onFile(vector <Sequences> &m, ofstream &saveDataFile, string &saveData){
    saveNormalized(m, saveDataFile, saveData);
    saveBubbleValues(m, saveDataFile, saveData);
    saveSelectionvalues(m, saveDataFile, saveData);
    saveSelectionSequences(m, saveDataFile, saveData);
    saveBubbleSequences(m, saveDataFile, saveData);
   
}
