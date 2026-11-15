#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLAVE "nexus"
#include "modelos.h"
#include "Login.h"


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
    int opcion = -1;
    int acceso = ACCESO_FALLIDO;

    while(opcion != 0 && acceso == ACCESO_FALLIDO)
    {
        mostrarMenuAcceso();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngresar: pendiente.\n");
            break;
        case 2:
            printf("\nCrear cuenta: pendiente.\n");
            break;
        case 3:
            printf("\nAdministrador: pendiente.\n");
            break;
        }
    }

    return acceso;
}
