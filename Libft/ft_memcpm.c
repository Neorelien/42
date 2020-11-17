/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:59:03 by awery             #+#    #+#             */
/*   Updated: 2020/11/17 18:45:02 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    char src[] = "oui";
    size_t n = sizeof( char ) * 2;

    /* Display the initial values */
    for(int  length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    printf("%p\n", ft_memcpy( array, src, n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

     /* Reset the memory bloc */
    printf("%p\n", memcpy( array, src, n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );


    return 0;
}
