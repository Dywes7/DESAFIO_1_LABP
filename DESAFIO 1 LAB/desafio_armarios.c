#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    unsigned char armarios = 0; // Vari�vel para controlar o estado dos arm�rios (mapa de bits)
    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios com o tempo atual

    while (1) {
        
        printf("\nMenu:\n");
        printf("1. Ocupar arm�rio\n");
        printf("2. Liberar arm�rio\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // Ocupar um arm�rio aleatoriamente
                if (armarios == 255) {

                    printf("Todos os arm�rios est�o ocupados!\n");

                } else {

                    int armarioAleatorio;
                    do {

                        armarioAleatorio = rand() % 8; // Gera um n�mero aleat�rio entre 0 e 7

                    } while (armarios & (1 << armarioAleatorio)); // Verifica se o arm�rio est� ocupado

                    armarios |= (1 << armarioAleatorio); // Ocupa o arm�rio
                    printf("Arm�rio %d ocupado.\n", armarioAleatorio + 1);

                }
                break;

            case 2: // Liberar um arm�rio
                printf("Digite o n�mero do arm�rio a ser liberado (0 a 7): ");
                int numArmario;
                scanf("%d", &numArmario);

                if (numArmario < 0 || numArmario > 7) {

                    printf("N�mero de arm�rio inv�lido!\n");

                } else {

                    if (armarios & (1 << numArmario)) {

                        armarios &= ~(1 << numArmario); // Libera o arm�rio
                        printf("Arm�rio %d liberado.\n", numArmario + 1);

                    } else {

                        printf("O arm�rio %d j� est� vazio.\n", numArmario + 1);

                    }
                }
                break;

            case 3: // Sair do programa
                printf("Saindo do programa.\n");
                exit(0);

            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

        // Apresenta os arm�rios ocupados e livres
        printf("\nEstado dos arm�rios:\n");
        for (int i = 0; i < 8; i++) {

            if (armarios & (1 << i)) {

                printf("Arm�rio %d: Ocupado\n", i);

            } else {

                printf("Arm�rio %d: Livre\n", i);

            }

        }
    }

    return 0;
}
