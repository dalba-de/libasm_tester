/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:31:47 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/11 17:27:19 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"
#include "mandatory.h"

#define	BFSIZE			0xF0000
#define STRLEN_TEST(s, b)   i = ft_strlen(s); printf("|" RED "%-28s"RESET" |"GREEN"%-28lu "RESET"|"PURPLE"%-28d"RESET"|\n", b, strlen(s), i);

void    ft_strlen_test()
{
	printf(""CYAN"\n\n \
			███████╗████████╗     ███████╗████████╗██████╗ ██╗    ███████╗████   ██╗ ████████╗███████╗███████╗████████╗\n \
			██╔════╝╚══██╔══╝     ██╔════╝╚══██╔══╝██╔══██╗██║    ██╔════╝██╔██  ██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			█████╗     ██║        ███████╗   ██║   ██████╔╝██║    █████╗  ██║ ██ ██║    ██║   █████╗  ███████╗   ██║\n \
			██╔══╝     ██║        ╚════██║   ██║   ██╔══██╗██║    ██╔══╝  ██║  ████║    ██║   ██╔══╝  ╚════██║   ██║\n \
			██║        ██║███████╗███████║   ██║   ██║  ██║██████╗███████╗██║   ███║    ██║   ███████╗███████║   ██║\n \
			╚═╝        ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═════╝╚══════╝╚═╝   ╚══╝    ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					by dalba-de			\n\n");
	printf("" CYAN"Testeando función "PURPLE"'FT_STRLEN' "RESET""CYAN"espere...\n\n"RESET"");
	sleep(2);
	int i = 0;
	printf("" RED "%-31s"GREEN"%-30s"PURPLE"%-30s\n"RESET"", "INPUT", "STRLEN", "FT_STRLEN");
	printf(" ");
	while (i++ < 88)
		printf("_");
	printf(" ");
	printf("\n");
	STRLEN_TEST("", "Empty string");
	STRLEN_TEST("hola", "hola");
	STRLEN_TEST("buenos dias", "buenos dias");
	STRLEN_TEST("asdfasdf''///##!!@", "Random characters");
	STRLEN_TEST("the\0hidden", "\\0 hidden");
	STRLEN_TEST("Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
	bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
	volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
	felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
	ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
	tortor, sit amet consequat amet.", "Long string");
	STRLEN_TEST("♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪", "Unicode string");
	STRLEN_TEST("01234567, AAAAAA, abc\xba e, ......, end of string !", "Optimization test");

	//Non aligned test
	const char	*s = "YOLO";

	if ((unsigned long)s & 0b111)
		s++;
	STRLEN_TEST(s, "Non aligned test");

	//Speed test
	size_t	size = BFSIZE * 16;
	char	*str = malloc(size + 1);
	
	memset(str, 'A', size);
	str[size] = 0;
	STRLEN_TEST(str, "Speed test");

	i = 0;
	printf("|");
	while (i++ < 29)
		printf("_");
	printf("|");
	while (i++ < 59)
		printf("_");
	printf("|");
	while (i++ < 88)
		printf("_");
	printf("|");
	printf("\n\n");
}
