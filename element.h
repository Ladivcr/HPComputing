#ifndef ELEMENT_H
#define ELEMENT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  typedef struct{
    char message[128]; // [x,y,z] m/s
  }Element;

  Element new_Element(char message[128], int miproc);
  int print_Element(Element element);

  int get_string(Element element, char *message);
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ELEMENT_H */

