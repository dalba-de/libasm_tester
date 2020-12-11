/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:17:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/06/21 17:43:47 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"

void	ft_read_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ██████╗ ███████╗   ██═╗  ███████═╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╔══██╗██╔════╝  ████╚╗ ██╔═══██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║        ██████╔╝█████╗   ██╔═██╚╗██║   ██║    ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║        ██╔══██╗██╔══╝  ████████║██║   ██║    ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗██║  ██║███████╗██╔═══██║███████╔╝    ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝   ╚═╝╚══════╝     ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
								\n\n");
	printf("" CYAN"Testeando función "PURPLE"'FT_READ' "RESET""CYAN"espere...\n\n"RESET"");
	sleep(2);
	printf(""GREY"Reading basic input from"PURPLE" 'FILES'"RESET"\n\n");
	sleep(1);

	//BASIC TEST
	char buf[4000];
	int r;
	int fd;
	fd = open("tester.txt", O_RDONLY);
	printf(""GREEN"Opening tester.txt file\n\n");
	sleep(1);

	printf(""BLUE"Reading 0 bytes"RESET"\n");
	r = read(fd, buf, 0);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 0);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 1 bytes"RESET"\n");
	r = read(fd, buf, 1);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 1);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 5 bytes"RESET"\n");
	r = read(fd, buf, 5);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 5);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 12 bytes"RESET"\n");
	r = read(fd, buf, 12);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 12);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 17 bytes"RESET"\n");
	r = read(fd, buf, 17);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 17);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 4 bytes"RESET"\n");
	r = read(fd, buf, 4);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 4);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	printf("\n"BLUE"Reading 501 bytes"RESET"\n");
	r = read(fd, buf, 501);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, buf, 501);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);
	close(fd);

	//STDIN TEST
	printf("\n"GREY"Reading basic input from"PURPLE" 'STDIN'"GREY"(max. 50 characters)"RESET"\n\n");
	sleep(1);
	r = ft_read(0, buf, 50);
	buf[r] = '\0';
	write(1, buf, strlen(buf));
	printf(""RED"ft_read ==> %d"RESET"\n", r);

	//ERROR TEST
	printf("\n"GREY"Error handling with"PURPLE" 'ERRNO'"RESET"\n\n");
	sleep(1);
	fd = open("tester.txt", O_RDONLY);
	r = read(fd, NULL, 3);
	perror("Error");
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(fd, NULL, 3);
	perror("Error");
	printf(""RED"ft_read ==> %d"RESET"\n\n", r);

	r = read(-1, buf, 3);
	perror("Error");
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(-1, buf, 3);
	perror("Error");
	printf(""RED"ft_read ==> %d"RESET"\n\n", r);

	r = read(42, NULL, 3);
	perror("Error");
	printf(""GREEN"read ==> %d"RESET"\n", r);
	r = ft_read(42, NULL, 3);
	perror("Error");
	printf(""RED"ft_read ==> %d"RESET"\n\n", r);
	close(fd);
}