#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char marca[10];
    char modelo[10];
    char placaX[4]; // Change to array of characters
    int placaY;
    int anofab;
};

struct Car cad_car[10];

int main() {
    int menu, i = 0, l, anofabfiltro, anofiltro;
    char filtromodelo[10];

    while (1) {
        printf("\n\t\tCadastro e Consulta de veiculos\n\n");
        printf("Digite o numero da opção correspondente ao serviço desejado\n");
        printf("1- Cadastrar veiculo.\n");
        printf("2- Consultar veiculos cadastrados.\n");
        printf("3- Consultar veiculos cadastrados fabricados em um ano específico.\n");
        printf("4- Consultar veiculos cadastrados a partir de um ano de fabricação.\n");
        printf("5- Consultar veiculos cadastrados a partir de um modelo especifico.\n");
        printf("0- Sair do menu.\n");
        printf(":::");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                if (i < 10) {
                    printf("\nQual marca do veículo?\t");
                    scanf("%s", cad_car[i].marca);
                    printf("Qual o modelo do veículo?\t");
                    scanf("%s", cad_car[i].modelo);
                    printf("Qual as três letras do placa do veiculo?\t");
                    scanf("%s", cad_car[i].placaX);
                    printf("Quais os quatro numeros do placa do veiculo?\t");
                    scanf("%d", &cad_car[i].placaY);
                    printf("Qual o ano de fabricação do veiculo?\t");
                    scanf("%d", &cad_car[i].anofab);
                    i++;
                } else {
                    printf("Limite de veículos cadastrados atingido.\n");
                }
                break;

            case 2:
                for (l = 0; l < i; l++) {
                    printf("\n\nMarca: %s", cad_car[l].marca);
                    printf("\nModelo: %s", cad_car[l].modelo);
                    printf("\nPlaca: %s - %d", cad_car[l].placaX, cad_car[l].placaY);
                    printf("\nAno de fabricação: %d", cad_car[l].anofab);
                }
                break;

            case 3:
                printf("Deseja visualizar o cadastro de carros fabricado em qual ano?");
                scanf("%d", &anofabfiltro);
                for (l = 0; l < i; l++) {
                    if (cad_car[l].anofab == anofabfiltro) {
                        printf("\n\nMarca: %s", cad_car[l].marca);
                        printf("\nModelo: %s", cad_car[l].modelo);
                        printf("\nPlaca: %s - %d", cad_car[l].placaX, cad_car[l].placaY);
                        printf("\nAno de fabricação: %d", cad_car[l].anofab);
                    }
                }
                break;

            case 4:
                printf("Deseja visualizar o cadastro de carros a partir de qual ano de fabricação?");
                scanf("%d", &anofiltro);
                for (l = 0; l < i; l++) {
                    if (cad_car[l].anofab >= anofiltro) {
                        printf("\n\nMarca: %s", cad_car[l].marca);
                        printf("\nModelo: %s", cad_car[l].modelo);
                        printf("\nPlaca: %s - %d", cad_car[l].placaX, cad_car[l].placaY);
                        printf("\nAno de fabricação: %d", cad_car[l].anofab);
                    }
                }
                break;

            case 5:
                printf("Deseja visualizar o cadastro de carros de qual modelo?");
                scanf("%s", filtromodelo);
                for (l = 0; l < i; l++) {
                    if (strcmp(cad_car[l].modelo, filtromodelo) == 0) {
                        printf("\n\nMarca: %s", cad_car[l].marca);
                        printf("\nModelo: %s", cad_car[l].modelo);
                        printf("\nPlaca: %s - %d", cad_car[l].placaX, cad_car[l].placaY);
                        printf("\nAno de fabricação: %d", cad_car[l].anofab);
                    }
                }
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("Essa opção não está no menu.\n");
                break;
        }
    }
    return 0;
}
