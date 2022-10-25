#!/usr/bin/env bash
for X in $(seq 10)
do
	for Y in $(seq 10)
	do
		echo "$X*$Y="$(echo "$X*$Y" | bc)
	done
done

