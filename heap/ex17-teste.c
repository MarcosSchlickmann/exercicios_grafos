#include <time.h>
#include <stdio.h>
#include "minunit.h"
#include "ex17.h"

int tests_run = 0;

static char * test_heap_sort_menor_para_maior() {
	int vetor[9] = {
    };

	heap_sort_menor_para_maior(vetor, 9);
    
    for (int i = 0; i < 9; ++i)
    {
        if(vetor[i]){
            printf("%d\n", vetor[i]+1);
        } else{
            printf("\n");
        }
    }

    // mu_assert("error, 0", vetor[0] == 3);
    // mu_assert("error, 1", vetor[1] == 2);
    // mu_assert("error, 2", vetor[2] == 1);
    // mu_assert("error, 3", vetor[3] == 0);
    // mu_assert("error 2", vetor[2] == 19);
    // mu_assert("error 3", vetor[3] == 43);
    // mu_assert("error 4", vetor[4] == 45);
    // mu_assert("error 5", vetor[5] == 56);
    // mu_assert("error 6", vetor[6] == 67);
    // mu_assert("error 7", vetor[7] == 95);

	return 0;
}

static char * all_tests() {
    mu_run_test(test_heap_sort_menor_para_maior);
    return 0;
}


int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}