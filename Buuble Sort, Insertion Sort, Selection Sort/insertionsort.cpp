#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


void insertionSort(vector<int> &arr){
    //Method to sort a list using insertion sort
    
    for(size_t i=1;i<arr.size();i++){
        int val = arr[i]; //storing i in a variable
        int j = (int) i-1;

        //Iterating through the list 
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j]; //shifting
            j--;
        }
        arr[j+1]=val; //Assigning val to its' correct position
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

    insertionSort(listNum);
    
    //printing the array
    for(int k:listNum){
        cout<<k<<" ";
    }

    return 0;
}