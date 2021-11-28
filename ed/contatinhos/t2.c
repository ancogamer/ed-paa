#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h> 


typedef struct C {
    char* n;
    int nu;  
    struct C* dad;
    struct C* dir;
    struct C* esq;
      
} C;


void iC(C** t, int nu,char* n,C* dad){
    if(*t == NULL)
    {
        *t = (struct C *) malloc(sizeof(C));
        (*t)->esq = NULL; 
        (*t)->dir = NULL; 
        (*t)-> nu= nu;
        (*t)->n = n; 
        (*t)->dad = dad; 
        return; 
    }
    
    if(strcmp(n, (*t)->n) == -1){
        iC(&(*t)->esq, nu,n,*t);
    }
    
    if (strcmp(n, (*t)->n) == 0){
        printf("Contatinho ja inserido\n");
        return;
    }
    if(strcmp(n, (*t)->n) == 1){
        iC(&(*t)->dir, nu,n,*t);
    }
    
}
C* cB()
{
    return NULL;
}

C* cF(C* c, char* n){
    if (c ==NULL){
        return  NULL;
    }
    for (;;){
            
        if (strcmp(n, c->n) == 0){
            return c;
        }
        cF(c->dir,n);
        cF(c->esq,n);
    }
}



void cD(struct C* c){
    if (c!=NULL){
        cD(c->dir);
        printf("%s %d\n",c->n,c->nu);
	    cD(c->esq);
    }
}

int main(){
    C* c = cB();
    char co;
    int nu;
    char na[10];
    C* cf=NULL;
    C* dad=NULL;
    C* son=NULL;
    for (;;){
        scanf("%c ",&co);
        switch (co)
        {
        case 'I':
            scanf("%s %d",na,&nu);
            iC(&c,nu,na,NULL);
            break;
        case 'P':
            scanf("%c ",na);
            cf=cF(c,na);
            if (cf==NULL){
                printf("Contatinho nao encontrado\n");
                continue;
            }
            printf("Contatinho encontrado: telefone %d\n",cf->nu);

        case 'R':
            scanf("%c ",na);
            cf=cF(c,na);
            if (cf==NULL){
                printf("Operacao invalida:contatinho nao encontrado\n");
                continue;
            }
            if ((cf->esq==NULL)&&(cf->dir==NULL)){
                free(cf);
                continue;
            }
            if (cf->esq==NULL){
                dad= cf->dad;
                if (dad->dir==cf){
                    son=cf->dir;
                    son->dad=dad;
                    dad->dir = cf->dir;
                }
                if (dad->esq==cf){
                    son=cf->esq;
                    son->dad=dad;
                    dad->esq = cf->dir;
                }
                free(cf);
                continue;
            }
            if (cf->dir==NULL){
                C* dad=NULL;
                dad= cf->dad;
                C* son=NULL;
                if (dad->dir==cf){
                    son=cf->dir;
                    son->dad=dad;
                    dad->dir = cf->dir;
                }
                if (dad->esq==cf){
                    son=cf->esq;
                    son->dad=dad;
                    dad->esq = cf->dir;
                }
                free(cf);
                continue;
            }
            break;
        case 'A':
            scanf("%c ",na);
            cf=cF(c,na);
            if (cf==NULL){
                printf("Operacao invalida:contatinho nao encontrado\n");
                continue;
            }
            cf->nu=nu;
            break;
        case 'D':
            cD(c);
            break;
        case '0':
            free(c);
             break;
            break;
        }
        free(cf);
    }
   

	return 0;
} 