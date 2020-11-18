/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:59:03 by awery             #+#    #+#             */
/*   Updated: 2020/11/17 23:53:20 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_memcmp(void *s1, const void *s2, size_t n);

int main() {

    char  array [] = "ouu";;
    char src[] = "oup";
    size_t n = sizeof( char ) * 1;

    /* Display the initial values */
    for(int  length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    printf("%d\n", ft_memcmp( array, src, n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

     /* Reset the memory bloc */
    printf("%d\n", memcmp( array, src, n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );


    return 0;
}
