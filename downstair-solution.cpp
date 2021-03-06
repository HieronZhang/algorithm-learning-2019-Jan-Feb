//下台阶问题：共h级台阶，每步可下1、2、3步，求输出所有解决方案。

#include <iostream>
using namespace std;

int num=0;
int take[1000];
int Try(int i,int s){  //s为当前步数,i为剩余阶数
    for(int j=3;j>0;j--){
        if(i>=j){
            take[s]=j;
            if(i==j){
                for(int k=1;k<=s;k++){
                    cout<<take[k]<<" ";
                }
                cout<<endl;
                num++;
            }
            else
                Try(i-j,s+1);
        }
    }
    return num;
}

int Count(int x){
    if(x==1)
        return 1;
    else if(x==2)
        return 2;
    else if(x==3)
        return 4;
    else
        return Count(x-1)+Count(x-2)+Count(x-3);
}

int main() {
    int h;
    cout<<"Input'h'";
    cin>>h;
    int out=Try(h,1);
    cout<<"The number is "<<out<<endl;
    int out2=Count(h);
    cout<<"The nummber is "<<out2<<endl;
    return 0;
}