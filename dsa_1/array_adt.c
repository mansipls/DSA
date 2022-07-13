#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};
//function to swap two pointer values
void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}
//function to display the elements of an Array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are:\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}
//function to append an integer x towards the end of an array
void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}
//function to insert an integer x at index 'index' in a given array
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>=0  && index <=arr->length){
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];    
        arr->A[index]=x;
        arr->length++;
    }
}
//function to delete element at index 'index' in an array
void Delete(struct Array *arr, int index)
{
    int i;
    if(index>=0 && index<=arr->length){
        for(i=index;i<=arr->length;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
    }
}
//function that returns the index of element x in an array
int linear_search(struct Array *arr, int x){
    int i;
    for(i=0;i<arr->length;i++){
        if(x==arr->A[i]){
            return i;
        }
    }
    return -1;
}
//function to get the value at a given index
int Get(struct Array arr,int index){
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1; 
}
//function to set value of an array at index 'index' as x
int Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}
//function to find maximum value of an array
int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}

//function to find minimum value of an Array
int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}
//Sum of all values of an index
int Sum(struct Array arr){
    int sum=0;
    int i;
    for(i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return (float) Sum(arr)/arr.length;
}
//main function
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    
    printf("%d",Get(arr,2));
    Set(&arr,0,12);
    Display(arr);
    printf("%f",Avg(arr));
    return 0;

}
