#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
    int tempo;
    int id;
}valor;

void *espera(void *tmp){/* é o ponteiro para uma função de thread.
 	Esta função contém o segmento de código que é executad pela thread*/
	tmp = (valor *)tmp;
	valor *v = ( valor*) tmp;

		sleep(v->tempo);
		printf("OI sou a famosa Thread <%d> esperei %d segundos antes de executar\n",v->id, v->tempo);
	
};


int main(){
	pthread_t linhas[10];
	int execute;
	valor *v;

	for (int i = 0; i < 10; i++)
	{
		v = (valor *)malloc(sizeof(valor*));
		v->tempo = (rand()%10)+2;
		v->id = i;
		printf("Criei a thread <%d> com o tempo <%d>\n",i,v->tempo);
		execute = pthread_create(&linhas[i], NULL, espera, (void *) v); // NULL é o encadeamento padrão
		if (execute == 0){
			printf("Thread <%d> criada com sucesso\n",i);
		}else{printf("Erro na criação da thread <%d>\n",i );}
	}

	pthread_exit(NULL);
}
