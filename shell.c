#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    bool a = true;

    while(a == true)
    {
        printf("#cisfun$\n");
        a = false;
    }
}