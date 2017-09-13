#include <iostream>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
using namespace std;


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

double y_dash(double y){
    double val = 10*(1-y);
    return val;
}

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

double** euler_integration(double (*f)(double), double t0, double tf, double y0, int n){
    double** ty = 0;
    ty = new double*[n];
    double h = (tf-t0)/n;
    double y = y0;
    double fdash;
    for(int i = 0; i<n; ++i){
        ty[i] = new double[2];
        if(i==0){
            ty[i][0] = t0;
            ty[i][1] = y0;
        }else{
            ty[i][0] =  t0 + i*h;
            fdash = f(y);
            y = y + h*fdash;
            ty[i][1] = y;
        }
    }

    return ty;
}

int main(){
    int n = 50;
    double t0 = 0;
    double y0 = 0;
    double tf = 1.5;
    double** sol = euler_integration(y_dash, t0, tf, y0, n);
    //double** arr = makearray(n,2);
    printarray(sol, n);
    maketxt(sol, n);


    
    for (int i = 0; i < n; i++){
        delete[] sol[i];
    }

    delete[] sol; 


    return 0;
}


