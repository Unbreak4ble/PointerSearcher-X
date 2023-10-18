#include <stddef.h>
#include <stdbool.h>

typedef struct PointerSearcherX PointerSearcherX;

typedef unsigned int Pid;

typedef struct Module {
  size_t start;
  size_t end;
  char *name;
} Module;

typedef struct Modules {
  size_t len;
  const struct Module *data;
} Modules;

typedef struct Params {
  size_t target;
  size_t depth;
  size_t node;
  size_t rangel;
  size_t ranger;
  const char *file_name;
} Params;

const char *get_last_error(struct PointerSearcherX *ptr);

struct PointerSearcherX *ptrsx_init(void);

void ptrsx_free(struct PointerSearcherX *ptr);

int create_pointer_map_file(struct PointerSearcherX *ptr,
                            Pid pid,
                            bool align,
                            const char *file_name);

int create_pointer_map(struct PointerSearcherX *ptr, Pid pid, bool align);

int load_pointer_map_file(struct PointerSearcherX *ptr, char *file_name);

struct Modules get_modules(struct PointerSearcherX *ptr);

int scanner_pointer_chain_with_module(struct PointerSearcherX *ptr,
                                      struct Module module,
                                      struct Params params);

int scanner_pointer_chain_with_address(struct PointerSearcherX *ptr,
                                       size_t address,
                                       struct Params params);
