#include<stdio.h>
void Heapify(int a[], int heapSize, int root)
{
    int left = 2 * root;
    int right = 2 * root +1;
    int largest = root, temp;
    if(left <= heapSize && a[left] > a[root])
        largest = left;
    if(right <= heapSize && a[right] > a[largest])
        largest = right;
    if(largest != root)
    {
        temp = a[largest];
        a[largest] = a[root];
        a[root] = temp;

        Heapify(a, heapSize, largest);
    }
}
void BuildHeap(int a[], int heapSize)
{
    int i;
    for(i=heapSize/2;i>=1;i--)
        Heapify(a, heapSize, i);
    printf("After Building Max-Heap\n");
    for(i=1;i<=heapSize;i++)
        printf("%d ", a[i]);
    printf("\n");
}
void HeapSort(int a[], int heapSize)
{
    BuildHeap(a, heapSize);
    int n = heapSize, temp, i, j;
    for(i=n;i>=1;i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        heapSize--;
        Heapify(a, heapSize, 1);
        printf("After heapify process\n");
        for(j=1;j<=heapSize;j++)
            printf("%d ", a[j]);
        printf("\n");
    }
}
int main()
{
    int i, n, numbers[100];
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &numbers[i]);

    HeapSort(numbers, n);

    printf("Sorted Numbers:\n");
    for(i=1;i<=n;i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;r
}
