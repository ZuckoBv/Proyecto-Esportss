#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLAVE "nexus"
#include "modelos.h"
#include "Login.h"
#include "Admin.h"


void mostrarMenuAcceso()
{
    printf("\n========================================");
    printf("\n             NEXUS ARENA");
    printf("\n========================================");
    printf("\n  [1]  Iniciar sesion como usuario.\n");
    printf("\n  [2]  Iniciar sesion como administrador.\n");
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

    inicializarAdminsPorDefecto("administradores.bin");

    while(opcion != 0 && acceso == ACCESO_FALLIDO)
    {
        mostrarMenuAcceso();
        scanf("%d", &opcion);
        while(getchar()!='\n');

        switch(opcion)
        {
        case 1:
            printf("Sistema Usuario.");
            break;

        case 2:
            printf("===================\n");
            printf("    ACCESO ADMIN\n");
            printf("===================\n");
            printf("\nUsuario: ");
            fgets(usuario,20,stdin);
            usuario[strcspn(usuario,"\n")]=0;

            printf("Contrasenia: ");
            fgets(contrasenia,20,stdin);
            contrasenia[strcspn(contrasenia,"\n")]=0;

            if(autenticarAdmin("administradores.bin", usuario,contrasenia)==1)
            {
                printf("Acceso concedido. Exito!\n");
                acceso=ACCESO_ADMIN;
            }

            else
            {
                printf("Usuario o clave invalidos.\n");
            }
            break;

        case 0:
            printf("\nSaliendo del sistema...\n");
            break;

        default:
            printf("\nOpcion invalida.\n");
            break;

        }
    }

    return acceso;
}
