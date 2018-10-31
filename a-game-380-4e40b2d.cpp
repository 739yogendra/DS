#include<iostream>

using namespace std;

long minimum(int arr[],long start,long end){
    int min=arr[start],pos=start;
    for(int i=start+1;i<end;i++){
        if(arr[i]<min){
            min=arr[i];
            pos=i;
        }
    }
    return pos;
}



int main(){
    long t;
    cin>>t;
    while(t){
        long m,i,pos,temp;
        cin>>m;
        int arr[m];
        
        for(i=0;i<m;i++){
            cin>>arr[i];
            
        }
        
        int stackT[m],stackU[m];
        long topT=-1,topU=-1,j=0,k=0,s=0,minpos;
        
        
        
        for(i=0;i<m;i++){
            
            minpos=minimum(arr,i,m);
            
            if((stackT[topT]<=arr[minpos])&&topT!=-1){
                while(stackT[topT]<=arr[minpos]){
                    topU=topU+1;
                    stackU[topU]=stackT[topT];
                    topT=topT-1;
                }
            }
            
            topU=topU+1;
            stackU[topU]=arr[minpos];
            temp=minpos-1;
            k=i;
            while(temp>=k){
                topT=topT+1;
                stackT[topT]=arr[k];
                k++;
            }
            i=minpos;
        }
        s=0;
        while(topT!=-1){
            topU=topU+1;
            stackU[topU]=stackT[topT];
            topT=topT-1;
        }
        while(s<=topU){
            cout<<"v"<<stackU[s];
            s++;
        }
        
        
        t--;
    }
}