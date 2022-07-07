#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int
main (void)

{
    char nome[30];
    int arquivos = 0;
    DIR *dp;
    struct dirent *ep;

    printf("O nome do diretorio: \n");
    scanf("%s",nome);
    dp = opendir (nome);
    if (dp != NULL)
    {
        while (ep = readdir (dp))
            {
            puts (ep->d_name);
            arquivos++;
            }
        printf("O numero de arquivos e diretorios e = %d", arquivos);
        (void) closedir (dp);
    }

    else
    perror ("Couldn't open the directory");

return 0;
}
