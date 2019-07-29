#include "sort.h"

typedef int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
void StackDestory(Stack *ps)
{
	assert(ps);
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}
void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : (ps->_capacity) * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}
STDataType StackTop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
bool StackEmpty(Stack *ps)
{
	assert(ps);
	return !(ps->_top);
}
int StackSize(Stack *ps)
{
	assert(ps);
	return ps->_top;
}


void InsertSort(int *a, int n)
{   //判插入n-1个temp的位置
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			//如果temp小于end，依次把end后移，直到找到end比temp小
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;;
		}
		//把temp插入到end后面
		a[end + 1] = temp;
	}
}

void testInsert()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void ShellSort(int *a, int n)
{
	int gap = n;
	//每次预处理使数组更趋于有序，直到gap = 1，进行最后一次插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}

void testShell()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *a1, int *a2)
{
	int temp = 0;
	temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	int minindex,maxindex;
	while (begin <= end)
	{
		//单趟遍历找到最大和最小值
		minindex = maxindex = begin;
		//遍历找到最小下标和最大下标
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[minindex])
				minindex = i;
			if (a[i] >= a[maxindex])
				maxindex = i;
		}
		//交换begin位置为最小值
		Swap(&a[begin], &a[minindex]);
		if (maxindex == begin)
			maxindex = minindex;
		//交换end位置为最大值
		Swap(&a[end], &a[maxindex]);
		++begin;
		--end;
	}
}

void testSelect()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	SelectSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void adjustdown(int *a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//升序 建大堆
void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjustdown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		adjustdown(a, end, 0);
		end--;
	}
}

void testHeap()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void BubbleSort(int *a, int n)
{
	int end = n - 1;
	while (end)
	{
		for (int i = 0; i < end; i++)
		{
			if (a[i + 1] < a[i])
				Swap(&a[i], &a[i + 1]);
		}
		end--;
	}
}

void testBubble()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//左右指针法
int PartSort1(int *a, int left, int right)
{
	int key = a[right];
	int keyindex = right;
	while (left < right)
	{
		while(left < right && a[left] <= key)
			left++;
		while(left < right && a[right] >= key)
			right--;
		if (left < right)
		{
			Swap(&a[left], &a[right]);
			left++;
			right--;
		}
	}
	Swap(&a[left], &a[keyindex]);
	return left;
}

void QuickSort1(int *a, int left,int right)
{
	if (left >= right)
		return;
	int keyindex = PartSort1(a,left,right);
	QuickSort1(a, left, keyindex - 1);
	QuickSort1(a, keyindex + 1 , right);
}

void testQuick1()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	QuickSort1(a, 0,(sizeof(a) / sizeof(int))-1);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int GetMid(int *a, int left,int  right)
{
	int mid = left + (right - left) / 2;
	if (a[right] < a[left])
	{
		if (a[mid] < a[right])
			mid = right;
		else if (a[mid] > a[left])
			mid = left;
	}
	if (a[right] > a[left])
	{
		if (a[mid] > a[right])
			mid = right;
		else if (a[mid] < a[left])
			mid = left;
	}
	return mid;
}

//挖坑优化法
int PartSort2(int *a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;
		a[right] = a[left];
		while (left < right && a[right] >= key)
			right--;
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

void QuickSort2(int *a, int left, int right)
{
	if (left >= right)
		return;
	int keyindex = PartSort2(a, left, right);
	if (right - left >= 10)
		InsertSort(a, left, right);
	QuickSort2(a, left, keyindex - 1);
	QuickSort2(a, keyindex + 1, right);
}

void testQuick2()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	QuickSort2(a, 0, (sizeof(a) / sizeof(int)) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//非递归前后指针法
int PartSort3(int *a, int left, int right)
{
	int prev = left - 1;
	int cur = left;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	prev++;
	Swap(&a[right], &a[prev]);
	return prev;

}

void QuickSort3(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int div = PartSort3(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
}

void testQuick3()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 3, 4, 0, 5 };
	QuickSort3(a, 0, (sizeof(a) / sizeof(int)) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int *a, int *temp, int left, int right)
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, temp, left, mid);
	_MergeSort(a, temp, mid + 1, right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i] = a[begin1];
			begin1++;
			i++;
		}
		else
		{
			temp[i] = a[begin2];
			begin2++;
			i++;
		}
	}
	while (begin1 <= end1)
	{
		temp[i] = a[begin1];
		begin1++;
		i++;
	}
	while (begin2 <= end2)
	{
		temp[i] = a[begin2];
		begin2++;
		i++;
	}
	memcpy(a + left, temp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int *a, int n)
{
	int *temp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, temp, 0, n - 1);
	free(temp);
}

void testMerge()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 4, 3, 0, 5 };
	MergeSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void MergeSortNonR(int *a, int n)
{
	int *temp = (int *)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		int i = 0;
		for (int begin = 0; begin < n; begin += 2 * gap)
		{
			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 > n - 1)
				end1 = n - 1;
			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 > n - 1)
				end2 = n - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					temp[i++] = a[begin1++];
				else
					temp[i++] = a[begin2++];
			}
			while (begin1 <= end1)
				temp[i++] = a[begin1++];
			while (begin2 <= end2)
				temp[i++] = a[begin2++];
		}
		memcpy(a, temp, sizeof(int)*n);
		gap *= 2;
	}
	free(temp);
}

void  testMergeNonR()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 4, 3, 0, 5, 2 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void CountSort(int *a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int *counta = (int *)malloc(sizeof(int)* range);
	memset(counta, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
		counta[a[i] - min]++;
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;
		}
	}
}

void  testCount()
{
	int a[] = { 1, 6, 4, 7, 8, 9, 4, 3, 0, 5 };
	CountSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}



#define N 10000

void testOP()
{
	srand((unsigned int)time(NULL));

	int a1[N] = { 0 };
	int a2[N] = { 0 };
	int a3[N] = { 0 };
	int a4[N] = { 0 };
	int a5[N] = { 0 };
	int a6[N] = { 0 };
	int a7[N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		a1[i] = (int) rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, sizeof(a1) / sizeof(int));
	int end1 = clock();
	printf("InsertSort time:%d\n", end1 - begin1);

	int begin2 = clock();
	ShellSort(a2, sizeof(a2) / sizeof(int));
	int end2 = clock();
	printf("ShellSort time:%d\n", end2 - begin2);

	int begin3 = clock();
	SelectSort(a3, sizeof(a3) / sizeof(int));
	int end3 = clock();
	printf("SelectSort time:%d\n", end3 - begin3);

	int begin4 = clock();
	HeapSort(a4, sizeof(a4) / sizeof(int));
	int end4 = clock();
	printf("HeapSort time:%d\n", end4 - begin4);

	int begin5 = clock();
	BubbleSort(a5, sizeof(a5) / sizeof(int));
	int end5 = clock();
	printf("BubbleSort time:%d\n", end5 - begin5);

	int begin6 = clock();
	QuickSort2(a6, 0, sizeof(a6) / sizeof(int)-1);
	int end6 = clock();
	printf("QuickSort time:%d\n", end6 - begin6);

	int begin7 = clock();
	MergeSort(a7, sizeof(a7) / sizeof(int));
	int end7 = clock();
	printf("MergeSort time:%d\n", end7 - begin7);
}