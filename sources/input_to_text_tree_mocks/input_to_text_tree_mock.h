/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:19:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 16:49:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TO_TEXT_TREE_MOCK_H
# define INPUT_TO_TEXT_TREE_MOCK_H
# include "../minishell.h"

# define MOCK_0_TEXT "echo hello world"
# define MOCK_1_TEXT "   echo hello\\n		my openworld "
# define MOCK_2_TEXT "echo \"1   2\"   3"
# define MOCK_3_TEXT "mkdir testf && cd testf && \
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
# define MOCK_17_TEXT "echo 1 && exit && echo 2"
# define MOCK_18_TEXT "echo 1 && exit || echo 2"
# define MOCK_19_TEXT "echo 1 || echo 2 && (echo 3 && (echo 4 || echo 5) \
&& echo 6)"
# define MOCK_20_TEXT "echo 1 || echo 2 && (echo 3 && (echo 4) || echo 5 \
&& echo 6)"
# define MOCK_21_TEXT "echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5 \
&& echo 6))"
# define MOCK_22_TEXT "echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5)) \
&& echo 6"
# define MOCK_23_TEXT "export foo=bar sea=$foo say=echo _1=$_1 _= && \
$say [$foo] ['$sea'] [\"$sea\"] [$food] [$_1] [$_] [$] [$PATH] [$some]"
# define MOCK_24_TEXT "echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'"
# define MOCK_25_TEXT "echo -nn 1 2"
# define MOCK_26_TEXT "echo 1 -n 2&&echo 3||echo 4   ||echo 5 ||   echo 6"

int	input_to_text_tree_mock(t_tree **tree, char *input);
int	mock_0_tree(t_treenode *root);
int	mock_1_tree(t_treenode *root);
int	mock_2_tree(t_treenode *root);
int	mock_3_tree(t_treenode *root);
int	mock_4_tree(t_treenode *root);
int	mock_5_tree(t_treenode *root);
int	mock_6_tree(t_treenode *root);
int	mock_7_tree(t_treenode *root);
int	mock_8_tree(t_treenode *root);
int	mock_9_tree(t_treenode *root);
int	mock_10_tree(t_treenode *root);
int	mock_11_tree(t_treenode *root);
int	mock_12_tree(t_treenode *root);
int	mock_13_tree(t_treenode *root);
int	mock_14_tree(t_treenode *root);
int	mock_15_tree(t_treenode *root);
int	mock_16_tree(t_treenode *root);
int	mock_17_tree(t_treenode *root);
int	mock_18_tree(t_treenode *root);
int	mock_19_tree(t_treenode *root);
int	mock_20_tree(t_treenode *root);
int	mock_21_tree(t_treenode *root);
int	mock_22_tree(t_treenode *root);
int	mock_23_tree(t_treenode *root);
int	mock_24_tree(t_treenode *root);
int	mock_25_tree(t_treenode *root);
int	mock_26_tree(t_treenode *root);
#endif
