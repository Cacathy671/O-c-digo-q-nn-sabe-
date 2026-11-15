#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    // item = o nome quantidade = quanto q tem remover= item q se remove 
    int X, quantidade, remover;
    char item[50];
    char busca[50];
    char continuar;
do{
printf("================================\n      Controle de Estoque\n================================\n");
printf("Selecione uma opção:\n");
printf("1. Adicionar Item\n");
printf("2. Remover Item\n");
printf("3. Listar Estoque\n");
printf("4. Sair\n");
printf("Opção: ");
scanf("%d", &X);

if (X == 1){
    fputs("Digite o nome do item: ", stdout);
    scanf(" %49[^\n]", item);
    fputs("Digite a quantidade: ", stdout);
    scanf("%d", &quantidade);

FILE *arquivo = fopen("inventory.txt", "a");
if (arquivo != NULL) {
            fprintf(arquivo, "%s\n%d\n", item, quantidade); 
            fclose(arquivo);
}
            printf("Item adicionado com sucesso!\n");


}else if (X == 2){
    fputs("Digite o nome do item: ", stdout);
    scanf(" %49[^\n]", busca); 
    fputs("Digite a quantidade a ser removida: ", stdout);
    scanf("%d", &remover);

FILE *arquivo = fopen("inventory.txt", "r");
            FILE *temp = fopen("temp.txt", "w"); // Arquivo auxiliar
            int achou = 0;

 if (arquivo != NULL) {           
while (fscanf(arquivo, " %49[^\n]\n%d", item, &quantidade) == 2) {
                    if (strcmp(busca, item) == 0) {
                        achou = 1;
                        
if (remover > 0 && quantidade >= remover){
    quantidade -= remover;
        if (quantidade == 0){
            printf("Item removido do estoque!\n");
        }else{
            printf("Quantidade atualizada com sucesso!\n");
            fprintf(temp, "%s\n%d\n", item, quantidade);
        }
    } else {
        printf("Estoque insuficiente. Quantidade disponível: %d\n", quantidade);
        fprintf(temp, "%s\n%d\n", item, quantidade);
   }
    } else {
                        
    fprintf(temp, "%s\n%d\n", item, quantidade);
                    }
                }
                fclose(arquivo);
            }
            fclose(temp);

            remove("inventory.txt");
            rename("temp.txt", "inventory.txt");

            if (achou == 0) {
                printf("Item não encontrado.\n");
            }
}

else if (X == 3){
    FILE *arquivo = fopen("inventory.txt", "r");
            int tem_item = 0;

            if (arquivo != NULL) {
                while (fscanf(arquivo, " %49[^\n]\n%d", item, &quantidade) == 2) {
                    if (tem_item == 0){
    printf("=============================\n");
    printf("        Estoque Atual\n");
    printf("=============================\n");
    
} else {
    printf("\n");
}
printf("Nome: %s\n", item);
printf("Quantidade: %d\n", quantidade);
tem_item = 1;
                }
                fclose(arquivo);
            }

            if (tem_item == 0) {
                printf("O estoque está vazio.\n");
            }

}else if (X == 4){
    break;
}

else {
    printf("Opção inválida! Tente novamente.\n");
    continue;
}

printf("Deseja realizar outra operação? (s/n): ");
scanf(" %c", &continuar);

}while(continuar == 's' || continuar == 'S');

printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");

    return 0;
}
