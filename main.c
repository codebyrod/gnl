#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int count;

	count = 0;

	printf("Teste main\n");
	fd = open("mussum.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro: Não foi possível abrir o arquivo 'teste.txt'\n");
		printf("Por favor, crie esse arquivo na mesma pasta.\n");
		return (1); // Retorna 1 para indicar um erro
	}

	printf("--- 🚀 Iniciando teste da GNL com 'teste.txt' ---\n\n");

	// --- PASSO 3: O LOOP DA GNL ---
	// Esta é a mágica:
	// 1. Chama get_next_line(fd)
	// 2. Salva o resultado em 'line'
	// 3. O loop continua ENQUANTO 'line' não for NULL (fim do arquivo)
	while ((line = get_next_line(fd)) != NULL)
	{
		// Imprime o número da linha e o conteúdo
		// Usamos %d para o contador e %s para a string
		printf("Linha %d: %s", count, line);

		// --- PASSO 4: LIBERAR A MEMÓRIA (CRÍTICO!) ---
		// A GNL aloca memória para 'line'.
		// Você é RESPONSÁVEL por liberar (free) essa memória.
		free(line);
		line = NULL; // Boa prática para evitar usar o ponteiro liberado

		count++; // Incrementa o contador de linhas
	}
	// O loop termina quando get_next_line(fd) retorna NULL pela primeira vez.

	printf("\n--- ✅ Fim da leitura do arquivo. ---\n");

	// --- PASSO 5: FECHAR O ARQUIVO ---
	// Sempre feche o arquivo que você abriu.
	close(fd);

	printf("Saindo da main \n");

	return (0);
}
