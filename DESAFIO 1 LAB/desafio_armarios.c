#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    unsigned char armarios = 0; // Variável para controlar o estado dos armários (mapa de bits)
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    while (1) {
        
        printf("\nMenu:\n");
        printf("1. Ocupar armário\n");
        printf("2. Liberar armário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // Ocupar um armário aleatoriamente
                if (armarios == 255) {

                    printf("Todos os armários estão ocupados!\n");

                } else {

                    int armarioAleatorio;
                    do {

                        armarioAleatorio = rand() % 8; // Gera um número aleatório entre 0 e 7

                    } while (armarios & (1 << armarioAleatorio)); // Verifica se o armário está ocupado

                    armarios |= (1 << armarioAleatorio); // Ocupa o armário
                    printf("Armário %d ocupado.\n", armarioAleatorio + 1);

                }
                break;

            case 2: // Liberar um armário
                printf("Digite o número do armário a ser liberado (0 a 7): ");
                int numArmario;
                scanf("%d", &numArmario);

                if (numArmario < 0 || numArmario > 7) {

                    printf("Número de armário inválido!\n");

                } else {

                    if (armarios & (1 << numArmario)) {

                        armarios &= ~(1 << numArmario); // Libera o armário
                        printf("Armário %d liberado.\n", numArmario + 1);

                    } else {

                        printf("O armário %d já está vazio.\n", numArmario + 1);

                    }
                }
                break;

            case 3: // Sair do programa
                printf("Saindo do programa.\n");
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        // Apresenta os armários ocupados e livres
        printf("\nEstado dos armários:\n");
        for (int i = 0; i < 8; i++) {

            if (armarios & (1 << i)) {

                printf("Armário %d: Ocupado\n", i);

            } else {

                printf("Armário %d: Livre\n", i);

            }

        }
    }

    return 0;
}
