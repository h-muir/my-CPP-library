#include <iostream>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
using namespace std;

/*
 * NOTES:
 * useful file for dealing with 2d arrays and data sets
 * accompanying file: plot2D.py
 * after compiling, for data visualisation run in terminal:
 * >>> python plot2D.py
 * (cntrl+z to exit python)
 */


void maketxt(double** arr, int n){
    ofstream file;
    file.open("datafile.txt");
    for(int i=0; i<n; ++i){
        for (int j=0; j<2; ++j){
            file << arr[i][j] << ' ';
        }
        file << '\n';
    }
    file.close();
}

double** makearray(int r, int c){
    double** arr = new double*[r];
    for(int i = 0; i < r; ++i){
        arr[i] = new double[c];
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    return arr;
}

void printarray(double** arr, int n){
    for(int i=0; i<n; ++i){
        for (int j=0; j<2; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    int n = 5;
    double** arr = makearray(n,2);
    printarray(arr, n);
    
    for (int i = 0; i < n; i++){
        delete[] arr[i];
    }

    delete[] arr; 


    return 0;
}

