/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:59:03 by awery             #+#    #+#             */
/*   Updated: 2020/11/17 16:27:31 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_memset(void *s, int c, size_t n);


int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;

    /* Display the initial values */
    for(int  length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    ft_memset( array, -2, size );

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

     /* Reset the memory bloc */
    memset( array, -2, size );

    /* Display the new values */
    for( int length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    return 0;
}
