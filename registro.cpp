#include <stdio.h>
#include <stdint.h>
#include "registro.h"

void red(reg*&vector, int &Actual, int Nuevo) {
    
    reg *New = new reg[Nuevo];   // Crear un nuevo vector con el nuevo tamaño
    
    for (int i = 0; i<Actual; ++i)    // Copiar los elementos del vector original al nuevo vector
    {
        New[i].id = vector[i].id;
        New[i].lower= vector[i].lower;
        New[i].type_NH= vector[i].type_NH;
        New[i].info= vector[i].info;
        New[i].type_NL= vector[i].type_NL;
        New[i].upper= vector[i].upper;
        int c=0;
        while (c != New[i].lower)
        {
            New[i].cadId[c]= vector[i].cadId[c];
            c++;
        }
    }
    delete[] vector;     // Liberar la memoria del vector original
    vector= New;      // Asignar el nuevo vector al puntero original
    Actual = Nuevo;    // Actualizar el tamaño actual
    
}

void Leer (FILE* f, reg*& vector, int Tam){
for (int i = 0; i < Tam; i++) {
    uint16_t header1;                                //Header 1
    fread(&header1, sizeof(uint16_t), 1, f);
    uint16_t id= header1 >> 6;     
     
    uint16_t lower = header1 << 10;  
    lower = lower >> 10;
    if (id >= Tam) {
        red(vector, Tam, id + 1); // Ajustar el índice al tamaño del nuevo vector
    }
    printf("id: %d\n", id);
    vector[id].id = id;
    vector[id].lower= lower;
    uint16_t header2;                               //Header 2
    fread(&header2, sizeof(uint16_t), 1, f);
    uint16_t type_NH = header2 >> 12;
    uint16_t info = header2 << 4;
    info = info >>8;
    uint16_t type_NL = header2 << 12;
    type_NH = type_NH >> 12;
    vector[id].type_NH = type_NH;
    vector[id].info = info;
    vector[id].type_NL = type_NL;
    uint16_t header3;                               //Header3
    fread(&header3, sizeof(uint16_t), 1, f);
    uint16_t upper = header3 << 3;
    upper = upper >>6;
    vector[id].upper = upper;
    if (lower != 0){
        vector[id].cadId = new uint16_t[lower] ;
        for (int i= 0; i<lower; i++){
        uint16_t LLD;
        fread(&LLD, sizeof(uint16_t), 1, f); 
        vector [id].cadId[i]= LLD;
        }
    }
}
printf("\nTamaño actual: %d\n", Tam);
for (int i = 1; i <= (Tam-1); i++) {
    printf("-----------\n");
    printf("Id: %d \n", vector[i].id);
    printf("Lower level devices count: %d \n", vector[i].lower);
    printf("Device type NH: %d \n", vector[i].type_NH);
    printf("Info: %d \n", vector[i].info);
    printf("Device type NL: %d \n", vector[i].type_NL);
    if (vector[i].upper != 1023){
        printf("Upper level Device ID: %d \n", vector[i].upper);
    }
    else{
        printf("Upper level Device ID: INVALIDO!\n");
    }       
    int c=0; 
    while ((vector[i].cadId[c])!=0){
        printf ("Lower level device: %d\n", vector[i].cadId[c]);
        c++;
    }
}
}

void B_iD (FILE* f, reg*& vcetor, int Tam)
{

}

