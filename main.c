#include <stdio.h>
#include <stdlib.h>
#include "element.h"

Element new_Element(char message[]){
    Element element; 
    element.message = message;
    return element;
}

int print_Element(Element element){
    printf("%s\n", element.message);
    return 0; 
}

int main(int argn, char **argc){
    Element element;
    int x;

    // El argumento número cero [0] corresponde al nombre del programa
    if (argn > 1){
	element = new_Element(argc[1]);
	print_Element(element);
	
	// %s cadena de caracteres
	// printf("%s %i\n", argc[1], argn);
    }else{
	printf("We need more arguments!\n");
    }
    return 0; 
}

