#include <stdio.h>
#include <stdlib.h>
#include "Sistema.h"

int  main()
{
    int s;
    s=cargarHardcodeadosAlArchivo();
    printf("%d", s);
    iniciarSistema();

    return 0;
}
