#include <iostream>

double getNum() //Tạo 1 số thực ngẫu nhiên dạng double
{
	return ((double)rand() / (RAND_MAX));
}

double* Arr(int n)
{
    double *A = new double[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = getNum();
    }
    return A;
}
long dem;
void quickSort(double *A, int l, int r)
{
    int i = l, j = r;
    int mid = (l+r)/2; dem += 2;
    double pivot = A[mid];
    while (i < j)
    {
        while (A[i] > pivot) {i++; dem+=2;}
        while (A[j] < pivot) {j--;dem+=2;}
        if (i <= j) 
        {
            std::swap(A[i], A[j]);
            i++;
            j--;dem+=4;
        }
    }
    if (i < r) {dem++;quickSort(A,i,r);}
    if (j > l) {dem++;quickSort(A,l,j);}
}
int main()
{
    srand(4);
    double *A;

    for (int i = 1000; i <= 20000; i+=1000)
    {
        dem = 0;
        A = Arr(i);
        quickSort(A,0,i-1);
        std::cout << dem << std::endl;
    }
}
