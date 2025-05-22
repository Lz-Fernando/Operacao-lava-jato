#include <stdio.h>
#include <string.h>
#include "../includes/structs.h"

void preencherDataHora(DataHora *dataHora) {
    printf("Digite a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dataHora->dia, &dataHora->mes, &dataHora->ano);
    while (getchar() != '\n');

    printf("Digite o horário (hh:mm): ");
    fgets(dataHora->hora, sizeof(dataHora->hora), stdin);
    dataHora->hora[strcspn(dataHora->hora, "\n")] = '\0';
}
