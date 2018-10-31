 #include<bits/stdc++.h>
#include<string>
#include<iostream>

using namespace std;

int precedence(char ope){
    if(ope=='+'||ope=='-')
    return 1;
    else if(ope=='*')
    return 2;
    else if(ope=='/'||ope=='%')
    return 3;
    else if(ope=='^')
    return 4;
    else if(ope=='~')
    return 5;
    else if(ope=='('||ope==')')
    return 0;
}

int main(){
    int t;
    scanf("%d\n",&t);
    
    while(t){
        char ch[80];
        char stack[100],bracketstack[80];
        int top=-1,i,invalid=0,brackettop=-1;
        
        
        scanf("%[^\n]\n",ch);
        
        for(i=0;ch[i]!='\0';i++){
            if(ch[i]=='('&&(ch[i+2]==')'||ch[i+2]=='^'||ch[i+2]=='%'||ch[i+2]=='/'||ch[i+2]=='*'||ch[i+2]=='+')){
                invalid=1;
                break;
            }
            
            else if((ch[i]>='0'&&ch[i]<='9')&&(ch[i+1]==' ')&&((ch[i+2]>='0'&&ch[i+2]<='9')||ch[i+2]=='(')){
                invalid=1;
                break;
            }
            
            else if((ch[i]=='^'||ch[i]=='%'||ch[i]=='/'||ch[i]=='*'||ch[i]=='+'||ch[i]=='-')&&(ch[i+2]=='^'||ch[i+2]=='%'||ch[i+2]=='/'||ch[i+2]=='*'||ch[i+2]=='+'||ch[i+2]=='-')){
                invalid=1;
                break;
            }
            
            else if(ch[i]=='('){
                brackettop=brackettop+1;
                bracketstack[brackettop]=ch[i];
            }
            
            else if(ch[i]==')'){
                brackettop=brackettop-1;
            }
        }
        
        if(brackettop!=-1)
        invalid=1;
        //cout<<invalid<<endl;
        if(invalid==1){
            cout<<"INVALID";
        }
        else{
            for(i=0;ch[i]!='\0';i++){
            
            if(ch[i]==' ')
            continue;
            
            else if((ch[i]>='0'&&ch[i]<='9')){
                while((ch[i]>='0'&&ch[i]<='9')){
                    cout<<ch[i];
                    i++;
                }
                cout<<" ";
                i=i-1;
            }
            
            else{
                if(ch[i]=='('){
                    top=top+1;
                    stack[top]=ch[i];
                }
                
                else if(ch[i]==')'){
                    while((top!=-1)&&(stack[top]!='(')){
                        if(stack[top]!='('){
                        cout<<stack[top]<<" ";    
                        }
                        
                        top=top-1;
                    }
                    top=top-1;
                }
                
                else{
                    while((top!=-1)&&(precedence(ch[i])<=precedence(stack[top]))&&(precedence(ch[i])!=4)){
                        cout<<stack[top]<<" ";
                        top=top-1;
                    }
                    top=top+1;
                    stack[top]=ch[i];
                }
                
            }
        }
        
        while(top!=-1){
            if(stack[top]!='('){
                cout<<stack[top]<<" ";    
            }
            top=top-1;
        }
        }
        
        cout<<endl;
        t--;
    }
    
    return 0;
}
