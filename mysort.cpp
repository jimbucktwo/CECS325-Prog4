//Jimmy Tran
// Class (CECS 325-02)
// Prog 4 Sortrace
// 10/24/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <pthread.h>
using namespace std;


void bubblesort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        bool swapped = false;

        for (int j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main(int argc, char *argv[]) { 
    
    //prints arguments used for mysort
    for (int i=0; i<argc; i++){
        cout << "argv["<<i<<"]: "<<argv[i] << endl;
    }

    //creates new file fin to be read
    ifstream fin;
    fin.open(argv[1], ios::in);
    
    // dynamically allocates memory for the array
    int* numArray = nullptr;
    int capacity = 10;
    int size = 0;
    int num;

    numArray = new int[capacity];

    // creates the array using the file numbers.dat
    while (fin >> num) {
        if (size == capacity) {
            capacity *= 2;
            int* tempArray = new int[capacity];

            for (int i = 0; i < size; ++ i) {
                tempArray[i] = numArray[i];
            }

            delete[] numArray;
            numArray = tempArray;
        }
        numArray[size] = num;
        ++size;
    }

    fin.close();

    //bubblesort algorithm
    bubblesort(numArray, size);

    //creates file mysort.out to write the results into
    ofstream fout;
    fout.open(argv[2], ios::out);
    for (int i = 0; i < size; ++i) {
        fout << numArray[i] << endl;
    }

    fout.close();
    delete[] numArray;
    

}