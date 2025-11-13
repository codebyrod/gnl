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
		return (1);
	}
	printf("--- 🚀 Iniciando teste da GNL com 'teste.txt' ---\n\n");
	while ((line = get_next_line(fd)) != NULL)
	{

		printf("Linha %d: %s", count, line);
		free(line);
		line = NULL;
		count++; 
	}
	printf("\n--- ✅ Fim da leitura do arquivo. ---\n");
	close(fd);

	printf("Saindo da main \n");

	return (0);
}
