#include <bits/stdc++.h>
#include <math.h>

const double pi = 3.14159265358979323846;
using namespace std;

vector<pair<double,double>> fft(vector<pair<double,double>>arr,int size,int n){
    if(n<=1)
    return arr;
    
    
    int esize,osize;
    double wreal,wimag;
    
    wreal=1.00;
    wimag=0.00;
    
    
    
    if(size!=1){
        if(size%2){
            esize=size/2;
        }
        else{
            esize=(size+1)/2;
        }
        osize=size/2;
        
        vector<pair<double,double>>odd(osize),even(esize);
        int i;
    
        for(i=0;i<esize;i++){
            even[i]=arr[2*i];
        }
        for(i=0;i<osize;i++){
            odd[i]=arr[2*i+1];
        }
        
        vector<pair<double,double>>curreven(n/2);
        vector<pair<double,double>>currodd(n/2);
    
    
    
    
        curreven=fft(even,esize,n/2);
        currodd=fft(odd,osize,n/2);
        
        vector<pair<double,double>>y(n);
    
        for(i=0;i<n/2;i++){
        
            y[i].first=curreven[i].first+(wreal*currodd[i].first-wimag*currodd[i].second);
            y[i].second=curreven[i].second+(wimag*currodd[i].first+wreal*currodd[i].second);
            y[i+n/2].first=curreven[i].first-(wreal*currodd[i].first-wimag*currodd[i].second);
            y[i+n/2].second=curreven[i].second-(wimag*currodd[i].first+wreal*currodd[i].second);
        
            wreal=cos(2*pi*(i+1)/n);
            wimag=sin(2*pi*(i+1)/n);
        }
        
    return y;
    }
    
    
    
    else{
        
        esize=size;
        
        //curreven=arr;
        int i;
        
        vector<pair<double,double>>y(n);
        
        for(i=0;i<n/2;i++){
        
            y[i].first=arr[0].first;
            y[i].second=arr[0].second;
            y[i+n/2].first=arr[0].first;
            y[i+n/2].second=arr[0].second;
        }
        
        return y;
    
    }
    
}

int main() {
	int d,i,n;
	cin >> d;										
	
	vector<pair<double,double>>arr(d);
	
	for(i=0;i<d;i++){
	    cin>>arr[i].first;
	}
	
	for(i=0;i<d;i++){
	    cin>>arr[i].second;
	}
	
	cin>>n;
	
	vector<pair<double,double>>result=fft(arr,d,n);
	cout<<std::fixed;
	for(i=0;i<n;i++){
	    if(abs(result[i].first)==0.00000){
	        cout<<"0.00000"<<" ";
	    }
	    else{
	        cout<<setprecision(5)<<result[i].first<<" ";
	    }
	}
	
	
	cout<<"\n";
	for(i=0;i<n;i++){
	    if(abs(result[i].second)==0.00000){
	        cout<<"0.00000"<<" ";
	    }
	    else{
	        cout<<setprecision(5)<<result[i].second<<" ";
	    }
	}
	
}



