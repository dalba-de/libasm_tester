/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:18:22 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/11 17:28:10 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm_bonus.h"
#include "bonus.h"

void    printf_list(t_list *list)
{
    t_list *tmp;

    tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

void	linked_list_test()
{
	printf(""CYAN"\n\n \
			██╗    ██╗████   ██╗██╗ ██╗███████╗███████═╗ ██╗    ██╗███████╗████████╗ ████████╗███████╗███████╗████████╗\n \
			██║    ██║██╔██  ██║██║██╔╝██╔════╝██╔═══██║ ██║    ██║██╔════╝╚══██╔══╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			██║    ██║██║ ██ ██║████═╝ █████╗  ██║   ██║ ██║    ██║███████╗   ██║       ██║   █████╗  ███████╗   ██║\n \
			██║    ██║██║  ████║██║██═╗██╔══╝  ██║   ██║ ██║    ██║╚════██║   ██║       ██║   ██╔══╝  ╚════██║   ██║\n \
			██████╗██║██║   ███║██║ ██║███████╗███████╔╝ ██████╗██║███████║   ██║       ██║   ███████╗███████║   ██║\n \
			╚═════╝╚═╝╚═╝   ╚══╝╚═╝ ╚═╝╚══════╝╚══════╝  ╚═════╝╚═╝╚══════╝   ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					by dalba-de			\n\n");
	printf("" CYAN"Checking "PURPLE"'LINKED LIST' "RESET""CYAN" functions, please wait...\n\n"RESET"");
	sleep(2);
	t_list	*list;
	printf(""GREEN"Creating new list file\n\n");
	sleep(1);
	printf(""GREY"Adding 11 elements to the list with"PURPLE" 'FT_LIST_PUSH_FRONT'"GREY":\n"RED"(lolo, titi, lolo, tata, lolo, tutu, lolo, tete, lolo, toto)\n\n");
	ft_list_push_front(&list, "lolo");
	ft_list_push_front(&list, "toto");
	ft_list_push_front(&list, "lolo");
	ft_list_push_front(&list, "tete");
	ft_list_push_front(&list, "lolo");
	ft_list_push_front(&list, "tutu");
	ft_list_push_front(&list, "lolo");
	ft_list_push_front(&list, "tata");
	ft_list_push_front(&list, "lolo");
	ft_list_push_front(&list, "titi");
	ft_list_push_front(&list, "lolo");
	printf(""GREY"Printing list:"RESET"\n\n");
	printf_list(list);
	sleep(1);
	printf("\n"GREY"Checking the length of the list with"PURPLE" 'FT_LIST_SIZE'"GREY":"RESET"\n\n");
	printf(""GREEN"Length of the list is:"RED" %d"RESET"\n\n", ft_list_size(list));
	sleep(1);
	printf("\n"GREY"Removing "RED"'lolo'"GREY" from the list with"PURPLE" 'FT_LIST_REMOVE_IF'"GREY":"RESET"\n\n");
	ft_list_remove_if(&list, "lolo", strcmp, free);
	sleep(1);
	printf("\n"GREY"Printing the list without "RED"'lolo'"GREY":"RESET"\n\n");
	sleep(1);
	printf_list(list);
	printf("\n"GREY"Now we sort the list with"PURPLE" 'FT_LIST_SORT'"GREY":"RESET"\n\n");
	sleep(1);
	ft_list_sort(&list, strcmp);
	printf(""GREY"Printing the sorted list:"RESET"\n\n");
	sleep(1);
	printf_list(list);
	printf("\n"GREY"Now the length of the list is:"RED" %d"RESET"\n\n", ft_list_size(list));
}
