/*geteth.c*/
// Description: Loop over all possible interface names to see if an ethercat device is connected.

#include <stdlib.h>
#include <stdio.h>
#include "../Libs/ec/ec.h"


const char * main(int argc, char **argv)
{
    int iret;
    int i;

    for (i=1; i < argc; i++)
    {
        if ( (iret=ec_start(argv[i]))==EC_SUCCESS ) 
        {
            ec_stop();
            printf("\n\nEhtercat stack connected to %s ...\n", argv[i]);
            return argv[i];
        }
    }

    printf("\n\nNo EtherCAT stack found, connect EtherCAT to pc and run as root\n");
    return "error";
}