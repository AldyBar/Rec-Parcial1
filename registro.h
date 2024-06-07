#include <stdio.h>
#include <stdint.h>

struct reg
{
    uint16_t id;
    uint16_t lower;
    uint16_t type_NH;
    uint16_t info;
    uint16_t type_NL;
    uint16_t upper;
    uint16_t *cadId;
};

void red (reg*&vector, int &Actual, int Nuevo);

void Leer (FILE* f, reg*& vector, int Tam);

void B_id (FILE* f, reg*& vcetor, int Tam);



