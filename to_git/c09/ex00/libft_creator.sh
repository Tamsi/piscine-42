# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 16:42:54 by tbesson           #+#    #+#              #
#    Updated: 2021/09/30 16:47:36 by tbesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c *.c && ar rcs libft.a *.o && rm *.o