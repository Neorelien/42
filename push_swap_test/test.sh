#!/bin/bash
while true
do 
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
var=`./push_swap $ARG | wc -l`
if [ $var -ge 5500 ]
then
	echo TOO MUCH MOVE 500
	echo $ARG > KO
fi
if ( ./push_swap $ARG | ./checker $ARG | grep KO )
	then
		echo NOT SORT 500
		echo $ARG > KO
fi
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
var=`./push_swap $ARG | wc -l`
if [ $var -ge 700 ]
then
	echo TOO MUCH MOVE 100
	echo $ARG > KO
fi
if ( ./push_swap $ARG | ./checker $ARG | grep KO )
	then
		echo NOT SORT 100
		echo $ARG > KO
	fi
echo OK >> 5
done

