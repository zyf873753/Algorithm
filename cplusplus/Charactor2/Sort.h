/*Author: Yifan Zhang
 *Descript: This class is just a collection of sort algorithm which not include data, such as array. So every function in this class has a parameter whitch is a pointer to array. 
 */

class Sort
{
private:
	bool less(int a, int b);
	void exchange(int *array, int a, int b);
	void merge(int *array, int lo, int mid, int hi);
	void mergeSort(int *array, int lo, int hi);
	int quick(int *array, int lo, int hi);
	void quickSort(int *array, int lo, int hi);
	void quick3waySort(int *array, int lo, int hi);
	void sink(int *array, int k, int N);

public:
	bool isSorted(int *array, int N);
	void selectionSort(int *array, int N);
	void insertSort(int *array, int N);
	void shellSort(int *array, int N);
	void mergeSort(int *array, int N);
	void quickSort(int *array, int N);
	void quick3waySort(int *array, int N);
	void heapSort(int *array, int N);
};

