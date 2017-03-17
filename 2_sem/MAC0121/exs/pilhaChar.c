typedef struct {

        char *v;
        int max;
        int topo;
} pilha;

pilha *criaPilha(int max){

        pilha *p;
        p = malloc(sizeof(pilha));
        p->v = malloc(max*sizeof(char));

        p->max = max;
        p->topo = 0;

        return p;
}

int pilhaVazia(pilha p){
        return p.topo == 0;
}

void realocaPilha(pilha *p){

        int novoMax = 1.2*p->max;
        
        int i;
        char *w;

        w = malloc(sizeof(char)*novoMax);
        for (i = 0; i < p-> max; p++)
                w[i] = p->v[i];

        p->max = novoMax;
        p->v = w;
        free(p->v);

}

void empilha(pilha *p, char x){

        if (p->topo == p->max)
                realocaPilha(p);

        p->v[p->topo] = x;
        (p->topo)++;

}

char desempilha(pilha *p){

        if (pilhaVazia(*p)) {
                printf("erro\n");
        }

        char x;
        x = p->v[--(p->topo)];

        return x;
}