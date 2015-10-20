#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[1], char *envp[]) {

int pid; /* identificador de processo */
int tempo = 10, nCPU, i, j;
long memoriausada;
time_t horainicio, inicio, fim;
struct sysinfo memoria;
struct timeval comeco,final;


pid = fork () ; /* replicação do processo */

if ( pid < 0 ) { /* se fork não funcionou */
	perror ("Erro: ") ;
	exit (-1) ; /* encerra o processo com código de erro -1 */
}
else if( pid > 0 ) /* se sou o processo pai*/
{
    for (j=0;j<10;j++){ /* Timer para medição dos recursos a cada 1 segundo durante 10 segundos */
         horainicio = time(NULL);
         inicio = clock ();
	 while (difftime (time(NULL), horainicio) < 1) { /* controle de 1 sengundo*/
               memoriausada = (memoriausada + (memoria.totalram-memoria.freeram)); 
               fim = clock();
               gettimeofday (&final,NULL);
      	 }
         nCPU = sysconf(_SC_NPROCESSORS_ONLN);
         printf("Uso da CPU = %.f%%\n",((((double) (fim-inicio))/nCPU)/1000)); /*calcula o uso da CPU*/
     	 printf("Uso da Memória = %lu\n",memoriausada/1048); /*calcula o uso da memória*/
    }
    kill (0,SIGKILL);

}
else /* senão, sou o processo filho*/
{
        if (strcmp(argv[1],"cpu") == 0) {

            for (;;){
              
            }
        }
        if (strcmp(argv[1],"mem-cpu")== 0) {
																																																																									
            for (;;){
                 malloc(sizeof(100000));
            }
        }

}
perror ("Erro: ") ; /* execve não funcionou */
printf ("Tchau !\n") ;
exit(0) ; /* encerra o processo com sucesso (código 0) */
}
