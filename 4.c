#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


long int findSize(char file_name[])
{
    // abre o arquivo no modo leitura
    FILE* fp = fopen(file_name, "r");

    // verificando se o arquivo existe ou n�o
    if (fp == NULL) {
        printf("Arquivo nao encontrado!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    //calcula o tamanho do arquivp
    long int res = ftell(fp);

    // fecha o arquivo
    fclose(fp);

    return res;
}

int main (void)
{
    int arquivos = 1;
    DIR *dp;
    struct dirent *ep;

    // abre um diret�rio
    dp = opendir ("./");
    if (dp != NULL) // testando se o diretorio em questao � nulo ou n�o, se n�o for ele execultar� o meu programa, caso seja nulo, ir� para a msg de erro l� no fim do codigo
    {
        while (ep = readdir (dp)){
        long int res = findSize(ep->d_name); //variavel res recebe a fun��o para cacular o tamanho de cada um dos meus arquivos que estao dentro do diretorio
        if (res != -1 && res >= 0 && res <= 1023 ){// como me variavel res recebe um tamanho, no caso o tamanho do arquivo do diretorio, que vai sendo percorrido de acordo com o while, eu coloco uma condi�ao para que eu possa imprimir de acordo com a categoria que eu quero, nos if's abaixo coloco as restrin��es para impress�o
                printf("\nNome do arquivo: \n");
                printf(ep->d_name);
                printf("\nO tamanho desse arquivo eh >= 0 e <=1023\n Esse arquivo tem tamanho de %ld bytes \n", res);
        }
        else
            if (res != -1 && res >= 1024 && res <= 2047 )
                {
                    printf("Nome do arquivo: \n");
                    printf(ep->d_name);
                    printf("\nO tamanho desse arquivo eh >= 1024 e <=2047\n Esse arquivo tem tamanho de %ld bytes \n", res);
                }
                else
                    if (res != -1 && res > 2047 )
                {
                    printf("Nome do arquivo: \n");
                    printf(ep->d_name);
                    printf("\nO tamanho desse arquivo eh >2047\n Esse arquivo tem tamanho de %ld bytes \n", res);
                }
        arquivos++;//esse contador � para retornar o num de arquivps e diret�rios
        }
    printf("O numero de arquivos e diretorios eh = %d", arquivos);
    (void) closedir (dp);//fecha o diretorio aberto l� em cima
    }

    else
    perror ("Couldn't open the directory");

return 0;
}
