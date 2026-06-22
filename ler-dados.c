#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void){
    char buffer[BUFFER_SIZE];
    int linha = 1;
    int nova_linha = 1;

    FILE *arquivo = fopen("dados.txt", "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, arquivo)) {
        if (nova_linha) {
            printf("%d: ", linha);
            nova_linha = 0;
        }

        fputs(buffer, stdout);

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            linha++;
            nova_linha = 1;
        }
    }

    fclose(arquivo);
    return 0;
}