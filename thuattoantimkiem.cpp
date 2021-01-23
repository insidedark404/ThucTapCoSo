#include<bits/stdc++.h>
using namespace std;

void nhap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> arr[i];
    }
}

int InterpolationSearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right && x >= arr[left] && x <= arr[right])
    {
        mid = left + (right - left) * (x - arr[left]) / (arr[right] - arr[left]);
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            right = mid - 1;
        else if (arr[mid] < x)
            left = mid + 1;
    }
    return -1; // Không tìm th?y x
}

int BinarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid; // tìm thay x, tra ve mid là vi trí caa x trong mang Arr
        if (arr[mid] > x)
            right = mid - 1; // Gi?i h?n kho?ng tìm kiem lai là nua khoang truac
        else if (arr[mid] < x)
            left = mid + 1; // Gioi han khoang tìm kiem lai là nua khoang sau
    }
    return -1; // không tìm thay x
}

int LinearSearch(int A[], int n, int x)
{
    int i = 0;
    A[n] = x;
    while (A[i] != x)
        i++;
    if (i == n)
        return -1;
    return i;
}

int main() 
{
	int a; int arr[1000]; int n ;int x; int index;
	cout<< "Menu:\n1.Tim kiem noi suy\n2.Tim kiem nhi phan\n3.Tim kiem trinh tu\n\n";
	cout<<"Nhap phuong phap tim kiem: ";
	cin>> a;
	cout<< "Nhap so phan tu mang : ";
	cin>> n;
	cout<< "Nhap mang chua du lieu can tim: \n";
	nhap( arr, n);
	cout<<"Nhap vao gia tri can tim: ";
	cin>> x;
	switch(a)
	{
		case 1:
			index =InterpolationSearch(arr, n, x);
    		if (index != -1)
        		cout << "Gia tri duoc tim thay o vi tri " << index;
    		else
        		cout << "Gia tri khong ton tai";
			break;
		
		case 2:
			index = BinarySearch(arr, n, x);
    		if (index != -1)
        		cout << "Gia tri duoc tim thay o vi tri " << index;
    		else
        		cout << "Gia tri khong ton tai";
			break;
			
		case 3:
			index = LinearSearch(arr, n, x);
    		if (index != -1)
        		cout << "Gia tri duoc tim thay o vi tri " << index;
    		else
        		cout << "Gia tri khong ton tai";
			break;
	}
	
}
