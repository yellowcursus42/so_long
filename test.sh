#!/bin/bash

# Assuming your_program is located in the same directory as the script
your_program="./so_long"

"$your_program" 
"$your_program" ./assets/maps/valid/map1.ber ./assets/maps/valid/map2.ber
"$your_program" dsldsfdsf.ber
"$your_program" dsldsfdsf
# Loop through all files in the current directory
for file in ./assets/maps/invalid/*; do
	echo "$file"
	valgrind "$your_program" "$file"
done
