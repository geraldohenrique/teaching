#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <times.h>
#include <stdio.h>
#include <stdlib.h>

int main () {

int pid ; /* identificador de processo */
int tempo = 10;
char medir;
time_t horainicio;
struct tms tempodecpu;

medir = 'c';

pid = fork () ; /* replicação do processo */

if ( pid < 0 ) { /* se fork não funcionou */
	perror ("Erro: ") ;
	exit (-1) ; /* encerra o processo com código de erro -1 */
}
else if( pid > 0 ) /* se sou o processo pai*/
{
    horainicio = time(NULL);
    while (difftime (time(NULL), horainicio) < tempo) {
       printf("Child process user time = %fn",((double) tempodecpu.tms_cutime)/CLK_TCK);
       sleep (1);
    }

}
else /* senão, sou o processo filho*/
{
        if medir == 'c' {

            for (;;){

            }
        }
        if medir == 'm' {

            for (;;){
                 malloc(sizeof(100000));
            }
        }

}
perror ("Erro: ") ; /* execve não funcionou */

printf ("Tchau !\n") ;
exit(0) ; /* encerra o processo com sucesso (código 0) */

}
