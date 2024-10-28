#!/bin/bash

source_file="MSFT.txt"
destination_file="MSFT.txt"

echo "Dest file "$destination_file
echo "src file "$source_file

for (( i=2001; i<4000; i++ )); do
	new_destination_file=$destination_file"_"$i
	cp -rp $source_file $new_destination_file
done
