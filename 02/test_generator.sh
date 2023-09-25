#!/bin/bash

#cimpile list
g++ -std=c++17 -O2 -Wall -Wextra random.cpp list.cpp -o random_list

# ompile vector
g++ -std=c++17 -O2 -Wall -Wextra random.cpp vector.cpp -o random_vector

# generate input arguments
generate_inputs() {
    local value=10
    local factor=1.78
    while (( value < 1000000 )); do
        echo $value
        value=$(printf "%.0f\n" $(echo "$value * $factor" | bc))
    done
}

# Run the program with generated input arguments for std::list
echo "Running tests for std::list..."
for i in $(generate_inputs); do
    ./random_list $i
done

# Run the program with generated input arguments for std::vector