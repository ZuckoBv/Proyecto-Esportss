#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLAVE "nexus"
#include "modelos.h"
#include "Login.h"

//PROTOTIPADOS-------------------------------------------------
int loginOperador();
//-------------------------------------------------------------

void login ()
{
    int acceso=loginOperador();
    if(acceso==0)
    {
        return 0;
    }
    printf("Interior del programa.\n");
}

//FUNCIONES----------------------------------------------------
int loginOperador()
{
    char clave[10];
    int intentos=3;
    int flag=0;

    while(intentos>=1 && flag==0)
    {
        printf("Inserte clave:\n");
        scanf(" %9s", clave);

        if(strcmp(clave, CLAVE)==0)
        {
            printf("Acceso concedido! Exito!\n\n");
            flag =1;
        }

        else
        {
            intentos--;
            printf("Clave incorrecta, quedan %d intentos.\n", intentos);
        }

        if(intentos<1)
        {
            printf("[Acceso denegado]\n");
        }


    }

    return flag;

}
