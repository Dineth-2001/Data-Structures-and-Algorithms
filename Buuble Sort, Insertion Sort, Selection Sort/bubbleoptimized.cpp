#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void bubbleOptimized(vector<int> &arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
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

    bubbleOptimized(listNum);

    //printing the array
    for (int k : listNum) {
        cout << k << " ";
    }
    
    return 0;
}
