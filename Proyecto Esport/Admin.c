#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Admin.h"
#include "Torneo.h"
#include "Usuario.h"
#include "gestionvideojuegos.h"
#define DIM 30
#define dimINC 10

int existeEnAdmin(char nombreArchivo[], char usuario[])
{

    FILE* archivo=fopen(nombreArchivo, "rb");

    if(!archivo)
    {
        return 0;
    }
    Administrador temp;
    while(fread(&temp, sizeof(Administrador),1,archivo)==1)
    {
        if(strcmp(temp.usuario, usuario)==0)
        {
            fclose(archivo);
            return 1;
        }

    }

    fclose(archivo);

    return 0;

}

Administrador cargarAdministrador(char nombreArchivo[])
{
    int buscado=0;
    Administrador admin;
    printf("=============================\n");
    printf("REGISTRAR NUEVO ADMINISTRADOR\n");
    printf("=============================\n");

    do
    {
    printf("Usuario: ");
    fgets(admin.usuario,20,stdin);
    admin.usuario[strcspn(admin.usuario,"\n")]=0;

    buscado=existeEnAdmin(nombreArchivo,admin.usuario);

    if(buscado==1)
    {
        printf("[!]Ese nombre de usuario ya existe.Intente con otro.\n\n");
    }

    }while(buscado==1);

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


Administrador* redimensionarArregloAdmin(Administrador* arreglo,int* capacidad)
{
    int nuevaDim=(*capacidad)+dimINC;

    Administrador* temp=realloc(arreglo,nuevaDim*sizeof(Administrador));

    if(temp)
    {
        arreglo=temp;
        *capacidad=nuevaDim;
    }

    return arreglo;

}

Administrador* agregarAdministrador(Administrador** arreglo,int* validos, int* capacidad, char nombreArchivo[])
{
    if(*validos== *capacidad)
    {
        *arreglo=redimensionarArregloAdmin(*arreglo, capacidad);
    }

    (*arreglo)[(*validos)]=cargarAdministrador(nombreArchivo);
    (*validos)++;


    return *arreglo;
}

void cargarAdministradoresEnArchivo(char nombreArchivo[])
{
    int capacidad=DIM;
    Administrador* arreglo=crearArregloDinamicoAdmin(capacidad);
    int validos=0;
    char seguir='s';


    while(seguir=='s'||seguir=='S')
    {
        arreglo=agregarAdministrador(&arreglo,&validos,&capacidad,"administrador.bin");


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

void mostrarAdministradores(char nombreArchivo[])
{
    FILE* archivo=fopen(nombreArchivo,"rb");

    if(!archivo)
    {
        printf("\nNo se pudo abrir el archivo de administradores.\n");
        return;
    }
    Administrador temp;
    printf("\n-----------------------------------------------------------------\n");
    printf("%-15s | %-15s | %-25s\n", "USUARIO", "ROL", "NOMBRE COMPLETO");
    printf("-----------------------------------------------------------------\n");

    while (fread(&temp, sizeof(Administrador), 1, archivo) == 1)
    {
        printf("%-15s | %-15s | %-25s\n", temp.usuario, temp.rol, temp.nombreCompleto);
    }
    printf("-----------------------------------------------------------------\n");

    fclose(archivo);

}

void menuAdministrador(char nombreArchivo[])
{
    int opcion = -1;

    while (opcion != 0)
    {
        printf("\n--- PANEL DE ADMINISTRADOR ---\n");
        printf("1.Registrar nuevos administradores\n");
        printf("2.Ver listado de administradores\n");
        printf("0.Cerrar sesion\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch(opcion)
        {
        case 1:
            cargarAdministradoresEnArchivo("administradores.bin");
            break;

        case 2:
            mostrarAdministradores("administradores.bin");
            break;

        case 0:
            printf("Cerrando sesion de administrador...\n");
            break;

        default:
            printf("Opcion invalida.\n");
            break;
        }
    }

}

void submenuAdministradores(char nombreArchivo[])
{

    int opcion=-1;
    system("cls");
    do
    {

        printf("\n========================================\n");
        printf("        PANEL DE ADMINISTRADOR\n");
        printf("========================================\n");
        printf("1. Administrar Torneos\n");
        printf("2. Administrar Juegos\n");
        printf("3. Administrar Usuarios\n");
        printf("4. Administrar Administradores\n");
        printf("0. Cerrar sesion\n");
        printf("========================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        while(getchar()!='\n');

        switch(opcion)
        {
        case 1:
            sistemaTorneo();
            break;

        case 2:
            system("cls");
            administarJuegos();
            break;

        case 3:

            sistemaUsuario();
            break;

        case 4:

            menuAdministrador("administradores.bin");
            break;

        case 0:

            printf("Saliendo del sistema...\n");
            break;

        default:
            printf("Opcion invalida.\n");

            break;
        }

    }
    while(opcion!=0);
}

Administrador* crearArregloDinamicoAdmin(int capacidad)
{
    return (Administrador*)calloc(capacidad,sizeof(Administrador));
}
