#include <stdio.h>
#include <stdlib.h>
#include "element.h"

Element new_Element(char message[128], int miproc){
  Element element;
  sprintf(element.message, "Process %i: %s %i", miproc, message,
	  miproc*miproc);
  //element.message = message;
  return element;
}

int print_Element(Element element){
  printf("%s\n",element.message);
  return 0;
}

int get_string(Element element, char *message){
    
    sprintf(message, "%s", element.message);
    return 0;
}
