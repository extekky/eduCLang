#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

void read_and_print_json(const char *filename) {
    // Открытие файла
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    // Чтение содержимого файла
    json_error_t error;
    json_t *root = json_loadf(file, 0, &error);
    fclose(file);

    if (!root) {
        fprintf(stderr, "Error parsing JSON: %s\n", error.text);
        return;
    }

    char *json_str = json_dumps(root, JSON_INDENT(4));
    if (!json_str) {
        fprintf(stderr, "Error converting JSON to string\n");
        json_decref(root);
        return;
    }

    printf("%s\n", json_str);

    free(json_str);
    json_decref(root);
}

int main() {
    const char *filename = "myjson.json";
    read_and_print_json(filename);
    return 0;
}
