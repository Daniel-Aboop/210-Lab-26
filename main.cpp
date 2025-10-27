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
    vector<string> filedata;
    string temp;
     while(file>>temp){
        filedata.push_back(temp);
    }
    file.close();
    long long data[4][3][2];
    int timevector=0;
    int timeset=0;
    int timelist=0;
    int counter=0;
    for(int simulation=0;simulation<3;simulation++){
        cout<<counter<<endl;
    // Reading race
        vector<string> racer1;
        list<string> racer2;
        set<string> racer3;
    //Vector
        auto start=high_resolution_clock::now();
        for(const auto &code:filedata){
            racer1.push_back(code);
        }
        auto end=high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        data[0][0][0]=duration.count();
        data[0][0][1]+= data[0][0][0];
    //List
        start=high_resolution_clock::now();
        for(const auto &code:filedata){
            racer2.push_back(code);
        }
        end=high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        data[0][1][0]=duration.count();
        data[0][1][1]+=data[0][1][0];
    //Set
        start=high_resolution_clock::now();
        for(const auto &code:filedata){
            racer3.insert(code);
        }
        end=high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        data[0][2][0]=duration.count();
        data[0][2][1]= data[0][2][0];
        counter++;

    //Sorting Race
    //Vector
      start=high_resolution_clock::now();
      sort(racer1.begin(),racer1.end());
      end=high_resolution_clock::now();
      duration=duration_cast<microseconds>(end-start);
      data[1][0][0]=duration.count();
      data[1][0][1]= data[1][0][0];
    //List
      start=high_resolution_clock::now();
      racer2.sort();
      end=high_resolution_clock::now();
      duration=duration_cast<microseconds>(end-start);
      timelist=duration.count();
      data[1][1][0]=duration.count();
      data[1][2][1]+=data[1][1][0];
    //Set
      data[1][2][0]=-1;
      data[1][2][1]+=data[1][2][0];

    //Inserting Race
    //Vector
     int place=racer1.size()/2;
     start=high_resolution_clock::now();
     racer1.insert(racer1.begin()+place,"TESTCODE");
     end=high_resolution_clock::now();
     duration=duration_cast<microseconds>(end-start);
     data[2][0][0]=duration.count();
     data[2][0][1]+=data[2][0][0];
    //Set
        

    }
    //Outputting the resulst of the races

    
    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/