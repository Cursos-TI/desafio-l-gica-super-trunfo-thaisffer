#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void exibirMenu(int atributosDisponiveis[]) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributosDisponiveis[1]) printf("1 - População\n");
    if (atributosDisponiveis[2]) printf("2 - Área\n");
    if (atributosDisponiveis[3]) printf("3 - PIB\n");
    if (atributosDisponiveis[4]) printf("4 - Pontos Turísticos\n");
    if (atributosDisponiveis[5]) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

float obterValorAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

int main() {
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 22000.50, 50};
    Carta carta2 = {"Argentina", 46000000, 2780400.0, 6400.30, 30};

    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributosDisponiveis[6] = {0,1,1,1,1,1};
    int atributo1, atributo2;

    printf("=== Super Trunfo - Nível Mestre ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    exibirMenu(atributosDisponiveis);
    scanf("%d", &atributo1);

    if (!atributosDisponiveis[atributo1]) {
        printf("Opção inválida!\n");
        return 1;
    }
    atributosDisponiveis[atributo1] = 0;

    exibirMenu(atributosDisponiveis);
    scanf("%d", &atributo2);

    if (!atributosDisponiveis[atributo2]) {
        printf("Opção inválida!\n");
        return 1;
    }

    float valor1_c1 = obterValorAtributo(carta1, atributo1);
    float valor1_c2 = obterValorAtributo(carta2, atributo1);

    float valor2_c1 = obterValorAtributo(carta1, atributo2);
    float valor2_c2 = obterValorAtributo(carta2, atributo2);

    int invertido1 = (atributo1 == 5);
    int invertido2 = (atributo2 == 5);

    float pontos1 = 0, pontos2 = 0;

    pontos1 += (valor1_c1 == valor1_c2) ? 0 :
               (invertido1 ? (valor1_c1 < valor1_c2 ? 1 : 0) : (valor1_c1 > valor1_c2 ? 1 : 0));

    pontos2 += (valor1_c1 == valor1_c2) ? 0 :
               (invertido1 ? (valor1_c2 < valor1_c1 ? 1 : 0) : (valor1_c2 > valor1_c1 ? 1 : 0));

    pontos1 += (valor2_c1 == valor2_c2) ? 0 :
               (invertido2 ? (valor2_c1 < valor2_c2 ? 1 : 0) : (valor2_c1 > valor2_c2 ? 1 : 0));

    pontos2 += (valor2_c1 == valor2_c2) ? 0 :
               (invertido2 ? (valor2_c2 < valor2_c1 ? 1 : 0) : (valor2_c2 > valor2_c1 ? 1 : 0));

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1: %d -> %s: %.2f | %s: %.2f\n", atributo1, carta1.nome, valor1_c1, carta2.nome, valor1_c2);
    printf("Atributo 2: %d -> %s: %.2f | %s: %.2f\n", atributo2, carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    if (soma1 > soma2) {
        printf("\nVencedor: %s\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\nVencedor: %s\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
