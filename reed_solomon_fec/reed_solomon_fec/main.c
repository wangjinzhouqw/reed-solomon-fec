//
//  main.c
//  rsfec
//
//  Created by wangjz on 2018/5/7.
//

#include <stdio.h>
#include "rs.h"

#define K 10
#define N 15

int unit_test()
{
    int i;
    //    void *code=fec_new(10,15); // 不需要指定，内部会申请
    char arr[N][100]=
    {
        "origin 01","origin 02","origin 03","origin 04","origin 05",
        "origin 06","origin 07","origin 08","origin 09","origin 10",
        "origin 11","origin 12","origin 13","origin 14","origin 15",
    };
    char *data[N];
    for(i=0;i<N;i++)
    {
        data[i]=arr[i];
    }
    printf("--------origin data start------------\n");
    for(i=0;i<K;i++)
    {
        printf("<%s>\n",data[i]);
    }
    printf("--------origin data end------------\n");
    
    rs_encode2(K,N,data,9);
    printf("++++++++encoded data start++++++++++++\n");
    for(i=0;i<N;i++)
    {
        printf("<%s>\n",data[i]);
    }
    printf("++++++++encoded data end++++++++++++\n");
    
    
    printf("@@@@@@@@trans data start@@@@@@@@@@@@\n");
    data[0]=NULL;
    data[2]=NULL;
    data[10]=NULL;
    data[11]=NULL;
    data[14]=NULL;
    for(i=0;i<N;i++)
    {
        printf("<%s>\n",data[i]);
    }
    printf("@@@@@@@@trans data end@@@@@@@@@@@@@\n");
    
    int ret=rs_decode2(K,N,data,9);
    printf("ret:%d\n",ret);
    
    printf("########decoder data start##########\n");
    for(i=0;i<N;i++)
    {
        printf("<%s>\n",data[i]);
    }
    printf("########decoder data end##########\n");
    //    fec_free(code);
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unit_test();
    return 0;
}
