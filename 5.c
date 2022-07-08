#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int
main (void)

{
    char nome[30];
    int arquivos = 0;
    int resp;
    DIR *dp;
    struct dirent *ep;

    do{// estrutura de repetição para o tanto de diretório que eu queira
        printf("O nome do diretorio: \n");
        scanf("%s",&nome); //recebendo o nome
        dp = opendir (nome); //diretorio com o nome recebido pela variavel nome sendo aberto
        if (dp != NULL)
        {
            while (ep = readdir (dp))//aqui será feita a leitura do diretorio que foi aberto, nisso ele irá imprimir o nome do mesmo, além de contar quantos arquivos e diretorios tem no mesmo
                {
                puts (ep->d_name);//comando para imprimir os nomes
                arquivos++;//contador de arquivps
                }
            printf("O numero de arquivos e diretorios e = %d", arquivos);
            (void) closedir (dp);//fechando o diretorio
        }

        else
        perror ("Erro!!! diretorio nao existe");//caso não haja diretorio com o nome digitado, essa menagem de erro será impressa
        printf("\nDigite 1 para continuar ou 2 para sair\n");
        scanf("%d", &resp);
    }while(resp==1);

return 0;
}
