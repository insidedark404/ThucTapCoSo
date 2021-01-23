#include <bits/stdc++.h>
using namespace std;

//manual input
void nhap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> arr[i];
    }
}
//random input-
int randomarr(int arr[], int n)
{
   cout<<"Nhap so phan tu cua mang:";
   cin>>n;
   for(int i=0;i<n;i++)
      arr[i]=rand()%100;
}

//output
void xuat(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

//doi vi tri 2 phan tu
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

//ham thuc hien bubble sort
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)       
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}
  
//ham thuc hien selection sort
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
    
    for (i = 0; i < n-1; i++)  
    {    
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
    
        swap(&arr[min_idx], &arr[i]);  
    }  
}

//ham thuc hien insertion sort
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

//ham thuc hien merge sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // tao mang tam (temp)
    int L[n1], R[n2];
 
    // chep du lieu sang mang L[] va R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    //ghep hai mang tam lai L, R va gan vao mang temp
 
    int i = 0;
 
    int j = 0;
 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {   
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  

        int pi = partition(arr, low, high);  
  
 
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 
int main()
{
	int a;int n; int arr[1000];int b;
	cout<<"Menu:\n";
	cout<<"1. Xep mang voi thuat toan Bubble-Sort\n2. Xep mang voi thuat toan Selection-Sort\n3. Xep mang voi thuat toan Insertion-Sort\n4. Xep mang voi thuat toan Merge-Sort\n5. Xep mang voi thuat toan Quick-Sort\n";
	cout<<"\n";
	cout<<"Nhap phuong phap xep mang: ";
	cin>> a;
	cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout<<"Nhap loai input:\n1.Nhap tu ban phim\n2.Nhap mang ngau nhien\n3.Nhap mang tu file\n";
    cin>>b;
    switch(b)
    {
    	case 1:
    		nhap(arr, n);
    		break;
    	case 2:
    		randomarr(arr,n);
    		break;
	}
    
    cout << "Mang truoc khi sap xep la: " << endl;
    xuat(arr, n);
    cout<<"\n";
	
	switch(a)
	{
		case 1:
			bubbleSort(arr, n);
			cout<<"Mang sau khi sap xep la:\n";
    		xuat(arr,n);
			break;
			
		case 2:
			selectionSort(arr, n);
			cout<<"Mang sau khi sap xep la:\n";
			xuat(arr,n);
			break;
			
		case 3:
			insertionSort(arr, n);
			cout<<"Mang sau khi sap xep la:\n";
			xuat(arr,n);
			break;	
		
		case 4:
			mergeSort(arr, 0, n - 1);
			cout<<"Mang sau khi sap xep la:\n";
			xuat(arr,n);
			break;
		
		case 5:
			quickSort(arr, 0, n - 1);
			cout<<"Mang sau khi sap xep la:\n";
			xuat(arr,n);
			break;
	}
	return 0;
}
