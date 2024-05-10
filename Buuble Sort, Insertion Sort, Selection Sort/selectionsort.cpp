#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void selectionSort(vector<int> &arr) {
    for (size_t i = arr.size() - 1; i > 0; i--) {
        int minPos = i;
        for (size_t j = 0; j < i; j++) {
            if (arr[minPos] < arr[j]) {
                minPos = j;
            }
        }
        if (minPos != (int)i) {
            int temp = arr[minPos];
            arr[minPos] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
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

    selectionSort(listNum);
    for (int k : listNum) {
        cout << k << " ";
    }
    
    return 0;
}
 
