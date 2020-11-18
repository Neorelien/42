/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:59:03 by awery             #+#    #+#             */
/*   Updated: 2020/11/17 22:41:46 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n);

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    int src[] = {1,2, 7};
    size_t n = sizeof( int ) * 0;

    /* Display the initial values */
    for(int  length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    printf("%p\n", ft_memmove( array, src, n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

     /* Reset the memory bloc */
    printf("%p\n", memmove( array, src,  n ));

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );


    return 0;
}
