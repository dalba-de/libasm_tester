/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 10:35:34 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/11 17:28:04 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"


void	ft_write_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ██╗    ╔██╗ ██████╗ ██╗████████╗███████╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╚╗  ╔╝██║ ██╔══██╗██║╚══██╔══╝██╔════╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║         ██║██║██╔╝ ██████╔╝██║   ██║   █████╗      ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║         ████████║  ██╔══██╗██║   ██║   ██╔══╝      ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗  ██╔═██╔╝  ██║  ██║██║   ██║   ███████╗    ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝  ╚═╝ ╚═╝   ╚═╝  ╚═╝╚═╝   ╚═╝   ╚══════╝    ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					by dalba-de			\n\n");
	printf("" CYAN"Checking "PURPLE"'FT_WRITE' "RESET""CYAN" function, please wait...\n\n"RESET"");
	sleep(2);
	printf(""GREY"Writing basic input in"PURPLE" 'STDOUT'\n\n");
	sleep(1);

	//BASIC TEST
	int j = 0;
	int k = 0;
	char *str;
	int size;
	
	printf(""BLUE"Basic input:");
	str = "";
	size = strlen(str);
	printf(""RESET"\n");
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);

	str = "hola";
	size = strlen(str);
	printf(""RESET"\n");
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);

	str = "buenos dias";
	size = strlen(str);
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);

	str = "#c#s#p#x#X#e#f#g";
	size = strlen(str);
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);
	
	printf(""BLUE"With \\0 hidden:"RESET"\n");
	str = "the\0hidden";
	size = strlen(str);
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);

	printf(""BLUE"With long string:"RESET"\n");
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.";
	size = strlen(str);
	j = write(1, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(1, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n\n", k);

	//FILE TEST
	sleep(2);
	printf(""GREY"Writing basic input in"PURPLE" 'FILES'"RESET"\n\n");
	sleep(1);
	printf(""GREEN"Creating tester.txt file\n\n");
	int fd;
	fd = open("tester.txt", O_WRONLY|O_CREAT|O_TRUNC, 0700);
	sleep(1);

	printf(""BLUE"Basic input:");
	str = "\n";
	size = strlen(str);
	printf(""RESET"\n");
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);

	str = "hola\n";
	size = strlen(str);
	printf(""RESET"\n");
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);
	
	str = "buenos dias\n";
	size = strlen(str);
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);

	str = "#c#s#p#x#X#e#f#g\n";
	size = strlen(str);
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);
	
	printf(""BLUE"With \\0 hidden:"RESET"\n");
	str = "the\n\0hidden";
	size = strlen(str);
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);

	printf(""BLUE"With long string:"RESET"\n");
	str = "Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.\n";
	size = strlen(str);
	j = write(fd, str, size);
	printf(""GREEN"write ==> %d"RESET"\n", j);
	k = ft_write(fd, str, size);
	printf(""RED"ft_write ==> %d"RESET"\n\n", k);
	close(fd);

	//ERROR TEST
	sleep(2);
	printf(""GREY"Error handling with"PURPLE" 'ERRNO'"RESET"\n\n");
	sleep(1);
	printf(""BLUE"With Errors:"RESET"\n");
	str = NULL;
	j = write(STDOUT_FILENO, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	perror("Error");
	k = ft_write(STDOUT_FILENO, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n", k);
	perror("Error");
	printf("\n");

	str = "hola";
	j = write(300, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	perror("Error");
	k = ft_write(300, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n", k);
	perror("Error");
	printf("\n");

	str = NULL;
	j = write(42, str, size);
	printf("\n"GREEN"write ==> %d"RESET"\n", j);
	perror("Error");
	k = ft_write(42, str, size);
	printf("\n"RED"ft_write ==> %d"RESET"\n", k);
	perror("Error");
	printf("\n");
}

