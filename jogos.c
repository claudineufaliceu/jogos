#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T_STR 100

typedef char string [T_STR];


typedef struct dados_jogo {
    string nome;
    int ano;
    string genero;
    string produtora;
    float valor;
} jogo_t;

typedef struct no {
    jogo_t dados_jogo;
    struct no *prox;
} no_t;

int menu();
jogo_t novo_jogo();
no_t *novo_no(jogo_t jogo);
void inserir_jogo_lista_inicio(no_t *no, no_t **lista);
void inserir_jogo_lista_fim(no_t *no, no_t **lista);
no_t *localizar_ultimo_no_na_lista(no_t *lista);
no_t localizar_jogo_por_nome(string nome, no_t *lista);
void mostrar_dados_jogo(jogo_t dados_jogo);
void excluir_no_lista(no_t *no, no_t **lista);
void retirar_enter(string str);
void formatar_maiuscula(string str);
void listar_jogos_cadastrados(no_t *lista);
int sub_menu_cadastro();
void exportar_dados_arquivo_texto(char* nome, no_t *lista);

int main() {
    int opc_principal, opc_sub;
    no_t *lista = NULL;

    do {
        opc_principal = menu();

        switch (opc_principal) {
            case 1: 
                do {
                    opc_sub = sub_menu_cadastro();

                    if (opc_sub == 1) {
                        inserir_jogo_lista_inicio(novo_no(novo_jogo()), &lista);
                    }
                    else if (opc_sub == 2) {
                        inserir_jogo_lista_fim(novo_no(novo_jogo()), &lista);
                    }
                    else if (opc_sub == 3) {

                    }

                } while (opc_sub != 0);
                
                break;
            
            case 2: 
                listar_jogos_cadastrados(lista);
                
                break;
            
            case 3: 

                break;
            case 4: 

                break;
            case 5:
                exportar_dados_arquivo_texto("jogos.txt", lista);
                
                break;
        }


    } while (opc_principal != 0);

    return 0;
}

int menu() {
    int opcao;

    printf("\n=== CADASTRO DE JOGOS ===\n");
    printf("\n-----------------------------\n");
    printf("1 - Cadastrar novo jogo\n");
    printf("2 - Listar jogos cadastrados\n");
    printf("3 - Encontrar um jogo por nome\n");
    printf("4 - Excluir jogo da lista\n");
    printf("5 - Exportar dados para arquivo texto\n");
    printf("0 - Sair do programa\n");
    printf("-----------------------------\n\n");
    printf("usr-> ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int sub_menu_cadastro() {
    int opcao;

    printf("\n=== INSERCAO NA LISTA ===\n");
    printf("\n-----------------------------\n");
    printf("1 - Pelo inicio\n");
    printf("2 - Pelo meio\n");
    printf("3 - Pelo fim\n");
    printf("0 - Retornar ao menu principal\n");
    printf("-----------------------------\n\n");
    printf("usr-> ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

jogo_t novo_jogo() {
    jogo_t novo;

    printf("\nNome do jogo: ");
    fgets(novo.nome, T_STR, stdin);
    retirar_enter(novo.nome);
    formatar_maiuscula(novo.nome);
    
    printf("Ano de lancamento: ");
    scanf("%i", &novo.ano);
    getchar();

    printf("Genero do jogo: ");
    fgets(novo.genero, T_STR, stdin);
    retirar_enter(novo.genero);
    formatar_maiuscula(novo.genero);

    printf("Produtora do jogo: ");
    fgets(novo.produtora, T_STR, stdin);
    retirar_enter(novo.produtora);
    formatar_maiuscula(novo.produtora);

    printf("Valor: ");
    scanf("%f", &novo.valor);
    getchar();

    return novo;
}

no_t *novo_no(jogo_t jogo) {
    no_t *novo = NULL;

    novo = calloc(1, sizeof(no_t));

    novo -> dados_jogo = jogo;
    novo -> prox = NULL;

    return novo;
}

void inserir_jogo_lista_inicio(no_t *no, no_t **lista) {
    if (*lista) {
        no -> prox = *lista;
    }
    *lista = no;
}

void inserir_jogo_lista_fim(no_t *no, no_t **lista) {
    no_t *ultimo = NULL;
    
    if (!*lista) {
        *lista = no;
    }
    else {
        ultimo = localizar_ultimo_no_na_lista(*lista);
        ultimo -> prox = no;
    }
}

no_t *localizar_ultimo_no_na_lista(no_t *lista) {
    for (lista; lista -> prox != NULL; lista = lista -> prox);
    
    return lista;
}

no_t localizar_jogo_por_nome(string nome, no_t *lista) {

}

void mostrar_dados_jogo(jogo_t dados_jogo) {
    printf("\nNome do jogo: %s\n", dados_jogo.nome);
    printf("Ano de lancamento: %i\n", dados_jogo.ano);
    printf("Genero do jogo: %s\n", dados_jogo.genero);
    printf("Produtora do jogo: %s\n", dados_jogo.produtora);
    printf("Valor: %.2f\n\n", dados_jogo.valor);
}

void excluir_no_lista(no_t *no, no_t **lista) {

}

void retirar_enter(string str) {
    *(str + strlen(str) - 1) = '\0';
}

void formatar_maiuscula(string str) {
    for (int i = 0; i < strlen(str); i++) {

    }
}

void listar_jogos_cadastrados(no_t *lista) {
    while (lista) {
        mostrar_dados_jogo(lista -> dados_jogo);
        lista = lista -> prox;
    }
}

void exportar_dados_arquivo_texto(char* nome, no_t *lista) {
    FILE *fd = NULL;

    fd = fopen(nome, "w");

    if (!fd) return;

    for (lista; lista != NULL; lista = lista -> prox) {
    fprintf(fd, "\nNome do jogo: %s\n", lista -> dados_jogo.nome);
    fprintf(fd, "Ano de lancamento: %i\n", lista -> dados_jogo.ano);
    fprintf(fd, "Genero do jogo: %s\n", lista -> dados_jogo.genero);
    fprintf(fd, "Produtora do jogo: %s\n", lista -> dados_jogo.produtora);
    fprintf(fd, "Valor: %.2f\n\n", lista -> dados_jogo.valor);
    }

    fclose(fd);
}
