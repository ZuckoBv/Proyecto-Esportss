#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLAVE "nexus"
#include "modelos.h"
#include "Login.h"
#include "Admin.h"
#include "usuario.h"
#include "Torneo.h"

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


    while(opcion != 0 && acceso == ACCESO_FALLIDO)
    {
        mostrarMenuAcceso();
        scanf("%d", &opcion);
        while(getchar()!='\n');

        switch(opcion)
        {
        case 1:
            system("cls");
            sistemaUsuario();
            break;

        case 2:

            /*FILE* temp=fopen("administradores.bin", "rb");

            if(!temp)
            {
                printf("\n[!] No hay administradores registrados.\n");
                cargarAdministradoresEnArchivo("administradores.bin");
            }

            else
            {
                fclose(temp);
            }
            */
            system("cls");
            printf("==========================\n");
            printf("  ERES UN ADMINISTRADOR?\n");
            printf("==========================\n");
            printf("Presione 0 para volver al menu.\n");


            printf("\nUsuario: ");
            fgets(usuario,20,stdin);
            usuario[strcspn(usuario,"\n")]=0;

            if (strcmp(usuario, "0") == 0)
            {
                printf("\nVolviendo al menu principal...\n");
                break;
            }

            printf("Contrasenia: ");
            fgets(contrasenia,20,stdin);
            contrasenia[strcspn(contrasenia,"\n")]=0;

            if(autenticarAdmin("administradores.bin", usuario,contrasenia)==1)
            {
                printf("Acceso concedido. Exito!\n");
                acceso=ACCESO_ADMIN;
                submenuAdministradores("administradores.bin");

            }

            else
            {
                printf("Usuario o clave invalidos.\n");
            }

            break;

        case 0:
            acceso=SALIR_SISTEMA;
            printf("\nSaliendo del sistema...\n");
            break;


        default:
            printf("\nOpcion invalida.\n");
            break;

        }

    }

    return acceso;
}
