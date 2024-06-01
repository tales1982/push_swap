/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:22:40 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/01 17:52:16 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int *parse_line_to_map(const char *line, int width)
{
    int *map_row;
    int i;

    map_row = malloc(sizeof(int) * width);
    if (!map_row)
        return (NULL);
    i = 0;
    while (i < width)
    {
        if (line[i] == '1')
            map_row[i] = 1;
        else if (line[i] == '0')
            map_row[i] = 0;
        else if (line[i] == 'C')
            map_row[i] = 2;
        else if (line[i] == 'E')
            map_row[i] = 3;
        else if (line[i] == 'P')
        {
            map_row[i] = 4;
        }
        i++;
    }
    return (map_row);
}

int **initialize_map(int width, int initial_height)
{
    int **map;

    (void)width;
    map = malloc(sizeof(int *) * initial_height);
    return (map);
}

void read_map_file(int fd, int **map, int *width, int *height)
{
    char *line;
    int row;

    row = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (row == 0)
            *width = ft_strlen(line) - 1;  // Ajuste conforme a implementação de get_next_line
        map[row] = parse_line_to_map(line, *width);
        free(line);
        row++;
    }
    *height = row;
}

int **load_map(const char *filename, int *width, int *height)
{
    int fd;
    int **map;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = initialize_map(*width, 100);
    read_map_file(fd, map, width, height);
    close(fd);
    return (map);
}




/*
#include "../so_long.h"

int *parse_line_to_map(const char *line, int width)
{
    int *map_row;
    int i;

    map_row = malloc(sizeof(int) * width);
    if (!map_row)
        return (NULL);
    i = 0;
    while (i < width)
    {
        if (line[i] == '1')
            map_row[i] = 1;
        else if (line[i] == '0')
            map_row[i] = 0;
        else if (line[i] == 'C')
            map_row[i] = 2;
        else if (line[i] == 'E')
            map_row[i] = 3;
		else if (line[i] == 'P')
        {
            map_row[i] = 4;
        }
        i++;
    }
    return (map_row);
}

int	**initialize_map(int width, int initial_height)
{
	int	**map;

	(void)width;
	map = malloc(sizeof(int *) * initial_height);
	return (map);
}

void	read_map_file(FILE *file, int **map, int *width, int *height)
{
	char	*line;
	size_t	len;
	ssize_t	read;
	int		row;

	line = NULL;
	len = 0;
	row = 0;
	while ((read = getline(&line, &len, file)) != -1)
	{
		if (row == 0)
			*width = read - 1;
		map[row] = parse_line_to_map(line, *width);
		row++;
	}
	*height = row;
	free(line);
}

int	**load_map(const char *filename, int *width, int *height)
{
	int		fd;
	FILE	*file;
	int		**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = fdopen(fd, "r");
	if (!file)
		return (NULL);
	map = initialize_map(*width, 100);
	read_map_file(file, map, width, height);
	fclose(file);
	close(fd);
	return (map);
}
*/
/*
° parse_line_to_map: Converte uma linha do arquivo de mapa em uma linha de inteiros (1 para parede,
	0 para chão).
° initialize_map: Inicializa a estrutura de dados para armazenar o mapa.
° read_map_file: Lê o arquivo de mapa e converte cada linha em uma representação interna,
	preenchendo a estrutura de dados do mapa.
° load_map: Abre o arquivo de mapa,
	inicializa a estrutura de dados e carrega o mapa,
	retornando a representação interna do mapa.
*/