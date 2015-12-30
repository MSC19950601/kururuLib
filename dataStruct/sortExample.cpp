#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<ctime>
#include<iomanip>
#include<windows.h>
using namespace std;

#define SIZE 1000000

typedef int ElementType;
ElementType Arr1[SIZE], Arr2[SIZE], Arr3[SIZE], Arr4[SIZE], Arr5[SIZE], Arr6[SIZE], Arr7[SIZE], Arr8[SIZE];

/*
*<<ֱ�Ӳ�������>>
* Ϊ��ʵ��N���������򣬽�����N-1�������β��뵽ǰ�����źõ��������У�
*�ٶ��տ�ʼ��1������һ�����ź���������С�����N-1�˾��ܵõ�һ���������С�
*****ʱ�临�Ӷȣ�������O(n)������O(n^2)��ƽ�����O(n^2).
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ��ȶ�
*/
void InsertSort(ElementType A[], int n)
{
	int i, j;
	ElementType temp; //��ʱ����

	for (i = 1; i<n; ++i)
	{
		temp = A[i];
		for (j = i; j>0 && A[j - 1]>temp; --j)
			A[j] = A[j - 1];
		A[j] = temp;
	}
}

/*
*<<�۰��������>>
* ��ֱ�Ӳ�������ͬ���ǣ��۰���������Ǳ߱Ƚϱ��ƶ������ǽ��ȽϺ���
*��������������������۰���ҳ�Ԫ�صĴ�����λ�ã�Ȼ����ͳһ���ƶ�������λ
*��֮�������Ԫ�ء����ѿ����۰������������Ǽ����˱ȽϵĴ�����
*****ʱ�临�Ӷȣ�O(n^2)
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ��ȶ�
*/
void BinaryInsertSort(ElementType A[], int n)
{
	int i, j, low, high, mid;
	ElementType temp;
	for (i = 1; i<n; ++i)
	{
		temp = A[i];
		low = 0; high = i - 1; // �����۰���ҵķ�Χ
		while (low <= high)
		{
			mid = (low + high) / 2; // ȡ�м��
			if (A[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (j = i - 1; j >= high + 1; --j) // ͳһ����
			A[j + 1] = A[j];
		A[high + 1] = temp; // ����
	}
}

/*
*<<ϣ������>>
* ϣ������ͨ���Ƚ����һ�������Ԫ�أ�������L[i,i+d,i+2d,...i+kd]������
*Ȼ����С��࣬�ٶԸ��������н�������ֱ��ֻ�Ƚ�����Ԫ�ص����һ������Ϊ
*ֹ�������ļ��Ϊ1��ϣ��������ʱҲ����*��С��������*
*****ʱ�临�Ӷȣ��������������е�ѡ�񣬵�������ΪO(N^2)
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ����ȶ�
*/
void ShellSort(ElementType A[], int n)
{
	int i, j, dk; // dk������
	ElementType temp;

	for (dk = n / 2; dk>0; dk /= 2) // �����仯
	{
		for (i = dk; i<n; ++i) // ÿ���������н���ֱ�Ӳ�������
		{
			temp = A[i];
			for (j = i - dk; j >= 0 && A[j]>temp; j -= dk)
				A[j + dk] = A[j]; // ����
			A[j + dk] = temp;
		}
	}
}

/*
*<<ð������>>
* ð������Ļ���˼���ǴӺ���ǰ�����ǰ���������Ƚ�����Ԫ�ص�ֵ����Ϊ
*�����򽻻����ǣ�ֱ�����бȽ��ꡣ���ǳ���Ϊһ��ð�ݡ�ÿһ��ð�ݶ��Ὣһ
*��Ԫ�ط��õ�������λ���ϡ�
*****ʱ�临�Ӷȣ�������O(n)������O(n^2)��ƽ�����O(n^2)
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ��ȶ�
*/
void BubbleSort(ElementType A[], int n)
{
	for (int i = 0; i<n - 1; ++i)
	{
		bool flag = false; // ��ʾ����ð���Ƿ��������ı�־
		for (int j = n - 1; j>i; --j) // �Ӻ���ǰ
		{
			if (A[j - 1] > A[j])
			{
				flag = true;
				// ����
				A[j - 1] = A[j - 1] ^ A[j];
				A[j] = A[j - 1] ^ A[j];
				A[j - 1] = A[j - 1] ^ A[j];
			}
		}

		if (flag == false)
			return;
	}
}

/*
*<<��������>>
* ���������Ƕ�ð�������һ�ָĽ��������˼���ǻ��ڷ��η����ڴ������L[n]
*����ȡһ��Ԫ��pivot��Ϊ��׼��ͨ��һ���������л���Ϊ������L[1...K-1]��
*L[k+1...n]���ǵ�L[1...k-1]�е�����Ԫ�ض�С��pivot����L[k+1...n]������Ԫ��
*�����ڻ����pivot����pivot������������λ��L(k)�ϡ�Ȼ�󣬷ֱ�ݹ�ض�������
*�����ظ��������̣�ֱ��ÿ������ֻ��һ��Ԫ�ػ��Ϊֹ��������Ԫ�ط�����������
*λ���ϡ�
*****ʱ�临�Ӷȣ����ŵ�����ʱ���뻮���Ƿ�Գ��йأ�����O(n^2),������
*O(nlogn),ƽ�����ΪO(nlogn)
*****�ռ临�Ӷȣ�������Ҫ�ݹ鹤��ջ������ΪO(n)��ƽ�����ΪO(logn)
*****�ȶ��ԣ����ȶ�
*/
int Partition(ElementType A[], int low, int high)
{
	// ���ֲ����кܶ�汾����������Ե�ǰ���е�һ��Ԫ����Ϊ��Ŧ/��׼
	ElementType pivot = A[low];
	while (low < high)
	{
		while (low<high && A[high] >= pivot)
			--high;
		A[low] = A[high]; // ������ŦֵС��Ԫ���Ƶ����
		while (low<high && A[low] <= pivot)
			++low;
		A[high] = A[low]; // ������Ŧֵ���Ԫ���Ƶ��Ҷ�
	}

	A[low] = pivot; // ��ŦԪ�طŵ�����λ��
	return low;  // ������ŦԪ�ص�λ��
}

void QuickSort(ElementType A[], int low, int high)
{
	if (low < high) // �ݹ�����������
	{
		int pivotPos = Partition(A, low, high); // ���ֲ��������ػ�׼Ԫ�ص�����λ��
		QuickSort(A, low, pivotPos - 1); // �ݹ�
		QuickSort(A, pivotPos + 1, high);
	}
}

/*
*<<��ѡ������>>
* ѡ��������㷨˼��ܼ򵥣���������ΪL[n]����i�����򼴴�L[i...n]��ѡ��
*�ؼ�����С��Ԫ����L(i)������ÿһ���������ȷ��һ��Ԫ�ص�����λ�á�����n-1
*������Ϳ���ʹ�����������ˡ�
*****ʱ�临�Ӷȣ�ʼ����O(n^2)
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ����ȶ�
*/
void SelectedSort(ElementType A[], int n)
{
	for (int i = 0; i<n - 1; ++i) // һ������n-1��
	{
		int minPos = i; // ��¼��СԪ�ص�λ��

		for (int j = i + 1; j<n; ++j)
		if (A[j] < A[minPos])
			minPos = j;

		if (minPos != i) // ���i��λ�ý���
		{
			A[i] = A[i] ^ A[minPos];
			A[minPos] = A[i] ^ A[minPos];
			A[i] = A[i] ^ A[minPos];
		}
	}
}

/*
*<<������>>
* ��������һ������ѡ�����򷽷�������������У���L[n]������һ����ȫ����
*����˳��洢�ṹ��������ȫ��������˫�׽ڵ�ͺ��ӽڵ�֮������ڹ�ϵ���ڵ�
*ǰ��������ѡ��ؼ�����󣨻���С����Ԫ�ء��������˼·�ǣ����Ƚ�����L[n]
*��n��Ԫ�ؽ��ɳ�ʼ�ѣ����ڶѱ�����ص㣨�Դ����Ϊ�������Ѷ�Ԫ�ؾ������
*ֵ������Ѷ�Ԫ�غ�ͨ�����ѵ�Ԫ������Ѷ�����ʱ������Ѳ��������ѵ���
*�ʣ��ѱ��ƻ������Ѷ�Ԫ�����µ���ʹ��������ִ���ѵ����ʣ�������Ѷ�Ԫ�ء�
*����ظ���ֱ�����н�ʣ��һ��Ԫ��Ϊֹ��
*****ʱ�临�Ӷȣ�O(nlogn)
*****�ռ临�Ӷȣ�O(1)
*****�ȶ��ԣ����ȶ�
*/

void AdjustDown(ElementType A[], int i, int len)
{
	ElementType temp = A[i]; // �ݴ�A[i]

	for (int largest = 2 * i + 1; largest<len; largest = 2 * largest + 1)
	{
		if (largest != len - 1 && A[largest + 1]>A[largest])
			++largest;   // ������ӽ���
		if (temp < A[largest])
		{
			A[i] = A[largest];
			i = largest;   // ��¼�������λ��
		}
		else
			break;
	}
	A[i] = temp; // ��ɸѡ����ֵ��������λ��
}
void BuildMaxHeap(ElementType A[], int len)
{
	for (int i = len / 2 - 1; i >= 0; --i) // ��i=[n/2]~1������������
		AdjustDown(A, i, len);
}
void HeapSort(ElementType A[], int n)
{
	BuildMaxHeap(A, n);  // ��ʼ����
	for (int i = n - 1; i>0; --i) // n-1�˵Ľ����ͽ��ѹ��� 
	{
		// ������ĶѶ�Ԫ�أ��Ͷѵ�Ԫ�ؽ�����
		A[0] = A[0] ^ A[i];
		A[i] = A[0] ^ A[i];
		A[0] = A[0] ^ A[i];
		// ��������ʣ���n-1��Ԫ������ɶ�
		AdjustDown(A, 0, i);
	}
}

/*
*<<2-·�鲢����>>
* ����˼�壬2-·�鲢���ǽ�2���������ϳ�һ���µ�������ٶ��������
*��n��Ԫ�أ�����Կ�����n��������ӱ�ÿ���ӱ���Ϊ1��Ȼ�������鲢...��
*ͣ�ظ���ֱ���ϳ�һ������Ϊn����������Ϊֹ��Merge()�����ǽ�ǰ�����ڵ�����
*�����鲢Ϊһ���������A[low...mid]��A[mid+1...high]�����ͬһ˳����
*����λ���ϣ��Ƚ����Ǹ��Ƶ���������B�С�ÿ�δӶ�ӦB�е�������ȡ��һ��Ԫ��
*���бȽϣ�����С�߷���A�С�
*****ʱ�临�Ӷȣ�ÿһ�˹鲢ΪO(n),��log2n�ˣ�����ʱ��ΪO(nlog2n)
*****�ռ临�Ӷȣ�O(n)
*****�ȶ��ԣ��ȶ�
*/
ElementType *B = new ElementType[SIZE]; // ������Aһ����
void Merge(ElementType A[], int low, int mid, int high)
{
	int i, j, k;
	for (k = low; k <= high; ++k)
		B[k] = A[k];    // ��A������Ԫ�ظ��Ƶ�B
	for (i = low, j = mid + 1, k = i; i <= mid&&j <= high; ++k)
	{
		if (B[i] <= B[j])  // �Ƚ�B���������������е�Ԫ��
			A[k] = B[i++]; // ����Сֵ���Ƶ�A��
		else
			A[k] = B[j++];
	}
	while (i <= mid) A[k++] = B[i++]; // ����һ����δ����꣬����
	while (j <= high) A[k++] = B[j++]; // ���ڶ�����δ����꣬����
}

void MergeSort(ElementType A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);  // ����������н��еݹ�����
		MergeSort(A, mid + 1, high); // ���Ҳ������н��еݹ�����
		Merge(A, low, mid, high);  // �鲢
	}
}

/*
* �������
*/
void print(ElementType A[], int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

/*
* ������
*/
int main()
{
	cout << setiosflags(ios::fixed);
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++){
		Arr1[i] = Arr2[i] = Arr3[i] = Arr4[i] = Arr5[i] = Arr6[i] = Arr7[i] = Arr8[i] = rand();
	}

	double dur1;
	clock_t start1, end1;
	start1 = clock();
	InsertSort(Arr1, SIZE);
	end1 = clock();
	dur1 = (double)(end1 - start1);
	printf("ֱ�Ӳ������� Use Time:%.30f\n", (dur1 / CLOCKS_PER_SEC));

	double dur2;
	clock_t start2, end2;
	start2 = clock();
	BinaryInsertSort(Arr2, SIZE);
	end2 = clock();
	dur2 = (double)(end2 - start2);
	printf("�۰�������� Use Time:%.30f\n", (dur2 / CLOCKS_PER_SEC));

	double dur3;
	clock_t start3, end3;
	start3 = clock();
	ShellSort(Arr3, SIZE);
	end3 = clock();
	dur3 = (double)(end3 - start3);
	printf("ϣ������ Use Time:%.30f\n", (dur3 / CLOCKS_PER_SEC));

	double dur4;
	clock_t start4, end4;
	start4 = clock();
	BubbleSort(Arr4, SIZE);
	end4 = clock();
	dur4 = (double)(end4 - start4);
	printf("ð������ Use Time:%.30f\n", (dur4 / CLOCKS_PER_SEC));

	
	double dur5;
	clock_t start5, end5;
	start5 = clock();
	QuickSort(Arr5, 0, SIZE - 1);
	end5 = clock();
	dur5 = (double)(end5 - start5);
	printf("�������� Use Time:%.30f\n", (dur5 / CLOCKS_PER_SEC));

	
	double dur6;
	clock_t start6, end6;
	start6 = clock();
	SelectedSort(Arr6, SIZE);
	end6 = clock();
	dur6 = (double)(end6 - start6);
	printf("ѡ������ Use Time:%.30f\n", (dur6 / CLOCKS_PER_SEC));

	
	double dur7;
	clock_t start7, end7;
	start7 = clock();
	HeapSort(Arr7, SIZE);
	end7 = clock();
	dur7 = (double)(end7 - start7);
	printf("������ Use Time:%.30f\n", (dur7 / CLOCKS_PER_SEC));

	
	double dur8;
	clock_t start8, end8;
	start8 = clock();
	MergeSort(Arr8, 0, SIZE - 1);
	end8 = clock();
	dur8 = (double)(end7 - start7);
	printf("�鲢���� Use Time:%.30f\n", (dur8 / CLOCKS_PER_SEC));

	system("pause");
	return 0;
}