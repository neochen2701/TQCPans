#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int is_perfect_match(const char *s1, const char *sub) {
    return !strcmp(s1, sub);
}

int main(void) {
    int m;
    scanf("%d", &m);

    char **fabric = malloc(m * sizeof(char *));
    for (int i = 0; i < m; i++) {
        fabric[i] = malloc(1001 * sizeof(char));
        scanf("%s", fabric[i]);
    }

    qsort(fabric, m, sizeof(char *), compare);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int len = strlen(fabric[i]);
        for (int j = 1; j <= len / 2; j++) {
            if (strncmp(fabric[i], fabric[i] + len - j, j) == 0) {
                char *sub = malloc((len - 2 * j + 1) * sizeof(char));
                strncpy(sub, fabric[i] + j, len - 2 * j);
                sub[len - 2 * j] = '\0';
                if (bsearch(&sub, fabric, m, sizeof(char *), compare)) {
                    ans++;
                }
                free(sub);
            }
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < m; i++) {
        free(fabric[i]);
    }
    free(fabric);

    return 0;
}
