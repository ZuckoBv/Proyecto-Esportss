#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Admin.h"

int DIM=30;
int dimINC=10;

Administrador cargarAdministrador()
{
    Administrador admin;
    printf("Usuario: ");
    fgets(admin.usuario,20,stdin);
    admin.usuario[strcspn(admin.usuario,"\n")]=0;

    printf("Contrasenia: ");
    fgets(admin.contrasenia,20,stdin);
    admin.contrasenia[strcspn(admin.contrasenia,"\n")]=0;

    printf("Nombre completo: ");
    fgets(admin.nombreCompleto,50,stdin);
    admin.nombreCompleto[strcspn(admin.nombreCompleto,"\n")]=0;

    printf("Rol: ");
    fgets(admin.rol,20,stdin);
    admin.rol[strcspn(admin.rol,"\n")]=0;


    return admin;

}
int guardarAdministradoresEnArchivo(char nombreArchivo[], Administrador arreglo[], int validos)
{
    FILE* archivo=fopen(nombreArchivo,"ab");

    if(!archivo)
    {
        return 0;
    }

    for(int i=0; i<validos; i++)
    {
        fwrite(&arreglo[i],sizeof(Administrador),1,archivo);
    }

    fclose(archivo);

    return 1;
}


Administrador* redimensionarArreglo(Administrador* arreglo,int validos)
{
    int nuevaDim=DIM+dimINC;

    Administrador* temp=realloc(arreglo,nuevaDim*sizeof(Administrador));

    if(temp)
    {
        arreglo=temp;
        DIM=nuevaDim;
    }


    return arreglo;

}

Administrador* agregarAdministrador(Administrador arreglo[],int validos)
{
    if(validos==DIM)
    {
        arreglo=redimensionarArreglo(arreglo,validos);
    }

    arreglo[validos]=cargarAdministrador();


    return arreglo;
}

void cargarAdministradoresEnArchivo(char nombreArchivo[])
{
    Administrador* arreglo=calloc(DIM,sizeof(Administrador));
    int validos=0;
    char seguir='s';

    while(seguir=='s'||seguir=='S')
    {
        arreglo=agregarAdministrador(arreglo,validos);
        validos++;

        printf("Desea seguir cargando admins? s/n\n");
        scanf(" %c", &seguir);
        while(getchar()!='\n');
    }

    guardarAdministradoresEnArchivo(nombreArchivo,arreglo,validos);
    free(arreglo);
}

int autenticarAdmin(char nombreArchivo[], char usuario[], char contrasenia[])
{
    int buscado=0;

    FILE* archivo=fopen(nombreArchivo,"rb");

    if(!archivo)
    {
        return 0;
    }
    Administrador temp;

    while(fread(&temp,sizeof(Administrador),1,archivo) && buscado==0)
{
    if(strcmp(temp.usuario,usuario)==0 && strcmp(temp.contrasenia,contrasenia)==0)
        {
            buscado=1;
        }
    }

    fclose(archivo);

    return buscado;
}
