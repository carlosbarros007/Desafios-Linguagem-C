/*#include <stdio.h>

// Função para converter metros em outras unidades de medida
void converterMedidas(float metros) {
    float decimetros = metros * 10;
    float centimetros = metros * 100;
    float milimetros = metros * 1000;

    printf("Valor em decimetros: %.2f dm\n", decimetros);
    printf("Valor em centimetros: %.2f cm\n", centimetros);
    printf("Valor em milimetros: %.2f mm\n", milimetros);
}

int main() {
    float metros;

    // Lendo o valor em metros
    printf("Digite um valor em metros: ");
    scanf("%f", &metros);

    // Chamando a função para converter e imprimir os resultados
    converterMedidas(metros);

    return 0;
}*/


/*#include <stdio.h>

// Função para converter metros em outras unidades de medida
void converterMedidas(float metros, float *decimetros, float *centimetros, float *milimetros) {
    *decimetros = metros * 10;
    *centimetros = metros * 100;
    *milimetros = metros * 1000;
}

int main() {
    float metros;
    float decimetros, centimetros, milimetros;

    // Lendo o valor em metros
    printf("Digite um valor em metros: ");
    scanf("%f", &metros);

    // Chamando a função para converter
    converterMedidas(metros, &decimetros, &centimetros, &milimetros);

    // Imprimindo os resultados
    printf("Valor em decimetros: %.2f dm\n", decimetros);
    printf("Valor em centimetros: %.2f cm\n", centimetros);
    printf("Valor em milimetros: %.2f mm\n", milimetros);

    return 0;
}*/

/*
#include <stdio.h>

// Definindo a struct para armazenar as medidas convertidas
typedef struct {
    float decimetros;
    float centimetros;
    float milimetros;
} dadosMedidas;

// Função para converter metros em outras unidades de medida
dadosMedidas converterMedidas(float metros) {
    dadosMedidas m;
    m.decimetros = metros * 10;
    m.centimetros = metros * 100;
    m.milimetros = metros * 1000;
    return m;
}

int main() {
    float metros;
    dadosMedidas resultaDaConvercao;

    // Lendo o valor em metros
    printf("Digite um valor em metros: ");
    scanf("%f", &metros);

    // Chamando a função para converter e armazenando o resultado na struct
    resultaDaConvercao = converterMedidas(metros);

    // Imprimindo os resultados
    printf("Valor em decimetros: %.2f dm\n", resultaDaConvercao.decimetros);
    printf("Valor em centimetros: %.2f cm\n", resultaDaConvercao.centimetros);
    printf("Valor em milimetros: %.2f mm\n", resultaDaConvercao.milimetros);

    return 0;
}*/

/*
#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número já está presente em um vetor
bool estaNoVetor(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return true;
        }
    }
    return false;
}

int main() {
    int vetor1[10], vetor2[10], intersecao[10];
    int tamanhoIntersecao = 0;

    // Lendo o primeiro vetor
    printf("Digite 10 elementos para o primeiro vetor:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor1[i]);
    }

    // Lendo o segundo vetor
    printf("Digite 10 elementos para o segundo vetor:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor2[i]);
    }

    // Encontrando a interseção dos dois vetores
    for (int i = 0; i < 10; i++) {
        if (estaNoVetor(vetor2, 10, vetor1[i]) && !estaNoVetor(intersecao, tamanhoIntersecao, vetor1[i])) {
            intersecao[tamanhoIntersecao] = vetor1[i];
            tamanhoIntersecao++;
        }
    }

    // Imprimindo o vetor interseção
    printf("Vetor interseção:\n");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        printf("%d ", intersecao[i]);
    }
    printf("\n");

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdbool.h>

int main(){
    
    int vetor[8];
    // Lendo os elementos do vetor
    printf("Digite 8 numeros inteiros:\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &vetor[i]);
    }

    // Imprimindo os elementos na ordem inversa
    printf("Elementos na ordem inversa:\n");
    for (int i = 7; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;

}
*/


/*#include <stdio.h>

// Definição da struct para armazenar id e usuário
struct Usuario {
    int id;
    char usuario[50]; // assumindo um tamanho máximo para o nome de usuário
};

int main() {
    struct Usuario usuarioRecebido[5];

    // Solicitando ao usuário que entre com o id e o usuário
    printf("Digite o ID: ");
    scanf("%d", &usuarioRecebido.id);

    printf("Digite o nome de usuario: ");
    scanf(" %s", usuarioRecebido.usuario); // lê o nome de usuário com espaços

    // Imprimindo os valores armazenados na struct
    printf("\nInformacoes coletadas:\n");
    printf("ID: %d\n", usuarioRecebido.id);
    printf("Usuario: %s\n", usuarioRecebido.usuario);

    return 0;
}*/


#include <stdio.h>

// Definição da struct para armazenar id e usuário
/*struct Usuario {
    int id;
    char usuario[50]; // assumindo um tamanho máximo para o nome de usuário
};*/


#include <stdio.h>
#include <stdlib.h> // necessário para usar malloc
#include "struct.h"
#include "cadastrar.h"


int main() {

    Usuario* usuariosCadastrados = cadastrar();

    if (usuariosCadastrados != NULL) {
        // Imprimindo os valores armazenados na struct para cada usuário
        printf("\nInformacoes coletadas:\n");
        for (int i = 0; i < 5; i++) {
            printf("Usuario %d:\n", i + 1);
            printf("ID: %d\n", usuariosCadastrados[i].id);
            printf("Usuario: %s\n", usuariosCadastrados[i].usuario);
            printf("\n"); // linha em branco para separar cada usuário
        }

        // Liberando a memória alocada
        free(usuariosCadastrados);
    }

    return 0;
}
