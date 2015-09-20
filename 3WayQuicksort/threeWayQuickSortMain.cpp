/*
3 way Quick Sort Implementation 
Written by Suvigya Tripathi, 3/8/2015

A unsorted data set with 8192 entries with duplicate entries is also submitted with the project
********************************************************************************************
To compile, please include following files in the project:
1) ThreeWayQsort.h
2) threeWayQuickSortMain.cpp

*******************************************************************************************
To execute the code, enter file path as command line argument:
shellSort.exe <input_file_path>

eg:

3WayQuicksort.exe C:\Acads\Sem_2\DSA\3wayqsort.txt
*/
#include"ThreeWayQsort.h"
#include<fstream>
#include<iostream>
#include<chrono>

int main(int argc,char** argv){
	ifstream ffile, sfile; //creating file pointer
	string firstFile = argv[1]; //read the location/path of the input file from command line
	string secondFile = argv[1];
	ffile.open(firstFile, ios::in);
	sfile.open(secondFile, ios::in);

	int str, size = 0;

	//gives error message if file is not opened
	if (!ffile.is_open() && !sfile.is_open()){
		cout << "file not opened\n";
	}

	else{
		cout << "File Opened\n";
		//mergeSort m;
		while (ffile >> str)
		{
			size++;
		}

		cout << "Total Number of inputs: " << size << '\n';
		int *inputArray = new int[size]; //creates array of the dynamic size

		int cnt = 0;
		ffile.close();

		//reopens the file to store the data into the array
		ffile.open(firstFile, ios::in);
		while (ffile >> str)
		{
			inputArray[cnt++] = str;
			//cout << str << "\n";
		}
		ffile.close();

		//int a[6] = { 5, 3, 7, 1, 2, 3 };
		threeWayQuickSort t;
		chrono::steady_clock::time_point start = chrono::steady_clock::now(); //takes the current time
		t.quickSort(inputArray, 0, size - 1);
		chrono::steady_clock::time_point end = chrono::steady_clock::now(); //takes the reading after executing the implementation
		typedef chrono::duration<int, milli> millisecs_t;
		millisecs_t duration(chrono::duration_cast<millisecs_t>(end - start)); //calculates time difference between start and end
		cout << "Sophisticated Implementation of Threesum: " << duration.count() << " milliseconds.\n";

		
		/*for (int i = 0; i < size; i++){
			std::cout << inputArray[i] << '\t';
		}*/

	}
	return 0;
} 