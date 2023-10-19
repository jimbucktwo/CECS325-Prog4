//Jimmy Tran
// Class (CECS 325-02)
// Prog 4 Sortrace
// 10/24/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]) {
    //makes sure user enters the correct amount of arguments
    if (argc < 4)
    {
        cout << "Please enter 3 parameters:\n";
        cout << "       Parameter 1: total count of numbers you want.\n";
        cout << "       Parameter 2: min value.\n";
        cout << "       Parameter 3: max value.\n";
        cout << "Example : %generate 1000000 100000 999999\n";
        exit(EXIT_SUCCESS);

    }

    // prints the arguments used
    for (int i=0; i<argc; i++){
        cout << "argv["<<i<<"]: "<<argv[i] << endl;
    }

    int count = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    // writes the random numbers generate to new file called numbers.dat
    ofstream fout;
    fout.open("numbers.dat", ios::out);
    for (int i = 0; i < count; i++) {
        fout << (rand() % (max - min + 1) + min) << endl;
    }
    fout.close();
    return 0;
}
