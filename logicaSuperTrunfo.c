#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.0, 699.28, 25};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1182.0, 361.00, 20};

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    printf("=== Cartas do Super Trunfo ===\n");
    printf("Carta 1: %s (%s) - %s\n", carta1.cidade, carta1.estado, carta1.codigo);
    printf("População: %d | Área: %.2f | PIB: %.2f | Densidade: %.2f | PIB per capita: %.6f\n",
           carta1.populacao, carta1.area, carta1.pib, carta1.densidadePopulacional, carta1.pibPerCapita);

    printf("\nCarta 2: %s (%s) - %s\n", carta2.cidade, carta2.estado, carta2.codigo);
    printf("População: %d | Área: %.2f | PIB: %.2f | Densidade: %.2f | PIB per capita: %.6f\n",
           carta2.populacao, carta2.area, carta2.pib, carta2.densidadePopulacional, carta2.pibPerCapita);

    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
