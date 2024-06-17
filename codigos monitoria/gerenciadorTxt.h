Cliente* leituraTxtCliente(int *num_clientes) {
    FILE *file;
    char buffer[500];
    Cliente *clientes = NULL;
    int num_linhas = 0;
    int i = 0;

    file = fopen("clientes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Contar quantas linhas tem no arquivo
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num_linhas++;
    }

    // Alocar memória para o array de clientes
    clientes = (Cliente*) malloc(num_linhas * sizeof(Cliente));
    rewind(file); // Voltar para o início do arquivo

    // Ler e preencher cada estrutura Cliente
     while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remover o caractere de nova linha (\n) do final de cada linha lida
        buffer[strcspn(buffer, "\n")] = '\0';

        // Verificar o início de um novo cliente (linha com "ID: ")
        if (strncmp(buffer, "ID: ", 4) == 0) {
            // Ler o ID do cliente
            sscanf(buffer, "ID: %d", &clientes[i].id);

            // Avançar para a próxima linha e ler os demais campos
            fgets(buffer, sizeof(buffer), file); // Ler próxima linha
            sscanf(buffer, "Usuário: %[^\n]", clientes[i].usuario);

            fgets(buffer, sizeof(buffer), file); // Ler próxima linha
            sscanf(buffer, "Raça: %[^\n]", clientes[i].raca);

            fgets(buffer, sizeof(buffer), file); // Ler próxima linha
            sscanf(buffer, "Idade: %[^\n]", clientes[i].idade);

            fgets(buffer, sizeof(buffer), file); // Ler próxima linha
            sscanf(buffer, "Telefone: %[^\n]", clientes[i].telefone);

            // Avançar para a próxima linha vazia ou final do arquivo
            fgets(buffer, sizeof(buffer), file); // Ler próxima linha

            i++; // Avançar para o próximo cliente
        }
    }

    *num_clientes = i; // Atualiza o número real de clientes lidos
    fclose(file);

    return clientes;
}


void cadastraCliente(){

    FILE *file;

    file = fopen("clientes.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");        
    } 

    Cliente cliente;

    // Coletando dados do cliente
    printf("Digite o ID: ");
    scanf("%d", &cliente.id);
    getchar(); // Consome o newline deixado pelo scanf
    
    printf("Digite o usuário: ");
    fgets(cliente.usuario, sizeof(cliente.usuario), stdin);
    cliente.usuario[strcspn(cliente.usuario, "\n")] = '\0'; // Remove o newline

    printf("Digite a raça: ");
    fgets(cliente.raca, sizeof(cliente.raca), stdin);
    cliente.raca[strcspn(cliente.raca, "\n")] = '\0'; // Remove o newline

    printf("Digite a idade: ");
    fgets(cliente.idade, sizeof(cliente.idade), stdin);
    cliente.idade[strcspn(cliente.idade, "\n")] = '\0'; // Remove o newline
    getchar();

    printf("Digite o telefone: ");
    fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0'; // Remove o newline

    // Gravando o cliente no arquivo
    fprintf(file, "ID: %d\n", cliente.id);
    fprintf(file, "Usuário: %s\n", cliente.usuario);
    fprintf(file, "Raça: %s\n", cliente.raca);
    fprintf(file, "Idade: %s\n", cliente.idade);
    fprintf(file, "Telefone: %s\n", cliente.telefone);
    fprintf(file, "---------------------\n");

    fclose(file);
}

void cadastraServico() {
    FILE *file;
    Servico servico;
    Cliente *clientes;
    int num_clientes;
    int escolha_cliente;

    file = fopen("servico.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê os clientes do arquivo
    clientes = leituraTxtCliente(&num_clientes);
    if (clientes == NULL) {
        printf("Erro ao ler clientes.\n");
        fclose(file);
        return;
    }

    // Exibe a lista de clientes disponíveis
    printf("Lista de Clientes Disponíveis:\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("%d. %s\n", i + 1, clientes[i].usuario);
    }

    // Solicita ao usuário escolher um cliente
    printf("Escolha o cliente (digite o número correspondente): ");
    scanf("%d", &escolha_cliente);
    getchar(); // Consome o newline deixado pelo scanf

    // Verifica se a escolha é válida
    if (escolha_cliente < 1 || escolha_cliente > num_clientes) {
        printf("Escolha inválida.\n");
        fclose(file);
        free(clientes);
        return;
    }

    // Copia o cliente escolhido para a estrutura de serviço
    servico.cliente = clientes[escolha_cliente - 1];

    // Coleta os dados do serviço
    printf("Digite o ID do serviço: ");
    scanf("%d", &servico.id);
    getchar(); // Consume o newline character left by scanf
    
    printf("Digite o tipo de banho: ");
    fgets(servico.banho, sizeof(servico.banho), stdin);
    servico.banho[strcspn(servico.banho, "\n")] = '\0'; // Remove o newline

    printf("Digite o tipo de tosa: ");
    fgets(servico.tosa, sizeof(servico.tosa), stdin);
    servico.tosa[strcspn(servico.tosa, "\n")] = '\0'; // Remove o newline

    printf("Digite o valor do banho: ");
    scanf("%d", &servico.valorBanho);
    getchar(); // Consume o newline character left by scanf

    printf("Digite o valor da tosa: ");
    scanf("%d", &servico.valorTosa);
    getchar(); // Consume the newline character left by scanf

    // Grava o serviço no arquivo
    fprintf(file, "ID: %d\n", servico.id);
    fprintf(file, "ServicoBanho: %s\n", servico.banho);
    fprintf(file, "ServicoTosa: %s\n", servico.tosa);
    fprintf(file, "ValorBanho: %d\n", servico.valorBanho);
    fprintf(file, "ValorTosa: %d\n", servico.valorTosa);
    fprintf(file, "Cliente: %s\n", servico.cliente.usuario); // Exemplo de como gravar o cliente junto ao serviço
    fprintf(file, "---------------------\n");

    fclose(file); // Fecha o arquivo após escrever

    // Libera a memória alocada para o array de clientes
    free(clientes);
}
