#include<stdio.h>

void Heapify(int a[], int heapSize, int root)
{
    int left, right, largest = root, temp;
    left = 2 * root;
    right = 2 * root + 1;
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
void BuildHeap(int a[], int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        Heapify(a, n, i);
}
void HeapSort(int a[], int n)
{
    int heapSize = n, i, temp;
    BuildHeap(a, n);

    for(i=n;i>=1;i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        heapSize--;
        Heapify(a, heapSize, 1);
    }
}
int main()
{
    int numbers[100], i, n;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &numbers[i]);

    HeapSort(numbers, n);

    printf("Sorted Numbers: \n");
    for(i=1;i<=n;i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
