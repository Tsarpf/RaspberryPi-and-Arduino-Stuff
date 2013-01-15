#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

#include "rs232.h"


int main()
{

	int i, n, cport_nr=0, bdrate=9600;

    unsigned char buf[4096];

    if(OpenComport(cport_nr, bdrate))
    {
        printf("Cannot open connection\n");
        return(0);
    }

    while(1)
    {
        n = PollComport(cport_nr, buf, 4095);

        if(n > 0)
        {
            buf[n] = 0; //Always put a "null" at the end of a string

            for(i=0; i < n; i++)
            {
                if(buf[i] < 32)
                {
                    buf[i] = '.';
                }
            }

            printf("received %i bytes: %s\n", n, (char *)buf);
        }

        usleep(100000);
    }

    return(0);
}
