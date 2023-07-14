#include <stdio.h>
#include "list.c"

int main() {
  List list = create_list();

  int option, value;
  do {
    printf("Menu de opcoes:\n[0] - Imprimir lista\n[1] - Adicionar item no final da lista\n[2] - Adicionar item no inicio da lista\n[3] - Remover item da lista\n[4] - Encerrar programa\n--> ");
    scanf("%d", &option);
    system("cls");

    switch(option) {
      case 0:
        print_list(list);
        break;
      case 1:
        printf("Informe um numero inteiro: ");
        scanf("%d", &value);
        add_in_list(&list, value);
        system("cls");
        break;
      case 2:
        printf("Informe um numero inteiro: ");
        scanf("%d", &value);
        add_in_list_start(&list, value);
        system("cls");
        break;
      case 3:
        remove_list_children(&list);
        break;
      default:
        break;
    };
  } while (option != 4);

  printf("Programa finalizado!");
  return 0;
};