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
    list<string> racer2;
    set<string>racer3;
    //changed it to 3D array, layers rows columns, 4 slices for the races, 1 row of data for 
    int data[4][1][3];
   
    string temp;
    int timevector=0;
    int timeset=0;
    int timelist=0;

        
    for(int x=0;x<15;x++){
        // Reading race
        auto start=high_resolution_clock::now();
        while(file>>temp){
            racer1.push_back(temp);
        }
        auto end=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        timevector=duration.count();
        data[0][0][0]=timevector;
        file.clear();
        file.seekg(0);
        start=high_resolution_clock::now();
    
        
    }
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