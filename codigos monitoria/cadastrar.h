
Usuario* cadastrar() {

    Usuario* usuariosCadastrados = malloc(5 * sizeof(Usuario));

    if (usuariosCadastrados == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = 0; i < 5; i++) {
        printf("Digite o ID para o usuario %d: ", i + 1);
        scanf("%d", &usuariosCadastrados[i].id);

        printf("Digite o nome de usuario para o usuario %d: ", i + 1);
        scanf(" %s", usuariosCadastrados[i].usuario); // lê o nome de usuário sem espaços

        printf("\n"); // linha em branco para separar cada entrada de usuário
    }

    return usuariosCadastrados;
}
