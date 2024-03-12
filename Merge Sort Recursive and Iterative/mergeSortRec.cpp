#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <chrono>
#include <algorithm>  
#include <random>

using namespace std;
using namespace std::chrono;

void merge(vector<int> &A, int first, int mid, int last){
    int n1 = mid-first+1;
    int n2 = last-mid;

    vector<int> L(n1+1),R(n2+1); // creating temporory vectors L and R
    
    // copying data to L and R
    for(int i=0;i<n1;i++){
        L[i] = A[first+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid+1+i];
    }

    L[n1]=INT_MAX;
    R[n2]=INT_MAX;

    int i=0;
    int j=0;

    // merging the two halves back into A
    for(int k=first;k<=last;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int first, int last){
    int mid;
    if(first<last){
        int mid = (first+last)/2;
        mergeSort(A,first,mid);
        mergeSort(A,mid+1,last);
        merge(A,first,mid,last);
    }
}

int main(){
    string list;
    getline(cin, list); //Obtaining the user inputs
    stringstream ss; //Creating an object of class stringstream
    ss<<list; //inserting list to the stream

    vector<int> listNum;
    
    while (not ss.eof()){ //Checking if the input stream has ended
        int n;
        ss>>n; //Streaming each integer into n  
        listNum.push_back(n); //Appending n to the vector
    }
    mergeSort(listNum, 0, listNum.size()-1);

    for(int k: listNum){
        cout<<k<<" ";
    }
}