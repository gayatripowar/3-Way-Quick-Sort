#include<iostream>
#include<algorithm>

using namespace std;

class threeWayQuickSort{
public:
	void quickSort(int inArray[], int begin, int end){
		if (end <= begin)
			return;
		int lt = begin;
		int gt = end;
		int v = inArray[begin];
		int i = begin;

		while (i <= gt){
			if (inArray[i] < v){
				//lt++;
				//i++;
				swap(inArray[lt++], inArray[i++]);
			}
			else if (inArray[i] > v){
				//gt--;
				swap(inArray[i], inArray[gt--]);
			}

			else
				i++;
		}

		quickSort(inArray, begin, lt - 1);
		quickSort(inArray, gt + 1, end);
		/*int k = 0;
		int temp = inArray[end];

		if (end <= begin)
			return;

		int i = begin - 1;
		int j = end;
		int p = begin - 1;
		int q = end;

		for (;;){
			while (inArray[++i] < temp){
				while (temp < inArray[--j]){
					if (j == 1)
						break;
					if (i >= j)
						break;
					swap(inArray[i], inArray[j]);
					if (inArray[i] == temp){
						p++;
						swap(inArray[p], inArray[i]);
					}
					if (inArray[j] == temp){
						q--;
						swap(inArray[q], inArray[j]);
					}
				}
			}

			for (k = begin; k <= p; k++, j--){
				swap(inArray[k], inArray[j]);
			}

			for (k = end - 1; k >= q; k--, i++){
				swap(inArray[k], inArray[i]);
			}

			quickSort(inArray, begin, j);
			quickSort(inArray, i, end);
		}*/
	}
};