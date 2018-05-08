#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _tl(char* in){
    int i;
    for(i=0;i<strlen(in);i++){
        if(in[i]<='Z' && in[i]>='A'){
            in[i] -= 'Z'-'z';
        }
    }
    return;
}

struct _n{
    char *tok;
    int  cnt;
    struct _n *nxt;
};
void h_insert(char *in, struct _n **h){
    int i;
    int key;
    char *buf;
    struct _n *pos, *tmp;
    for(i=0; i<strlen(in); i++){
        key += in[i];
        key %=1000;
    }
    if(h[key] == NULL){
        h[key]=malloc(sizeof(struct _n));
        pos = h[key];
        pos->tok=malloc(sizeof(char)*(strlen(in)+1));
        strcpy(pos->tok, in); 
        pos->cnt = 1;
        pos->nxt = NULL;
        //printf("hi1[%d][%s]%d\n",key, pos->tok, pos->cnt);
    }else{
        pos = h[key];
        while(0!=strcmp(pos->tok,in)){
            if(pos->nxt !=NULL){
                pos = pos->nxt;
            }else{
                pos->nxt = malloc(sizeof(struct _n));
                pos = pos->nxt;
                pos->cnt=0;
                pos->tok=malloc(sizeof(char)*(strlen(in)+1));
                strcpy(pos->tok, in); 
                pos->nxt = NULL;
            }
        }
        pos->cnt++;
        //printf("hi2[%d][%s]%d\n",key, pos->tok, pos->cnt);
    }
}
void h_del(char *in, struct _n **h){
    int i;
    int key;
    char *buf;
    struct _n *pos;
    for(i=0; i<strlen(in); i++){
        key += in[i];
        key %=1000;
    }
    pos = h[key];
    while(NULL!=pos && NULL!=pos->tok && 
            0!=strcmp(pos->tok,in)){
        pos = pos->nxt;
    }
    if(pos!=NULL){
        if(pos->tok!=NULL){
            //printf("h_d[%d][%s]%d\n",key, pos->tok, pos->cnt);
            pos->cnt=0;
        }
    }
}
char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char *ret = malloc(sizeof(char)*1000);
    char *tok = NULL;
    struct _n *hash[1000];
    int i;
    int max=0;
    struct _n *pos;

    memset(ret, 0, sizeof(char)*1000);
    //memset(hash, 0, sizeof(struct _n *)*1000);
    for(i=0; i<1000; i++){
        hash[i] = NULL;
    }

    _tl(paragraph);
    tok = strtok(paragraph, "!?',;. ");

    while(tok != NULL){
        //printf("[%d]%s, \n", tok, tok);
        h_insert(tok, &hash[0]);
        tok = strtok(NULL,  "!?',;. ");
    }

    for(i=0; i<bannedSize; i++){
        h_del(banned[i], hash);
    }

    for(i=0; i<1000; i++){
        pos = hash[i];
        while(pos!=NULL){
            //printf("(%d,%s)", pos->cnt, pos->tok);
            if(pos->cnt > max){
                max = pos->cnt;
                strcpy(ret, pos->tok);
            }
            pos=pos->nxt;
        }
    }

    return ret;
}

char p[] = "Bob hit a ball, the hit BALL flew far after it was hit.";
char *b[] = {"hit"};
int main(){
    char * ret;

    ret = mostCommonWord(p, b, 1);
    printf("%s \n", ret);
    
    free(ret);
    return 0;
}
