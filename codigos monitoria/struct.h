typedef struct {
    int id;
    char usuario[50];
    char raca[50];
    char idade[3];
    char telefone[15];
} Cliente;

typedef struct {
    int id;
    char banho[50];
    char tosa[50];
    int valorBanho;
    int valorTosa;
    Cliente cliente;
}Servico;

typedef struct{
   int id;
   int valorTotal;
   Servico servico;
}NotaFiscal;

