
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "struct.h"
#include "gerenciadorTxt.h"


int main() {

    int opcao;
      do {
        printf("****************************\n");
        printf("*      MENU PRINCIPAL      *\n");
        printf("****************************\n");
        printf("* 1. Cadastar Cliente   *\n");
        printf("* 2. Cadastrar Serviço   *\n");
        printf("* 3. Atualizar registro    *\n");
        printf("* 4. Deletar registro      *\n");
        printf("* 5. Sair                  *\n");
        printf("****************************\n");
        printf("\nEscolha uma opção (1-5): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastraCliente();
                break;
            case 2:
                cadastraServico();
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
  


    return 0;
}
