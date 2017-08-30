#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int MaxHeap(int a[],int index,int k){  
    int MaxIndex = index;  
    int LeftIndex = 2*index;  
    int RightIndex = 2*index+1;  
    if(LeftIndex <= k && a[LeftIndex] > a[MaxIndex]){  
        MaxIndex = LeftIndex;  
    }  
    if(RightIndex <= k && a[RightIndex] > a[MaxIndex]){  
        MaxIndex = RightIndex;  
    }  
    int temp;  
    if(MaxIndex != index){  
        temp = a[index];  
        a[index] = a[MaxIndex];  
        a[MaxIndex] = temp;  
        MaxHeap(a,MaxIndex,k);  
    }
    return 0;  
}  
int BuildMaxHeap(int a[],int k){  
    for(int i = k;i >= 1;i--)
        MaxHeap(a,i,k);
    return 0;  
}
int main(){
    int n,x,k,a[N];
    while(cin>>n>>k){
        int num=k;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(num){
                a[num--]=x;
                if(num==0)
                    BuildMaxHeap(a,k);
            }else{
                if(a[1]>x){
                    a[1]=x;
                    MaxHeap(a,1,k);
                }
            }
        }
        for(int i=1;i<=k;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
