#include <stdio.h>
#include <stdint.h>
#include "registro.h"
//#include "red.h"

int main() {
    FILE *f = fopen("network_structure.dat", "rb");
    if (!f) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    reg *v;
    int TI= 1;
    v= new reg [TI]; //Asigno memoria dinamica a la estructura.
    Leer (f, v, TI);
    B_id (f, v, TI);
    delete []v;
    fclose(f);
}