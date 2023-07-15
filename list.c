#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Children {
  int value;
  struct Children *next;
} Children;

typedef struct {
  int size;
  Children* start;
} List;

List create_list() {
  List list;
  list.size = 0;
  list.start = NULL;
  return list;
};

void add_in_list(List *list, int value) {
  Children *new_children = (Children*) malloc(sizeof(Children));
  new_children->value = value;
  new_children->next = NULL;

  Children *current_children = list->start;
  if(current_children == NULL) {
    list->start = new_children;
  } else {
    while(current_children->next != NULL) {
      current_children = current_children->next;
    };
    current_children->next = new_children;
  };

  list->size++;
};

void add_in_list_start(List *list, int value) {
  Children *new_children = (Children*) malloc(sizeof(Children));

  new_children->value = value;
  new_children->next = list->start;
  list->start=new_children;
  list->size++;
};

int remove_list_children(List *list) {
  if(list->size == 0) {
    system("cls");
    printf("Nao ha elementos na lista para serem removidos!\n------------------\n");
    return 1;
  };

  int value;
  printf("Selecione o item que voce deseja remover da lista:\n");
  Children *current_children = list->start;
  for(int i = 0; i < list->size; i++) {
    printf("[%d] - %d\n", i, current_children->value);
    current_children = current_children->next;
  };

  printf("--> ");
  scanf("%d", &value);
  fflush(stdin);

  current_children = list->start;
  if(value == 0) {
    list->start = current_children->next;
    list->size--;
    free(current_children);
  } else if(value > 0 && value < list->size) {
    for(int i = 0; i < (list->size-1); i++) {
      if((i+1) == value) {
        Children *children_to_delete = current_children->next;
        current_children->next = current_children->next->next;
        free(children_to_delete);
        list->size--;
        system("cls");
        return 0;
      };
      current_children = current_children->next;
    };
  } else {
    system("cls");
    printf("Opcao invalida!\n------------------\n");
    remove_list_children(list);
  };

  system("cls");
  return 0;
};

int print_list(List list) {
  if(list.size == 0) {
    printf("A lista esta vazia!\n------------------\n");
    return 1;
  };

  printf("Lista atual: ");
  Children *current_children = list.start;
  for(int i = 0; i < list.size; i++) {
    printf("%d ", current_children->value);
    current_children = current_children->next;
  };
  printf("\n------------------\n");

  return 0;
};