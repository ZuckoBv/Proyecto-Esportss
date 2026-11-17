#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLAVE "nexus"
#include "modelos.h"
#include "Login.h"
#include "Admin.h"


//PROTOTIPADOS-------------------------------------------------
int loginOperador();
//-------------------------------------------------------------

void mostrarMenuAcceso()
{
    printf("\n========================================");
    printf("\n             NEXUS ARENA");
    printf("\n========================================");
    printf("\n  [1]  Ingresar");
    printf("\n  [2]  Crear cuenta");
    printf("\n  [3]  Iniciar sesion como administrador");
    printf("\n  [0]  Salir");
    printf("\n========================================");
    printf("\n  Seleccione una opcion: ");
}

int login()
{
    char usuario[20];
    char contrasenia[20];

    int opcion = -1;
    int acceso = ACCESO_FALLIDO;

    while(opcion != 0 && acceso == ACCESO_FALLIDO)
    {
        mostrarMenuAcceso();
        scanf("%d", &opcion);
        while(getchar()!='\n');

        switch(opcion)
        {
        case 1:
            printf("\nIngresar: pendiente.\n");
            break;
        case 2:
            printf("\nCrear cuenta: pendiente.\n");
            break;
        case 3:
            printf("===================\n");
            printf("    BIENVENIDO\n");
            printf("===================\n");
            printf("\nUsuario: ");
            fgets(usuario,20,stdin);
            usuario[strcspn(usuario,"\n")]=0;

            printf("Contrasenia: ");
            fgets(contrasenia,20,stdin);
            contrasenia[strcspn(contrasenia,"\n")]=0;

            if(autenticarAdmin("administradores.bin", usuario,contrasenia)==1)
            {
               acceso=ACCESO_ADMIN;
            }

            else
            {
                printf("Contrasenia invalida.\n");
            }
             break;

        }
    }

    return acceso;
}
