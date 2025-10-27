// COMSC-210 | Lab 25 | Daniel Santisteban
// IDE used: VS Code

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;
void printvector(vector<int>& pass,string name);

int main() {
    ifstream file("C:\\Users\\hope4\\Desktop\\COMSC 210 Work\\210-Lab-26\\codes.txt");
    if(!file.is_open()){
        cout<<"failed to open file"<<endl;
        return 1;
    }
    else{
        cout<<"opened file"<<endl;
    }
    vector<string> racer1;
    set<string> racer2;
    list<string> racer3;
    //using these to hold my results from the races from vector->set->list and hold certain points of data
    vector<int> reading;
    vector<int> sorting;
    vector<int> inserting;
    vector<int> deleting;
    string temp;
    int timevector=0;
    int timeset=0;
    int timelist=0;
    // Reading race
    auto start=high_resolution_clock::now();
    while(file>>temp){
        racer1.push_back(temp);
    }
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(end-start);
    timevector=duration.count();
    reading.push_back(timevector);
    file.clear();
    file.seekg(0);

    start=high_resolution_clock::now();
    while(file>>temp){
        racer2.insert(temp);
    }
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timeset=duration.count();
    reading.push_back(timeset);
    file.clear();
    file.seekg(0);

    start=high_resolution_clock::now();
    while(file>>temp){
        racer3.push_back(temp);
    }
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timelist=duration.count();
    reading.push_back(timelist);

    //Sorting Race
    start=high_resolution_clock::now();
    sort(racer1.begin(),racer1.end());
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timevector=duration.count();
    sorting.push_back(timevector);

    //set already sorts
    sorting.push_back(-1);
    start=high_resolution_clock::now();
    racer3.sort();
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timelist=duration.count();
    sorting.push_back(timelist);

    //Inserting Race
    int place=racer1.size()/2;
    start=high_resolution_clock::now();
    racer1.insert(racer1.begin()+place,"TESTCODE");
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timevector=duration.count();
    inserting.push_back(timevector);

    start=high_resolution_clock::now();
    racer2.insert("TESTCODE");
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timeset=duration.count();
    inserting.push_back(timeset);
    
    start=high_resolution_clock::now();
    auto iter=racer3.begin();
    advance(iter,racer3.size()/2);
    racer3.insert(iter,"TESTCODE");
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timelist=duration.count();
    inserting.push_back(timelist);

    //Deleting Race
    start=high_resolution_clock::now();
    int middle=racer1.size()/2;
    racer1.erase(racer1.begin()+middle);
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timevector=duration.count();
    deleting.push_back(timevector);

    start=high_resolution_clock::now();
    auto it=racer2.begin();
    advance(it,racer2.size()/2);
    racer2.erase(it);
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timeset=duration.count();
    deleting.push_back(timeset);

    start=high_resolution_clock::now();
    auto its=racer3.begin();
    advance(its,racer3.size()/2);
    racer3.erase(its);
    end=high_resolution_clock::now();
    duration=duration_cast<microseconds>(end-start);
    timelist=duration.count();
    deleting.push_back(timelist);

    //Outputting the resulst of the races
    cout<<left<<setw(12)<<"Operation"<<right<<setw(10)<<"Vector"
    <<right<<setw(10)<<"Set"<<right<<setw(10)<<"List"<<endl;
    printvector(reading,"Read");
    printvector(sorting,"Sort");
    printvector(inserting,"Insert");
    printvector(deleting,"Delete");

    file.close();
    return 0;
}

void printvector(vector<int>& pass,string name){
    cout<<left<<setw(12)<<name<<" ";
    for(int temp: pass){
        cout<<right<<setw(10)<<temp;
    }
    cout<<endl;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/