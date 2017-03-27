/*sort algr*/

//insertion sort
#if 0
#include <stdio.h>

/*
 在插入位置P的元素之前，保证前P-1个元素已排序
 内部循环保证插入位置的准确性
 插入排序的最优时间：Θ(n^2)
*/
void insertion_sort(int origin_arr[], int length)
{
	int cursor = 0;
	int index = 0;
	int tmp = 0;

	for (cursor = 1; cursor < length; cursor++)
	{
		tmp = origin_arr[cursor];

		for (index = cursor - 1; index >= 0; index--)
		{
			if (tmp < origin_arr[index])
			{
				origin_arr[index + 1] = origin_arr[index];
			}
			else
			{
				break;
			}
		}

		origin_arr[index + 1] = tmp;
	}

	return;
}
#endif 

#if 0
//hill sort
#include <stdio.h>

/*
 希尔排序是插入排序的一种通用解。要求按照增量increment来进行排序。每次排序好相隔increment的
 子序列，通过不断缩小increment，排序完整的数组
 选择合适的增量的希尔排序的最优时间Θ(n^7\6)
*/
void hill_sort(int origin_arr[], int length)
{
	int cursor = 0;
	int index = 0;
	int increment = length/2;
	int tmp = 0;

	for (increment = length/2; increment > 0; increment /= 2)
	{
		for (cursor = increment; cursor <= length; cursor++)
		{
			tmp = origin_arr[cursor];

			for (index = cursor; index >= increment; index -= increment)
			{
				if (tmp > origin_arr[index])
				{
					origin_arr[index] = origin_arr[index - 1];
				}
				else 
				{
					break;
				}
			}

			origin_arr[index] = tmp;
		}
	}
}
#endif

//heap sort
#include <stdio.h>

/*
 堆排序分为建立堆和从堆中取最小/最大值的两个过程，前者是O(N)，后者是O(logN)，因此该
 排序算法需要的时间是O(NlogN)
*/
void heap_sort()
{

}

//merge sort

/*
 归并排序排序时间很快，最差需要时间是O(NlogN)。但是由于排序时需要额外的内存（临时数组）以及数组间拷贝操作
 所以一般不会用于内存排序。归并排序是许多外部排序的基石
*/
void merge_sort()
{

}

//quick sort

/*
 快速排序是实践中一种很快的排序方法，平均时间是O(NlogN)，最坏时间是O(N^2)。
 选取合适的中值对快速排序速度提升有很大帮助。
 对于小数组 -- 长度小于20的数组，由于采用了递归实现，快速排序一般慢于插入排序
*/
void quick_sort()
{

}
