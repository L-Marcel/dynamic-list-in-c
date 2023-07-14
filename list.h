typedef struct Children {
  int value;
  struct Children *next;
} Children;

typedef struct {
  int size;
  Children* start;
} List;

List create_list();

void add_in_list(List *list, int value);
void add_in_list_start(List *list, int value);
int remove_list_children(List *list);
int print_list(List list);
