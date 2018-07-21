#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
#define MAXSIZE 5
typedef struct
{
    int *seat;  //交椅（编号）-人
    int length; //当前公司有多少个人

}SqList;

void InitList(SqList &sqList){

   sqList.seat = (int *)malloc(sizeof(int)*MAXSIZE);

   sqList.length = 0;
}
int Length(SqList sqList){

    return sqList.length;
}
int LocateElem(SqList sqList,int e){
    int locate = -1;

    for(int i =0;i<sqList.length;i++){ //我们在找马马
        if(sqList.seat[i] == e){ //找到了
            locate = i;
            return locate; //返回马马的编号
        }
    }
    return locate; //如果找不到的话，就返回-1
}
int GetElem(SqList sqList,int i){

    return sqList.seat[i];

}
bool ListInsert(SqList &sqList,int i,int e){
    /*加入一个人当老i*/
    bool isSucceed = false; //先让它置为false，基本操作

    if(i<1 || i>sqList.length+1){  //首先，我们检查第i个位置是否在这个团队中，比如唐僧是老大（位置是0），马马是老五个人（位置是4）
    //如果我们输入的i<1 是不存在老0 老-1 之类的 所以返回flase
    //如果我们输入的i>L.length+1 比如 i = 7 现在最小老五， 来个人想当老7 也是不合理的， 返回false
        return isSucceed;
    }

    if(sqList.length + 1 > MAXSIZE){ //如果队伍人数超过之前申请的最大人数 队伍满啦 再来小弟大家就没饭吃了 所以返回false
        return isSucceed;
    }

    for(int j = sqList.length;j>=i;j--){ //比如来个人当老二，那么马马 沙僧 八戒都得往后排
        //想想为什么是倒序
        sqList.seat[j+1] = sqList.seat[j];
    }

    sqList.seat[i-1] = e;  //这把交椅就是兄弟你的了

    sqList.length++;  //总人数加1

    isSucceed = true; //插入成功~

    return isSucceed;

}
bool ListDelete(SqList &sqList, int i,int &e){
    /*把老i踢出公司*/
    bool isSucceed = false; //先让它置为false，基本操作

    if(i<1 || i>sqList.length+1){  //首先，我们检查第i个位置是否在这个团队中，比如唐僧是老大（位置是0），马马是老五个人（位置是4）
    //如果我们输入的i<1 是不存在老0 老-1 之类的 所以返回flase
    //如果我们输入的i>L.length+1 比如 i = 7 现在最小老五， 想踢老7 也是不合理的， 返回false
        return isSucceed;
    }

    //想想这里为什么不检查是否超出公司最大人数，但在ListInsert里面检查了

    e = sqList.seat[i-1]; //用e返回这个人，想想e传参时候为什么加地址

    for(int j = i;j<sqList.length;j++) //为什么是正序
    {
        sqList.seat[j-1] = sqList.seat[j]; //为什么是j-1,想想老大和老大的位置之间的关系
    }
    sqList.length--; //走了一个，总人数减1

    isSucceed = true;
    return isSucceed;
}
void PrintList(SqList sqList){
    for(int i =0;i<sqList.length;i++){
        printf("%d ",sqList.seat[i]); //加个空格优雅美观大方楚楚动人
    }
    printf("\n");
}
bool Empty(SqList sqList){
    if(sqList.length == 0)
        return true;
    else
        return false;
}
void DestroyList(SqList &sqList){
    sqList.length = 0;
    free(sqList.seat); //这里不能直接释放sqList,至于原因emmmmm我也不晓得哎~
}

int main()
{
    SqList sqList;

    InitList(sqList);

    int length = Length(sqList);
    printf("当前公司人数： %d\n",length);

    int n;//我们目前要加入的人数
    printf("你们现在有几个人？\n");
    scanf("%d",&n); //唐僧师徒一共5人
    printf("分别叫啥？\n");
    int k = 1; //k代表老k，  k=1 表示 老大
    for(int i= 0;i<n;i++){
        int name; //由于直接输入名字太复杂，我们用10表示唐僧的名字，以此类推
        scanf("%d",&name);
        ListInsert(sqList,k,name);
        k++;
    }
    printf("输出一下结果\n");
    PrintList(sqList);

    int e,i;
    printf("你想开除老几？\n");
    scanf("%d",&i);
    ListDelete(sqList,i,e);

    printf("删除的人是：%d\n",e);
    printf("输出一下结果\n");
    PrintList(sqList);


    printf("这个公司倒闭了！");
    DestroyList(sqList);


    printf("输出一下结果\n");
    PrintList(sqList);





    return 0;
}
