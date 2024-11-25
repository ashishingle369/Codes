#include<iostream>
#include<math.h>
using namespace std;

int main()
{ int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    int arr[n];
    int i,j;
    cout<<"Enter elements for an array with size 5:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=1 ; i<n ; i++){
        for(j=0 ; j<n-i ;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
 cout<<"sorted array: "<<endl;
        for(i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
    return 0;
}