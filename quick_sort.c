#if 0
quick sort, bubble sort, merge sort
1,2,3,4,5,6,6
6,6,5,4,3,2,1
1,2,3,6,4,5,6
1,2,3,4,6,6,5
2,1,3,4,5,6,6
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int* in, int sz){
    int i;
    for(i=0; i<sz; i++){
        printf("%d, ", in[i]);
    }
    printf("\n");
    return;
}

void _swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return;
}
int _partition(int *in, int s, int e){
    int pvt_val = in[e];
    int le = s-1;
    int gt = s;

    for(;gt<e;gt++){
        if(in[gt] <= pvt_val){
            le++;
            _swap(&in[le], &in[gt]);
        }
    }
    le++;
    _swap(&in[le], &in[e]);

    return le;
}


void _qs(int *in, int s, int e){
    int pvt;

    if (s<e){
        pvt = _partition(in, s, e);
        _qs(in, s, pvt-1);
        _qs(in, pvt+1, e);
    }
}

void q_sort(int *in, int sz){
    _qs(in, 0, sz-1);
    return;
}

#define SZ 7

int main(){
    int t0[]={1,2,3,4,5,6,6};
    int t1[]={1,6,5,4,3,2,6};
    int t2[]={1,2,3,6,4,5,6};
    int t3[]={1,2,3,4,6,6,5};
    int t4[]={2,1,3,4,5,6,6};
    int test[7];

    memcpy(test, t0, sizeof(int)*SZ);
    print_arr(test, SZ); 
    q_sort(test, SZ);
    print_arr(test, SZ); printf("\n");

    memcpy(test, t1, sizeof(int)*SZ);
    print_arr(test, SZ); 
    q_sort(test, SZ);
    print_arr(test, SZ); printf("\n");
    
    memcpy(test, t2, sizeof(int)*SZ);
    print_arr(test, SZ); 
    q_sort(test, SZ);
    print_arr(test, SZ); printf("\n");

    memcpy(test, t3, sizeof(int)*SZ);
    print_arr(test, SZ); 
    q_sort(test, SZ);
    print_arr(test, SZ); printf("\n");

    memcpy(test, t4, sizeof(int)*SZ);
    print_arr(test, SZ); 
    q_sort(test, SZ);
    print_arr(test, SZ); printf("\n");

    return 0;
}


#if 0
#define COL 5
#define ROW 7
int main(){
    int ** t_set;
    int i, j, k;
    t_set = (int**)malloc(sizeof(int*)*COL);
    t_set[0] = (int*)malloc(sizeof(int*)*COL*ROW);

    for(i=0; i<COL; i++){
        t_set[i] = t_set[0]+i*ROW;
    }

    k = 0;
    for(i=0; i<COL; i++){
        for(j=0; j<ROW; j++){
            t_set[i][j] = k++;
        }
    }


    for(i=0; i<COL; i++){
        for(j=0; j<ROW; j++){
            printf("%d,",t_set[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    free(t_set[0]);
    free(t_set);

    return 0;
}
#endif
