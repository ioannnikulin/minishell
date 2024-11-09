/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:19:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/08 20:28:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TO_TEXT_TREE_MOCK_H
# define INPUT_TO_TEXT_TREE_MOCK_H
# include "../minishell.h"

# define MOCK_0_TEXT "echo hello world"
# define MOCK_1_TEXT "   echo hello\\n		my openworld "
# define MOCK_2_TEXT "echo \"1   2\"   3"
# define MOCK_3_TEXT "mkdir testf && cd -L testf &&\
mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt"
# define MOCK_4_TEXT "echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6"
# define MOCK_5_TEXT "echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 \
&& echo 6)"
# define MOCK_6_TEXT "echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 \
&& echo 6))"
# define MOCK_7_TEXT "uname"
# define MOCK_8_TEXT "./tests/tool_print_environment one \"two   three\" four"
# define MOCK_9_TEXT "export foo=bar && export foo=zah nope=uhoh && \
unset nope && ./tests/tool_print_environment one \"two   three\" four"
# define MOCK_10_TEXT "pwd"
# define MOCK_11_TEXT "mkdir testf && cd testf && pwd"
# define MOCK_12_TEXT "pwd && mkdir testf && cd ./testf/.. && pwd"
# define MOCK_13_TEXT "cd /bin && pwd"
# define MOCK_14_TEXT "cd /nope && pwd"
# define MOCK_15_TEXT "cd && pwd && cd nope && pwd"
# define MOCK_16_TEXT "env && unset HOME PATH && env"

int		input_to_text_tree_mock(t_tree **tree, char *input);
void	mock_0_tree(t_treenode *root);
void	mock_1_tree(t_treenode *root);
void	mock_2_tree(t_treenode *root);
void	mock_3_tree(t_treenode *root);
void	mock_4_tree(t_treenode *root);
void	mock_5_tree(t_treenode *root);
void	mock_6_tree(t_treenode *root);
void	mock_7_tree(t_treenode *root);
void	mock_8_tree(t_treenode *root);
void	mock_9_tree(t_treenode *root);
void	mock_10_tree(t_treenode *root);
void	mock_11_tree(t_treenode *root);
void	mock_12_tree(t_treenode *root);
void	mock_13_tree(t_treenode *root);
void	mock_14_tree(t_treenode *root);
void	mock_15_tree(t_treenode *root);
void	mock_16_tree(t_treenode *root);
#endif
