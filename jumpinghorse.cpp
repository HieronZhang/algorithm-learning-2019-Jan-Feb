//跳马问题：半张中国象棋棋盘（4*8），马从左下角跳到右上角，只允许向右跳，求总方案数
#include <iostream>
using namespace std;

const int TARGETX=8;
const int TARGETY=4;
int num;
int path[10][2];
int dx[]={0,1,2,2,1};
int dy[]={0,2,1,-1,-2};
int myk[10];

void jump(int x,int y,int step){
    for(int k=1;k<=4;k++){
        int x1=x+dx[k];
        int y1=y+dy[k];
        bool t1=(x1>=0)&&(x1<=TARGETX);
        bool t2=(y1>=0)&&(y1<=TARGETY);
        bool t3=(x1>=TARGETX)&&(y1!=TARGETY);
        bool t4=(x1==TARGETX)&&(y1==TARGETY);
        if(t1&&t2&&!t3){
            path[step][0]=x1;
            path[step][1]=y1;
            myk[step]=k;
            if(t4){
                num++;
                cout<<"solution"<<num<<":\n";
                for(int i=0;i<=step;i++){
                    cout<<"("<<path[i][0]<<","<<path[i][1]<<")\n";
                }
            }
            else
                jump(x1,y1,step+1);
        }
    }
}
int main() {
    num=0;
    jump(0,0,1);
    cout<<"Total solutions number:"<<num<<endl;
    return 0;
}