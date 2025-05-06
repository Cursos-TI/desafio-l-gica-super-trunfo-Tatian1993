#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char codigo[10];  // Identificador da carta
    char estado[50];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Funções para cálculos
float calcularDensidade(int populacao, float area) {
    return (area == 0) ? 0 : populacao / area;
}

float calcularPIBperCapita(float pib, int populacao) {
    return (populacao == 0) ? 0 : pib / populacao;
}

float calcularSuperPoder(Carta carta) {
    float inverso_densidade = (carta.densidade_populacional == 0) ? 0 : 1 / carta.densidade_populacional;
    return carta.populacao + carta.area + carta.pib + carta.pontos_turisticos + carta.pib_per_capita + inverso_densidade;
}

// Função para comparar um atributo específico
void compararCartas(Carta carta1, Carta carta2, char atributo[]) {
    float valor1, valor2;

    // Escolha do atributo para comparação
    if (strcmp(atributo, "populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
    } else if (strcmp(atributo, "super_poder") == 0) {
        valor1 = carta1.super_poder;
        valor2 = carta2.super_poder;
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    // Exibição dos valores comparados
    printf("\nComparacao de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s) [Codigo: %s]: %.2f\n", carta1.nome, carta1.estado, carta1.codigo, valor1);
    printf("Carta 2 - %s (%s) [Codigo: %s]: %.2f\n", carta2.nome, carta2.estado, carta2.codigo, valor2);

    // Determinação do vencedor
    if (strcmp(atributo, "densidade_populacional") == 0) {
        printf("Resultado: %s venceu!\n", (valor1 < valor2) ? carta1.nome : carta2.nome);
    } else {
        printf("Resultado: %s venceu!\n", (valor1 > valor2) ? carta1.nome : carta2.nome);
    }
}

int main() {
    Carta carta1, carta2;
    char atributo[30];

    // Entrada de dados para carta 1
    printf("Informacoes para Carta 1:\n");
    printf("Codigo da carta: "); scanf("%s", carta1.codigo);
    printf("Estado: "); scanf("%s", carta1.estado);
    printf("Nome da cidade: "); scanf("%s", carta1.nome);
    printf("Populacao: "); scanf("%d", &carta1.populacao);
    printf("Area (km²): "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("NUmero de pontos turisticos: "); scanf("%d", &carta1.pontos_turisticos);

    // Cálculo das métricas para carta 1
    carta1.densidade_populacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcularPIBperCapita(carta1.pib, carta1.populacao);
    carta1.super_poder = calcularSuperPoder(carta1);

    // Entrada de dados para carta 2
    printf("\nInformacoes para Carta 2:\n");
    printf("Codigo da carta: "); scanf("%s", carta2.codigo);
    printf("Estado: "); scanf("%s", carta2.estado);
    printf("Nome da cidade: "); scanf("%s", carta2.nome);
    printf("Populacao:  "); scanf("%d", &carta2.populacao);
    printf("Area (km²):  "); scanf("%f", &carta2.area);
    printf("PIB:  "); scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: "); scanf("%d", &carta2.pontos_turisticos);

    // Cálculo das métricas para carta 2
    carta2.densidade_populacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcularPIBperCapita(carta2.pib, carta2.populacao);
    carta2.super_poder = calcularSuperPoder(carta2);

    // Exibição dos resultados
    printf("\n================ Resultados das Cartas ================\n");
    printf("Carta 1 - %s (%s) [Código: %s]: População: %d | Área: %.2f km² | PIB: %.2f | Pontos turísticos: %d\n", 
           carta1.nome, carta1.estado, carta1.codigo, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
    printf("Densidade: %.2f hab/km² | PIB per capita: R$ %.2f | Super Poder: %.2f\n", 
           carta1.densidade_populacional, carta1.pib_per_capita, carta1.super_poder);

    printf("\nCarta 2 - %s (%s) [Código: %s]: População: %d | Área: %.2f km² | PIB: %.2f | Pontos turísticos: %d\n", 
           carta2.nome, carta2.estado, carta2.codigo, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);
    printf("Densidade: %.2f hab/km² | PIB per capita: R$ %.2f | Super Poder: %.2f\n", 
           carta2.densidade_populacional, carta2.pib_per_capita, carta2.super_poder);

    // Escolha do atributo pelo usuário
    printf("\nEscolha um atributo para comparar (populacao, area, pib, densidade_populacional, pib_per_capita, super_poder): ");
    scanf("%s", atributo);

    // Comparação das cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}