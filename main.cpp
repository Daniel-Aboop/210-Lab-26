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

int main() {
    ifstream file("file path here");
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
    // My numbers didnt match up to yours but I assumed it was a hardware difference.
    // the reason for using long long int was that if you wanted to run more simulations it would become a REALLy big number
    long long int data[4][3][2]={0};
    int timevector=0;
    int timeset=0;
    int timelist=0;
    int counter=0;
    // I mostly copied and pasted code from Lab 25 but I switched the racer 2 and 3 since I got them mixed up 
    // I also put it in the for loop so it can reset iteration easily and also
    //changed reading a file every time to just reading from a vector with the file data
    // I also changed it for better readability
    for(int simulation=0;simulation<15;simulation++){
        cout<<counter<<endl;
    // Reading race-------------------------------------------------
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
    //Sorting Race--------------------------------------------
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

    //Inserting Race-------------------------
    //Vector
        int place=racer1.size()/2;
        start=high_resolution_clock::now();
        racer1.insert(racer1.begin()+place,"TESTCODE");
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[2][0][0]=duration.count();
        data[2][0][1]+=data[2][0][0];
    //List
        start=high_resolution_clock::now();
        auto iter=racer2.begin();
        advance(iter,racer2.size()/2);
        racer2.insert(iter,"TESTCODE");
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[2][1][0]=duration.count();
        data[2][1][1]+=data[2][1][0];
    //Set
        start=high_resolution_clock::now();
        racer3.insert("TESTCODE");
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[2][2][0]=duration.count();
        data[2][1][1]+=data[2][2][0];
    //Deleting Race-------------------------------------
    //Vector
        start=high_resolution_clock::now();
        int middle=racer1.size()/2;
        racer1.erase(racer1.begin()+middle);
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[3][0][0]=duration.count();
        data[3][0][1]+=data[3][0][0];
    //List
        start=high_resolution_clock::now();
        auto its=racer2.begin();
        advance(its,racer2.size()/2);
        racer2.erase(its);
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[3][1][0]=duration.count();
        data[3][1][1]+=data[3][1][0];
    //Set
        start=high_resolution_clock::now();
        auto it=racer3.begin();
        advance(it,racer3.size()/2);
        racer3.erase(it);
        end=high_resolution_clock::now();
        duration=duration_cast<microseconds>(end-start);
        data[3][2][0]=duration.count();
        data[3][2][1]+=data[3][2][0];


        counter++;
    }
    //Outputting the resulst of the races
    string races[4]={"Read","Sort","Insert","Delete"};
    cout<<"Number of simulations: "<<counter<<endl;
    cout<<left<<setw(12)<<"Operation"<<right<<setw(10)<<"Vector"
    <<right<<setw(10)<<"List"<<right<<setw(10)<<"Set"<<endl;
    //Here I print out the 3D array i view it in a x y z format 
    // X being the slices Y being the rows and Z being the columns
    // its like printing a 2D array but simple since we're always ont he second column
    for(int x=0;x<4;x++){
        cout<<left<<setw(12)<<races[x];
        for(int y=0;y<3;y++){
            cout<<right<<setw(10)<<data[x][y][1]/counter;
        }
        cout<<endl;
    }
    
    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/