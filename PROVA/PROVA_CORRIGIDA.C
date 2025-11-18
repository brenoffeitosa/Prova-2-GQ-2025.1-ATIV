#include <stdio.h>

#include <string.h>



#define TAM 100



struct Categoria {

    int código;

    char nome[50];

};



struct Produto {

    int código;

    char titulo[100];

    char descrição[256];

    int categoria; // código da categoria

    int preco;     // valor em centavos (ex: 1999 = R$ 19,99)

};



// ========================= Questão 1 =========================

void cadastrarCategoria(struct Categoria v[], int *qtd) {

    if (*qtd >= TAM) {

        printf("Limite de categorias atingido!\n");

        return;

    }



    struct Categoria nova;

    printf("Digite o código da categoria: ");

    scanf("%d", &nova.codigo);

    getchar();



    // Verifica duplicidade

    for (int i = 0; i < *qtd; i++) {

        if (v[i].código == nova.codigo) {

            printf("Código já existente!\n");

            return;

        }

    }



    printf("Digite o nome da categoria: ");

    fgets(nova.nome, sizeof(nova.nome), stdin);

    nova.nome[strcspn(nova.nome, "\n")] = '\0';



    v[*qtd] = nova;

    (*qtd)++;



    printf("Categoria cadastrada com sucesso!\n");

}



// ========================= Questão 2 =========================

void imprimirCategorias(struct Categoria v[], int qtd) {

    printf("\n=== Lista de Categorias ===\n");

    for (int i = 0; i < qtd; i++) {

        printf("Código: %d | Nome: %s\n", v[i].código, v[i].nome);

    }

}



// ========================= Questão 3 =========================

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias) {

    printf("\n=== Lista de Produtos ===\n");

    for (int i = 0; i < qtdProdutos; i++) {

        // Procura o nome da categoria

        char nomeCategoria[50] = "Desconhecida";

        for (int j = 0; j < qtdCategorias; j++) {

            if (vc[j].código == vp[i].categoria) {

                strcpy(nomeCategoria, vc[j].nome);

                break;

            }

        }



        double precoReal = vp[i].preco / 100.0;

        printf("Código: %d\n", vp[i].código);

        printf("Título: %s\n", vp[i].titulo);

        printf("Descrição: %s\n", vp[i].descrição);

        printf("Categoria: %s\n", nomeCategoria);

        printf("Preço: R$ %.2f\n\n", precoReal);

    }

}



// ========================= Questão 4 =========================

void selectionSortPorDescricao(struct Produto v[], int qtd) {

    for (int i = 0; i < qtd - 1; i++) {

        int min = i;

        for (int j = i + 1; j < qtd; j++) {

            if (strcmp(v[j].descrição, v[min].descrição) < 0) {

                min = j;

            }

        }

        if (min != i) {

            struct Produto temp = v[i];

            v[i] = v[min];

            v[min] = temp;

        }

    }

}



// ========================= Questão 5 =========================

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {

    int inicio = 0, fim = qtd - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        int cmp = strcmp(v[meio].descrição, x);



        if (cmp == 0) {

            printf("\nProduto encontrado:\n");

            printf("Código: %d | Descrição: %s\n", v[meio].código, v[meio].descrição);

            return;

        } else if (cmp < 0) {

            inicio = meio + 1;

        } else {

            fim = meio - 1;

        }

    }

    printf("\nProduto não encontrado!\n");

}



// ========================= Função principal (exemplo) =========================

int main() {

    struct Categoria categorias[TAM];

    struct Produto produtos[TAM];

    int qtdCategorias = 0, qtdProdutos = 0;



    // Exemplo de uso (pode ser adaptado)

    cadastrarCategoria(categorias, &qtdCategorias);

    imprimirCategorias(categorias, qtdCategorias);



    return 0;

}

#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; // código da categoria
    int preco;     // valor em centavos (ex: 1999 = R$ 19,99)
};

// ========================= Questão 1 =========================
void cadastrarCategoria(struct Categoria v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("Limite de categorias atingido!\n");
        return;
    }

    struct Categoria nova;
    printf("Digite o código da categoria: ");
    scanf("%d", &nova.codigo);
    getchar();

    // Verifica duplicidade
    for (int i = 0; i < *qtd; i++) {
        if (v[i].codigo == nova.codigo) {
            printf("Código já existente!\n");
            return;
        }
    }

    printf("Digite o nome da categoria: ");
    fgets(nova.nome, sizeof(nova.nome), stdin);
    nova.nome[strcspn(nova.nome, "\n")] = '\0';

    v[*qtd] = nova;
    (*qtd)++;

    printf("Categoria cadastrada com sucesso!\n");
}

// ========================= Questão 2 =========================
void imprimirCategorias(struct Categoria v[], int qtd) {
    printf("\n=== Lista de Categorias ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

// ========================= Questão 3 =========================
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias) {
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < qtdProdutos; i++) {
        // Procura o nome da categoria
        char nomeCategoria[50] = "Desconhecida";
        for (int j = 0; j < qtdCategorias; j++) {
            if (vc[j].codigo == vp[i].categoria) {
                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }

        double precoReal = vp[i].preco / 100.0;
        printf("Código: %d\n", vp[i].codigo);
        printf("Título: %s\n", vp[i].titulo);
        printf("Descrição: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCategoria);
        printf("Preço: R$ %.2f\n\n", precoReal);
    }
}

// ========================= Questão 4 =========================
void selectionSortPorDescricao(struct Produto v[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int min = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(v[j].descricao, v[min].descricao) < 0) {
                min = j;
            }
        }
        if (min != i) {
            struct Produto temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

// ========================= Questão 5 =========================
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int inicio = 0, fim = qtd - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(v[meio].descricao, x);

        if (cmp == 0) {
            printf("\nProduto encontrado:\n");
            printf("Código: %d | Descrição: %s\n", v[meio].codigo, v[meio].descricao);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("\nProduto não encontrado!\n");
}

// ========================= Função principal (exemplo) =========================
int main() {
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];
    int qtdCategorias = 0, qtdProdutos = 0;

    // Exemplo de uso (pode ser adaptado)
    cadastrarCategoria(categorias, &qtdCategorias);
    imprimirCategorias(categorias, qtdCategorias);

    return 0;
}