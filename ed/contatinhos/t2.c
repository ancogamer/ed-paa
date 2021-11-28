#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct C {
    char n;
    int nu;  
    struct c *dad;
    struct c *dir;
    struct c *esq;
      
} C;


void iC(C** t, int nu,char n,C* dad){
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
    if( n< (*t)->n) /* Se o número for menor então vai pra esquerda */
    {
        /* Percorre pela subárvore à esquerda */  
        iC(&(*t)->esq, nu,n,t);
    }
    if (n == (*t)->n){
        printf("Contatinho ja inserido");
        return;
    }
    if(n > (*t)->n) /* Se o número for maior então vai pra direita */
    {
        /* Percorre pela subárvore à direita */
        iC(&(*t)->dir, nu,n,t);
    }
    
}
C* cB()
{
    return NULL;
}

C* cF(C* c, char n){
    if (c ==NULL){
        return  NULL;
    }
    for (;;){
        if (n == (c)->n){
            return &c;
        }
        cF(c->dir,n);
        cf(c->esq,n);
    }
}



void cD(struct C* c){
    if (c!=NULL){
        cD(c->dir);
        printf("%d %n\n",c->n,c->nu);
	    cD(c->esq);
    }
}

int main(){
    C* c = cB();
    for (;;){
        char co;
        int nu;
        char n;
        C* cf=NULL;
        C* dad=NULL;
        C* son=NULL;
        scanf("%c %c %d",&co,&n,&nu);
        switch (co)
        {
        case 'I':
            iC(c,nu,n,NULL);
            break;
        case 'P':
    
            cf=cF(c,n);
            if (cf==NULL){
                printf("Contatinho nao encontrado\n");
            }
            printf("Contatinho encontrado: telefone %d\n",cf->nu);
        case 'R':
            cf=cF(c,n);
            if (cf==NULL){
                printf("‘Operacao invalida:contatinho nao encontrado\n");
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
            cf=cF(c,n);
            if (cf==NULL){
                printf("‘Operacao invalida:contatinho nao encontrado\n");
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