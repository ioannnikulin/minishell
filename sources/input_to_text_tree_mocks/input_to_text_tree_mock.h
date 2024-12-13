/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:19:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 12:49:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TO_TEXT_TREE_MOCK_H
# define INPUT_TO_TEXT_TREE_MOCK_H
# include "../minishell.h"

# define MOCK_00_TEXT "echo hello world"
# define MOCK_01_TEXT "   echo hello\\n		my openworld "
# define MOCK_02_TEXT "echo \"1   2\"   3"
# define MOCK_03_TEXT "mkdir testf && cd testf && \
mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt"
# define MOCK_04_TEXT "echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6"
# define MOCK_05_TEXT "echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 \
&& echo 6)"
# define MOCK_06_TEXT "echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 \
&& echo 6))"
# define MOCK_07_TEXT "uname"
# define MOCK_08_TEXT "./tests/tool_print_environment one \"two   three\" four"
# define MOCK_09_TEXT "export foo=bar && export foo=zah nope=uhoh && \
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
# define MOCK_27_TEXT "cd a b && echo 1"
# define MOCK_28_TEXT "echo 1 && echo 1 | wc | wc"
# define MOCK_29_TEXT "(echo 1 && echo 1) | wc | wc"
# define MOCK_30_TEXT "echo 1 && (echo 1 && (echo 1 && echo 1) | wc | wc) \
| wc && echo 1"
# define MOCK_31_TEXT "echo 1 > out.a && echo 2 > out.a"
# define MOCK_32_TEXT "echo 1 >> out.a && echo 2 >> out.a"

int	input_to_text_tree_mock(t_tree **tree, char *input);
int	mock_00_tree(t_treenode *root);
int	mock_00_tree_expanded(t_treenode *root);
int	mock_01_tree(t_treenode *root);
int	mock_01_tree_expanded(t_treenode *root);
int	mock_02_tree(t_treenode *root);
int	mock_02_tree_expanded(t_treenode *root);
int	mock_03_tree(t_treenode *root);
int	mock_03_tree_expanded(t_treenode *root);
int	mock_04_tree(t_treenode *root);
int	mock_04_tree_expanded(t_treenode *root);
int	mock_05_tree(t_treenode *root);
int	mock_05_tree_expanded(t_treenode *root);
int	mock_06_tree(t_treenode *root);
int	mock_06_tree_expanded(t_treenode *root);
int	mock_07_tree(t_treenode *root);
int	mock_07_tree_expanded(t_treenode *root);
int	mock_08_tree(t_treenode *root);
int	mock_08_tree_expanded(t_treenode *root);
int	mock_09_tree(t_treenode *root);
int	mock_09_tree_expanded(t_treenode *root);
int	mock_10_tree(t_treenode *root);
int	mock_10_tree_expanded(t_treenode *root);
int	mock_11_tree(t_treenode *root);
int	mock_11_tree_expanded(t_treenode *root);
int	mock_12_tree(t_treenode *root);
int	mock_12_tree_expanded(t_treenode *root);
int	mock_13_tree(t_treenode *root);
int	mock_13_tree_expanded(t_treenode *root);
int	mock_14_tree(t_treenode *root);
int	mock_14_tree_expanded(t_treenode *root);
int	mock_15_tree(t_treenode *root);
int	mock_15_tree_expanded(t_treenode *root);
int	mock_16_tree(t_treenode *root);
int	mock_16_tree_expanded(t_treenode *root);
int	mock_17_tree(t_treenode *root);
int	mock_17_tree_expanded(t_treenode *root);
int	mock_18_tree(t_treenode *root);
int	mock_18_tree_expanded(t_treenode *root);
int	mock_19_tree(t_treenode *root);
int	mock_19_tree_expanded(t_treenode *root);
int	mock_20_tree(t_treenode *root);
int	mock_20_tree_expanded(t_treenode *root);
int	mock_21_tree(t_treenode *root);
int	mock_21_tree_expanded(t_treenode *root);
int	mock_22_tree(t_treenode *root);
int	mock_22_tree_expanded(t_treenode *root);
int	mock_23_tree(t_treenode *root);
int	mock_23_tree_expanded(t_treenode *root);
int	mock_24_tree(t_treenode *root);
int	mock_24_tree_expanded(t_treenode *root);
int	mock_25_tree(t_treenode *root);
int	mock_25_tree_expanded(t_treenode *root);
int	mock_26_tree(t_treenode *root);
int	mock_26_tree_expanded(t_treenode *root);
int	mock_27_tree(t_treenode *root);
int	mock_27_tree_expanded(t_treenode *root);
int	mock_28_tree(t_treenode *root);
int	mock_28_tree_expanded(t_treenode *root);
int	mock_29_tree(t_treenode *root);
int	mock_29_tree_expanded(t_treenode *root);
int	mock_30_tree(t_treenode *root);
int	mock_30_tree_expanded(t_treenode *root);
int	mock_31_tree(t_treenode *root);
int	mock_31_tree_expanded(t_treenode *root);
int	mock_32_tree(t_treenode *root);
int	mock_32_tree_expanded(t_treenode *root);
#endif
