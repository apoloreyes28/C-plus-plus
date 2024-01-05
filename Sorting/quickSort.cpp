#include <iostream>
using namespace std;

void quickSort(int *arr, int left, int right){
   int i = left, j = right, temp;
   int p = arr[(left+right)/2];
   
   while(i<=j){
     while(arr[i] < p) i++;
     while(arr[j] > p) j--;
     
     if(i<=j){
        temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;     j--;	
	 }
   } 
   if(left < j)
      quickSort(arr, left, j);
      if(i < right)
         quickSort(arr, i, right);
} 

int main(){        //  0 1 2 3 4 5 6 7 8 9
	int array[10] = {4,6,2,9,1,5,7,3,8,0};
	
	quickSort(array, 0, 9);
	
	for(int i=0; i<10; i++)
	    cout<<array[i]<<" ";
	    cout<<"\n";
	
system("pause");
return 0;
}
