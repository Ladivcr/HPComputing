/*
 *
 *
 *
 *
 *
 * 
 *
 *
 */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "element.h"

int main(int argn, char **args){
    Element element;
    int x;
    int miproc;
    int numproc;
    int i; 
    char message[128];
    MPI_Status status;



    // El argumento número cero [0] corresponde al nombre del programa
    if (argn > 1){
	MPI_Init (&argn, &args); //Inicializar MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD,&miproc); /*determina el rango 
						del proceso invocado*/
	MPI_Comm_size(MPI_COMM_WORLD, &numproc); /*Determina el
						numero de procesos*/

	MPI_Barrier (MPI_COMM_WORLD);
	
	//nikos khazastakis	
	if (miproc == 0){
	    printf("I am the master!\n");
	    
	    for (i=1; i < numproc; i++){
		//status es para saber si si llegaron o 
		//no los mensajes
		MPI_Recv(message, 128, MPI_CHAR, i, 99,
		    MPI_COMM_WORLD, &status);
		printf("%s\n", message);
	    }

	}else{
	    //slaves
	    element = new_Element(args[1], miproc);
	    //print_Element(element);
	    get_string(element, message);

	    //se lo mandaremos al proceso cero = destiono
	    //99 solo es un tag, cualquier número como control
	    //128 son los bits que se mandaran 
	    //MPI_CHAR es el tipo de dato
	    MPI_Send(message, 128, MPI_CHAR, 0, 99, MPI_COMM_WORLD);
	}

	MPI_Barrier (MPI_COMM_WORLD);
	MPI_Finalize(); //Finalizar MPI
	
	// %s cadena de caracteres
	// printf("%s %i\n", argc[1], argn);
    }else{
	printf("We need more arguments!\n");
    }
    return 0; 
}

