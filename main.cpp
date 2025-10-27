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
    int counter;
    for(int x=0;x<15;x++){ 
        // Reading race
        //Vector
        auto start=high_resolution_clock::now();
        while(file>>temp){
            racer1.push_back(temp);
        }
        auto end=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        timevector=duration.count();
        data[0][0][0]+=timevector;
        file.clear();
        file.seekg(0);
        //List
        start=high_resolution_clock::now();
        while(file>>temp){
            racer2.push_back(temp);
        }
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        timelist=duration.count();
        data[0][0][1]+=timelist;
        file.clear();
        file.seekg(0);
        //Set
        start=high_resolution_clock::now();
        while(file>>temp){
            racer3.insert(temp);
        }
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        timeset=duration.count();
        data[0][0][2]+=timeset;
         
   
        counter++;
    }

   

        //Outputting the resulst of the races
        string races[4]={"Read","Sort","Insert","Delete"};
        cout<<"Number of simulations: "<<counter<<endl;
        // Since I setup my 3d array the rows will always be 0 so i didnt put it in the output
        cout<<"Operation     Vector       List      Set"<<endl;
        for(int x=0;x<4;x++){
            cout<<left<<setw(10)<<races[x];
            for(int z=0;z<3;z++){
                cout<<right<<setw(10)<<data[x][0][z]/counter;
            }
            cout<<endl;
        }
      
    
     
    file.close();
    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/