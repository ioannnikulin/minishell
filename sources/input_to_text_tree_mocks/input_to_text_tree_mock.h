/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:19:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 21:43:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_TO_TEXT_TREE_MOCK_H
# define INPUT_TO_TEXT_TREE_MOCK_H
# include "../minishell.h"

# define MOCK_0_TEXT "echo hello world"
# define MOCK_1_TEXT "   echo hello\\n		my\n ope\nworld "
# define MOCK_2_TEXT "\echo \"1   2\"   3"
# define MOCK_3_TEXT "mkdir testf && cd -L testf &&\
mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt"
# define MOCK_4_TEXT "echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6"
# define MOCK_5_TEXT "echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 \
&& echo 6)"
# define MOCK_6_TEXT "echo 1 || echo 2 && ((echo 3 && echo 4 || ((echo 5) \
&& echo 6)))"

int			input_to_text_tree_mock(t_tree **tree, char *input);
void		mock_0_tree(t_treenode *root);
void		mock_1_tree(t_treenode *root);
void		mock_2_tree(t_treenode *root);
void		mock_3_tree(t_treenode *root);
void		mock_4_tree(t_treenode *root);
void		mock_5_tree(t_treenode *root);
void		mock_6_tree(t_treenode *root);
#endif