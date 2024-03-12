#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <chrono>
#include <algorithm>  
#include <random>

using namespace std;
using namespace std::chrono;

vector<int> merge(vector<int> arr, int first1, int last1, int first2, int last2){
    vector<int> temp;
    int index = 0;
    
    // merging the two sub arrays in sorted order
    while(first1<=last1 && first2 <= last2){
        if(arr[first1] < arr[first2]){
            temp.push_back(arr[first1]);
            index ++;
            first1++;
        }
        else{
            temp.push_back(arr[first2]);
            index ++;
            first2++;
        }
    }
    
    // copying remaining elements from the sub arrays
    while (first1<=last1){
        temp.push_back(arr[first1]);
        index ++;
        first1++;
    }
    while (first2<=last2){
        temp.push_back(arr[first2]);
        index ++;
        first2++;
    }
    return temp;
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
    
    int len = 1;
    int n = listNum.size();
    
    // iterative merge sort
    while (len<n){
        int i = 0;
        while (i<n){
            int L1 = i;
            int R1 = i + len -1;
            int L2 = i + len;
            int R2 = i+2*len-1;
            if (L2>=n){
                break;
            }
            if (R2>=n){
                R2 = n-1;
            }
            
            // merging two sub arrays
            vector <int> temp = merge(listNum, L1, R1, L2, R2);
            for (int j = 0;j<=R2-L1;j++){
                listNum[i+j]=temp[j];
            }
            i = i+2*len;
        }
        len = len*2;
    }

    for(int k: listNum){
        cout<<k<<" ";
    }
}