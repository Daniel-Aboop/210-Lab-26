// COMSC-210 | Lab 26 | Daniel Santisteban
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
 

    //Outputting the resulst of the races

    file.close();
    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/