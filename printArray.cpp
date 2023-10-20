/* to compile this program:

$ c++ printArray.cpp -o printArray -pthread

*/


//#include <stdio.h>
//#include <stdlib.h>
#include <pthread.h>
//#include <thread>
#include <iostream>
#include <unistd.h>  // needed for the sleep function
using namespace std;

// Create a structure to pass parameters to printHelper in pthread_create
struct printStruct{
	int *pstart; // pointer to the starting array element
	int size;	// how many numbers to print from array
	int wait;	// how many seconds to wait
};

// the print function. prints an array of ints
void print(int *p, int size)
{
	for (int i=0; i<size; i++)
		cout << *(p+i)<<",";
}
// This is the function that will be called in pthread_create.
// Notice this returns a void pointer
void *printHelper(void *ptr )
{
	printStruct *arg = (printStruct *) ptr;
	
	cout << "Print start:"<<*(arg->pstart)<<" count:"<<arg->size<<" wait:"<<arg->wait<<endl;
	sleep(arg->wait);
	print(arg->pstart, arg->size);
	cout << endl;
	
	return NULL;
}




int main()
{

	int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	cout << "Print entire array:";
	print(a,20);
	cout << endl;

	printStruct s1;
	s1.pstart = a;
	s1.size = 5;
	s1.wait = 3;

	printStruct s2;
	s2.pstart = &(a[5]);
	s2.size = 5;
	s2.wait = 2;	

	printStruct s3;
	s3.pstart = a+10;
	s3.size = 5;
	s3.wait = 1;

	printStruct s4; 
	s4.pstart = a+15;
	s4.size = 5;
	s4.wait = 0;
	
	pthread_t thread0, thread1, thread2, thread3;
	int iret0, iret1, iret2, iret3;
	/* Create independent threads each of which will execute function */
	iret0 = pthread_create( &thread0, NULL, printHelper, (void*) &s1);
	iret1 = pthread_create( &thread1, NULL, printHelper, (void*) &s2);
	iret2 = pthread_create( &thread2, NULL, printHelper, (void*) &s3);
	iret3 = pthread_create( &thread3, NULL, printHelper, (void*) &s4);
// The return value of pthread_create is 0 if successful and non-zero if there is a problem

	cout << "Thread 0 returns:"<<iret0<<endl;
	cout << "Thread 1 returns:"<<iret1<<endl;
	cout << "Thread 2 returns:"<<iret2<<endl;
	cout << "Thread 3 returns:"<<iret3<<endl;

/* Wait till threads are complete before main continues. Unless we */
/* wait we run the risk of executing an exit which will terminate */
/* the process and all threads before the threads have completed. */
	pthread_join( thread0, NULL);
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	pthread_join( thread3, NULL);

	return 0;
}
