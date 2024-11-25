#include<iostream>
using namespace std;

int main(){
    int i,j,temp;
    int n;
    //size of array
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    //elements from user
    cout<<"enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //displaying array
    cout<<"array: \t";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    //i and j loop for insertion sort where i loop gives 1 element and j comparing it with all elements of array.
    for(i=1;i<n;i++){
         temp=arr[i];
       for (j=i-1;j>=0;j--){
        //if given element is already large then no need to change and break;
        if(temp>arr[j]){
            break;
        }
        //else we assign the gretest value of j loop to ith element so we copy it with higher index to sort
        else{
            arr[j+1]=arr[j];
        }
        //after breaking condition we assign the value of temp to proper location using j loop
       }
       arr[j+1]=temp;

    }
       cout<<"Sorted Array: \t";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}