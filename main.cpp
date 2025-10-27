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
    vector<string> filedata;
    long long data[4][3][2];
    string temp;
    int timevector=0;
    int timeset=0;
    int timelist=0;
    int counter;
    while(file>>temp){
        filedata.push_back(temp);
    }
    file.close();
    for(int x=0;x<3;x++){ 
        cout<<counter<<endl;
        vector<string> racer1;
        list<string> racer2;
        set<string>racer3;
        //Reading race
        //Vector
        auto start=high_resolution_clock::now();
       for(const auto&code:filedata){
        racer1.push_back(code);
       }
        auto end=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        timevector=duration.count();
        data[0][0][0]=timevector;
        data[0][0][1]+= data[0][0][0];
        //List
        start=high_resolution_clock::now();
        for(const auto&code:filedata){
         racer2.push_back(code);
       }
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        timelist=duration.count();
        data[0][1][0]=timelist;
        data[0][1][1]+=data[0][1][0];
        //Set
        start=high_resolution_clock::now();
          for(const auto&code:filedata){
            racer3.insert(code);
       }
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        timeset=duration.count();
        data[0][2][0]+=timeset;
        data[0][2][1]+=data[0][2][0];
        counter++;
    }

   

        //Outputting the resulst of the races
        string races[4]={"Read","Sort","Insert","Delete"};
        cout<<"Number of simulations: "<<counter<<endl;
        // Since I setup my 3d array the rows will always be 0 so i didnt put it in the output
        cout<<"Operation     Vector       List      Set"<<endl;
        for(int x=0;x<3;x++){
            cout<<data[0][x][1]/counter<<" ";
        }
      
    
     
    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/