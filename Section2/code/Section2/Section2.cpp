#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
#define MAXSIZE 5
typedef struct
{
    int *seat;  //���Σ���ţ�-��
    int length; //��ǰ��˾�ж��ٸ���

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

    for(int i =0;i<sqList.length;i++){ //������������
        if(sqList.seat[i] == e){ //�ҵ���
            locate = i;
            return locate; //��������ı��
        }
    }
    return locate; //����Ҳ����Ļ����ͷ���-1
}
int GetElem(SqList sqList,int i){

    return sqList.seat[i];

}
bool ListInsert(SqList &sqList,int i,int e){
    /*����һ���˵���i*/
    bool isSucceed = false; //��������Ϊfalse����������

    if(i<1 || i>sqList.length+1){  //���ȣ����Ǽ���i��λ���Ƿ�������Ŷ��У�������ɮ���ϴ�λ����0����������������ˣ�λ����4��
    //������������i<1 �ǲ�������0 ��-1 ֮��� ���Է���flase
    //������������i>L.length+1 ���� i = 7 ������С���壬 �������뵱��7 Ҳ�ǲ�����ģ� ����false
        return isSucceed;
    }

    if(sqList.length + 1 > MAXSIZE){ //���������������֮ǰ������������ �������� ����С�ܴ�Ҿ�û������ ���Է���false
        return isSucceed;
    }

    for(int j = sqList.length;j>=i;j--){ //���������˵��϶�����ô���� ɳɮ �˽䶼��������
        //����Ϊʲô�ǵ���
        sqList.seat[j+1] = sqList.seat[j];
    }

    sqList.seat[i-1] = e;  //��ѽ��ξ����ֵ������

    sqList.length++;  //��������1

    isSucceed = true; //����ɹ�~

    return isSucceed;

}
bool ListDelete(SqList &sqList, int i,int &e){
    /*����i�߳���˾*/
    bool isSucceed = false; //��������Ϊfalse����������

    if(i<1 || i>sqList.length+1){  //���ȣ����Ǽ���i��λ���Ƿ�������Ŷ��У�������ɮ���ϴ�λ����0����������������ˣ�λ����4��
    //������������i<1 �ǲ�������0 ��-1 ֮��� ���Է���flase
    //������������i>L.length+1 ���� i = 7 ������С���壬 ������7 Ҳ�ǲ�����ģ� ����false
        return isSucceed;
    }

    //��������Ϊʲô������Ƿ񳬳���˾�������������ListInsert��������

    e = sqList.seat[i-1]; //��e��������ˣ�����e����ʱ��Ϊʲô�ӵ�ַ

    for(int j = i;j<sqList.length;j++) //Ϊʲô������
    {
        sqList.seat[j-1] = sqList.seat[j]; //Ϊʲô��j-1,�����ϴ���ϴ��λ��֮��Ĺ�ϵ
    }
    sqList.length--; //����һ������������1

    isSucceed = true;
    return isSucceed;
}
void PrintList(SqList sqList){
    for(int i =0;i<sqList.length;i++){
        printf("%d ",sqList.seat[i]); //�Ӹ��ո��������۴󷽳�������
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
    free(sqList.seat); //���ﲻ��ֱ���ͷ�sqList,����ԭ��emmmmm��Ҳ�����ð�~
}

int main()
{
    SqList sqList;

    InitList(sqList);

    int length = Length(sqList);
    printf("��ǰ��˾������ %d\n",length);

    int n;//����ĿǰҪ���������
    printf("���������м����ˣ�\n");
    scanf("%d",&n); //��ɮʦͽһ��5��
    printf("�ֱ��ɶ��\n");
    int k = 1; //k������k��  k=1 ��ʾ �ϴ�
    for(int i= 0;i<n;i++){
        int name; //����ֱ����������̫���ӣ�������10��ʾ��ɮ�����֣��Դ�����
        scanf("%d",&name);
        ListInsert(sqList,k,name);
        k++;
    }
    printf("���һ�½��\n");
    PrintList(sqList);

    int e,i;
    printf("���뿪���ϼ���\n");
    scanf("%d",&i);
    ListDelete(sqList,i,e);

    printf("ɾ�������ǣ�%d\n",e);
    printf("���һ�½��\n");
    PrintList(sqList);


    printf("�����˾�����ˣ�");
    DestroyList(sqList);


    printf("���һ�½��\n");
    PrintList(sqList);





    return 0;
}
