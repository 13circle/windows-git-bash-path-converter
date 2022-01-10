#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_help_msg() {
  printf("Error: wrong input format. \n");
  printf("> wingbpath.exe [-tgb,--to-git-bash|-tw,--to-windows] [path string] \n");
}

void win_to_gb(char *win_path) {
  char *token, *gb_path;

  if (!win_path) {
    return;
  }

  if (win_path[2] != '\\') {
    return;
  }

  gb_path = malloc(sizeof(char) * (strlen(win_path) + 2));

  token = strtok(win_path, "\\");
  token[0] = tolower(token[0]);
  token[1] = '\0';
  strcpy(gb_path, "/");
  while (token) {
    strcat(gb_path, token);
    strcat(gb_path, "/");
    token = strtok(NULL, "\\");
  }

  printf("%s \n", gb_path);

  free(gb_path);
}

void gb_to_win(char *gb_path) {
  if (!gb_path) {
    return;
  }

  printf("%s \n", gb_path);
}

int main(int argc, char **argv) {
  char *options[4] = {
    "-tgb",
    "--to-git-bash",
    "-tw",
    "--to-windows"
  };
  char *input_option;
  char *input_path;
  int i, option_num;

  if (argc != 3) {
    print_help_msg();
    return EXIT_FAILURE;
  }

  input_option = argv[1];
  input_path = argv[2];

  for (i = 0, option_num = -1; i < 4; i++) {
    if (!strcmp(options[i], input_option)) {
      option_num = i;
      break;
    }
  }

  if (option_num == -1) {
    print_help_msg();
    return EXIT_FAILURE;
  }

  switch (option_num) {
  case 0: case 1:
    win_to_gb(input_path);
    break;
  case 2: case 3:
    gb_to_win(input_path);
  }

  return EXIT_SUCCESS;
}

