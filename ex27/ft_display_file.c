/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:17:28 by ldurmish          #+#    #+#             */
/*   Updated: 2024/06/08 12:55:10 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[1];

	fd = open(argv[1], O_RDONLY);
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	else if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (fd == -1)
		write(1, "Cannot read file.\n", 18);
	while (read(fd, buffer, 1) > 0)
		write(1, buffer, 1);
	close(fd);
	return (0);
}
