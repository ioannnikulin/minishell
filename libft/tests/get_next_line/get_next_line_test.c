/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:46 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 12:57:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include "get_next_line_test.h"
// #define DEBUG

int	gfs[10] = {0,0,0,0,0,0,0,0,0,0};
int curfs = 0;

void	test_notall(void)
{
	#ifdef DEBUG
	printf("\n===== not whole file is read (leaks?) =====\n");
	#endif
	remove("6.tmp");
	int	f1 = open("6.tmp", O_WRONLY|O_CREAT, 0600);
	assert(f1 != -1);
	write(f1, "\n\n \n ", 5);
	close(f1);
	int fs = open("6.tmp", O_RDONLY);
	assert(fs != -1);
	char *r;
	for (int i = 0; i < 2; i ++)
	{
		r = get_next_line(fs);
		assert(strcmp("\n", r) == 0);
	  #ifdef DEBUG 
		if (!r)
			printf("%d NULL\n", i);
		else
			printf("%d [%s] %lu\n", i, r, strlen(r));
	  #endif
		free(r);
	}
	gfs[curfs++] = fs;
	remove("6.tmp");
}

void	test_emptylines(void)
{
	#ifdef DEBUG
		printf("\n===== empty lines and spaces =====\n");
	#endif
	remove("4.tmp");
	int	f1 = open("4.tmp", O_WRONLY|O_CREAT, 0600);
	assert(f1 != -1);
	write(f1, "\n\n \n ", 5);
	close(f1);
	int fs = open("4.tmp", O_RDONLY);
	assert(fs != -1);
	char *r;
	char *exp[6] = {"\n", "\n", " \n", " ", 0, 0};
	for (int i = 0; i < 6; i ++)
	{
		r = get_next_line(fs);
		assert((!r && !exp[i]) || (r && exp[i] && strcmp(r, exp[i]) == 0));
	  #ifdef DEBUG
		if (!r)
			printf("%d NULL\n", i);
		else
			printf("%d [%s] %lu\n", i, r, strlen(r));
	  #endif
		free(r);
	}
	gfs[curfs++] = fs;
	remove("4.tmp");
}

void	pop_files(void)
{
	remove("1.tmp");
	remove("2.tmp");
	remove("3.tmp");
	int	f1 = open("1.tmp", O_WRONLY|O_CREAT, 0600);
	int	f2 = open("2.tmp", O_WRONLY|O_CREAT, 0600);
	int	f3 = open("3.tmp", O_WRONLY|O_CREAT, 0600);
	assert(f1 != -1 && f2 != -1 && f3 != -1);
	write(f1, "abcdefgh\nijklmnopqrstuv\nwxyz\n!", 30);
	close(f1);
	write(f2, "ABCD\nEFGHIJKLMNOPQRSTUVWXYZ!", 28);
	close(f2);
	close(f3);
}

void	test_stdin(void)
{
	printf("\n===== stdin =====\n");
	remove("out.tmp");
	int f = open("out.tmp", O_WRONLY | O_CREAT, 0600);
	assert(f > -1);
	for (int i = 0; i < 2; i ++)
	{
		char *r = get_next_line(0);
		write(f, "[", 1);
		write(f, r, strlen(r));
		write(f, "]\n", 2);
		free(r);
	}
	close(f);
	
	FILE *fptr = fopen("filename.txt", "r");
	assert(fptr);
	char line[100];
	while(fgets(line, 100, fptr))
    	printf("%s", line);
	fclose(fptr);
	remove("out.tmp");
}

void	test_multiple(void)
{
	#ifdef DEBUG
	printf("\n===== multiple files simultaneously =====\n");
	#endif
	pop_files();
	int fs[] = {open("1.tmp", O_RDONLY), open("2.tmp", O_RDONLY), open("3.tmp", O_RDONLY)};
	assert(fs[0] != -1 && fs[1] != -1 && fs[2] != -1);
	char *r;
	int from[] = {0, 0, 1, 2, 1, 2, 0, 0, 2, 1};
	char *exp[] = {"abcdefgh\n", "ijklmnopqrstuv\n", "ABCD\n", 0, "EFGHIJKLMNOPQRSTUVWXYZ!", 0, "wxyz\n", "!", 0, 0};
	for (int i = 0; i < 10; i ++)
	{
		r = get_next_line(fs[from[i]]);
		assert((!r && !exp[i]) || (r && exp[i] && strcmp(r, exp[i]) == 0));
	  #ifdef DEBUG
		if (!r)
			printf("%d NULL\n", i);
		else
			printf("%d [%s] %lu\n", i, r, strlen(r));
	  #endif
		free(r);
	}
	gfs[curfs++] = fs[0];
	gfs[curfs++] = fs[1];
	gfs[curfs++] = fs[2];
	remove("1.tmp");
	remove("2.tmp");
	remove("3.tmp");
}

void	test_invalid(void)
{
	#ifdef DEBUG
	printf("\n===== invalid file descriptor =====\n");
	#endif
	char * r = get_next_line(200);
	assert(!r);
	#ifdef DEBUG
	if (!r)
		printf("NULL\n");
	else
		printf("[%s] %lu\n", r, strlen(r));
	#endif
	free(r);
	gfs[curfs++] = 200;
}

void	test_error(void)
{
	#ifdef DEBUG
	printf("\n===== file disappears after first line read =====\n");
	#endif
	remove("5.tmp");
	int	f1 = open("5.tmp", O_WRONLY|O_CREAT, 0600);
	assert(f1 != -1);
	char *line = ft_calloc(sizeof(char) * BUFFER_SIZE + 12, 1);
	if (!line)
	{
		printf("couldn't allocate memory for the test\n");
		return ;
	}
	for (int i = 0; i < BUFFER_SIZE + 10; i ++)
		line[i] = 'a';
	line[BUFFER_SIZE + 10] = '\n';
	line[BUFFER_SIZE + 11] = 0;
	for (int j = 0; j < 3; j ++)
	{
		write(f1, line, BUFFER_SIZE + 11);
	}
	close(f1);
	int fs = open("5.tmp", O_RDONLY);
	assert(fs != -1);
	char *r;
	char *exp[4] = {line, 0, 0, 0};
	for (int i = 0; i < 4; i ++)
	{
		if (i == 1) 
		{
			close(fs);
			remove("5.tmp");
		}
		r = get_next_line(fs);
		assert((!r && !exp[i]) || (r && exp[i] && strcmp(r, exp[i]) == 0));
		#ifdef DEBUG
		if (!r)
			printf("%d NULL\n", i);
		else
			printf("%d [%s] %lu\n", i, r, strlen(r));
		#endif
		free(r);
	}
	free(line);
	remove("5.tmp");
}

int	get_next_line_test(void)
{
//	test_stdin();
	test_multiple();
	test_emptylines();
	test_invalid();
	test_notall();
	test_error();
	for (int i = 0; i < curfs; i ++)
		close(gfs[i]);
	return (0);
}
