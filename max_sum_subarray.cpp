#include<bits/stdc++.h>
using namespace std;
int divide_and_conquer(vector<int> arr,int start,int end)
{
    if(start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;

    int leftsum = divide_and_conquer(arr,start,mid);
    int rightsum = divide_and_conquer(arr,mid+1,end);

    int leftmax = arr[mid];
    int total = 0;

    for(int i = mid+1 ;i<= end;i++)
    {
        
    }

}
int main()
{

}