#include<iostream>
#include<cmath>
using namespace std;
int jump_Search(int a[], int n, int item) {
   int i = 0;
   int m = sqrt(n);

   while(m < n && a[m] <= item) 
   {
      i = m;  
      m += sqrt(n);
 //     printf("m=%d",m);
 //  	  system("pause");
      if(m > n ) 
      {
      //	printf("m=%d,n=%d",m,n);
      //	 return -1; 
      m=n;
	  }

   }
  // printf("i=%d,m=%d",i,m);
   for(int x = i; x<m; x++) 
   { 
      if(a[x] == item)
         return x; 
   }
   return -1;
}
int main()
 {
   int n,j, item, key;
   for(j=0;j<=2;j++)
{
   cout << "\n Enter range: ";
   cin >> n;
   int arr[n]; 
   cout << "\n Enter elements in the array : ";

   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }
   cout << "\n Enter key element: ";
   cin >> item;
   key = jump_Search(arr, n, item);
   if(key>=0)
      cout << "\n Present: " << key;
   else
      cout << "\n Not Present";
  }
}
