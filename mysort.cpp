#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

const int numThreads = 10;
const int arr_size = 1000000;

int numArray[arr_size];

void merge(int a1[], int size1, int a2[], int size2){
    int tempArray[size1 + size2];
    int i = 0;
    int left = 0;
    int right = 0;

    while ((left < size1) && (right < size2)) {
        if (a1[left] <= a2[right]) {
            tempArray[i] = a1[left];
            ++left;
        } else {
            tempArray[i] = a2[right];
            ++right;
        }
    }

}

void* bubblesort(void* ptr) {
    int thread_id = *(int*) ptr;
    int chunk_size = 100000;
    int start = thread_id * chunk_size;
    int end = (thread_id = 9) ? 1000000 : start + chunk_size;

    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (numArray[j] > numArray[j + 1]) { 
                swap(numArray[j], numArray[j + 1]);
            }
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[] ) {
    ifstream fin;
    fin.open(argv[1], ios::in);
    int num;
    int i = 0;

    while (fin >> num) {
        numArray[i] = num;
        ++i;
    }

    fin.close();

    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
    int ret0, ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8, ret9;
    int threadIds[numThreads];

    ret0 = pthread_create(&thread0, NULL, bubblesort, &threadIds[0]);
    ret1 = pthread_create(&thread1, NULL, bubblesort, &threadIds[1]);
    ret2 = pthread_create(&thread2, NULL, bubblesort, &threadIds[2]);
    ret3 = pthread_create(&thread3, NULL, bubblesort, &threadIds[3]);
    ret4 = pthread_create(&thread4, NULL, bubblesort, &threadIds[4]);
    ret5 = pthread_create(&thread5, NULL, bubblesort, &threadIds[5]);
    ret6 = pthread_create(&thread6, NULL, bubblesort, &threadIds[6]);
    ret7 = pthread_create(&thread7, NULL, bubblesort, &threadIds[7]);
    ret8 = pthread_create(&thread8, NULL, bubblesort, &threadIds[8]);
    ret9 = pthread_create(&thread9, NULL, bubblesort, &threadIds[9]);

    cout << "Thread 0 returns: " << ret0;
    cout << "Thread 1 returns: " << ret1;
    cout << "Thread 2 returns: " << ret2;
    cout << "Thread 3 returns: " << ret3;
    cout << "Thread 4 returns: " << ret4;
    cout << "Thread 5 returns: " << ret5;
    cout << "Thread 6 returns: " << ret6;
    cout << "Thread 7 returns: " << ret7;
    cout << "Thread 8 returns: " << ret8;
    cout << "Thread 9 returns: " << ret9;

    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);

    ofstream fout;
    fout.open(argv[2], ios::out);
    for (int i = 0; i < arr_size; ++i) {
        fout << numArray[i] << endl;
    }

    fout.close();
    delete[] numArray;
}