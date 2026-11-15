#include <stdio.h>
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

void guardarAdministradorEnArchivo(char nombreArchivo[])
{
    Administrador admin;
    char seguir='s';
    FILE* archivo=fopen(nombreArchivo,"ab");

    if(!archivo)
    {
        printf("El archivo fallo.\n");
        return;
    }


    }

    fclose(archivo);

}

int cargarAdministradorEnArreglo(Administrador admin[], int validos)
{
    char seguir='s';

     while(seguir=='s'||seguir=='S'))&& validos<DIM)
    {
       admin[validos]=cargarAdministrador();
       validos++;

       if(validos==DIM)
       {
          admin=redimensionarArreglo();
          printf("Tamanio redimensionado con exito!");
       }


        printf("Desea seguir cargando admins? s/n\n");
        scanf(" %c", &seguir);
        while(getchar()!='\n');

    }


    return validos;
}

int cargarAdministradorEnArreglo(char nombreArchivo[],Administrador* arreglo,int validos)
{
    FILE* archivo=fopen(nombreArchivo,"rb");

    if(!archivo)
    {
        printf("No se pudo abrir.\n");
        return 0;
    }
    Administrador temp;
    while(fread(&arreglo[validos],sizeof(Administrador),1,archivo)==1)
    {

    }


    fclose(archivo);
    return validos;
}
