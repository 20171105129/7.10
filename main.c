#include<stdlib.h>
#include<stdio.h>
struct student
{
    int numbers;//学号
    char name[10];//姓名
    char sex[10];//性别
    int dateofbirth;//出生日期
    char class1[15];//班级
    char phoneNo[15];//电话号码
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;//平均值
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;//读入
    int i=0,j;
    char header[100];
    fp1 =fopen("/Users/s20171105129/Desktop/student2.csv","r");//读取文件
    if(fp1==NULL)
    {
        printf("文件打开失败\n");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%s",header);//把表头读入
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,s[i].name,s[i].sex,&s[i].dateofbirth,s[i].class1,
                   s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirth,s[i].class1,s[i].phoneNo,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }//循环
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }//计算最大值
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }//计算最小值
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }//计算平均值
    j=i;
    i=0;
    
    fp2=fopen("student2.csv","w");
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,score\n");
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",
                s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirth,s[i].class1,
                s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
        i++;
    }//输出表格
    fclose(fp2);
    return 0;
}
