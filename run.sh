#!/bin/bash

GREEN="\033[1;32m"
YELOW="\033[1;33m"
REDCL="\033[1;31m"
RESET="\033[0m"

RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'

printf ${YELLOW}"\n--------> TESTS CREATED BY: "${RESET};
printf ${CYAN}"ABADOUAB\t\n\n"${RESET};

PUSH_SWAP="./push_swap"

if [ -f "push_swap" ]; then
	printf ${GREEN}"\t...\n\n"${RESET};
else
	printf ${RED}"\tNO EXIST PUSH_SWAP PROGRAM ...\n\n"${RESET};
	exit 0
fi

#            Test Cases Of 3          #

printf ${GREEN}"\tAll The Test Cases Of 3 Numbers ...\n\n"${RESET};

COMBINATIONS_3=(
	"1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"
)

test_combinations_3()
{
	max_actions=0
	min_actions=9999999
	total_actions=0

	for combination in "${COMBINATIONS_3[@]}"; do
		actions=$($PUSH_SWAP $combination | wc -l)
		total_actions=$((total_actions + actions))

	if (( actions > max_actions )); then
		max_actions=$actions
	fi

	if (( actions < min_actions )); then
		min_actions=$actions
	fi

	echo "Combination: $combination | Actions: $actions"
	done

	average_actions=$((total_actions / ${#COMBINATIONS_3[@]}))

	echo -e
	printf "\\033[1;31mMax Actions: $max_actions\\n"${RESET};
	printf "\\033[1;32mMin Actions: $min_actions\\n"${RESET};
	printf "\\033[1;33mAverage Actions:    $average_actions\n\n"${RESET};
}

test_combinations_3

#            Test Cases Of 4          #

printf ${GREEN}"\tAll The Test Cases Of 4 Numbers ...\n\n"${RESET};

COMBINATIONS_4=(
	"1 2 4 3" "1 3 2 4" "1 3 4 2" "1 4 2 3" "1 4 3 2" "2 1 3 4" "2 1 4 3" "2 3 1 4"
	"2 3 4 1" "2 4 1 3" "2 4 3 1" "3 1 2 4" "3 1 4 2" "3 2 1 4" "3 2 4 1" "3 4 1 2"
	"3 4 2 1" "4 1 2 3" "4 1 3 2" "4 2 1 3" "4 2 3 1" "4 3 1 2" "4 3 2 1"
)

test_combinations_4()
{
	max_actions=0
	min_actions=9999999
	total_actions=0

	for combination in "${COMBINATIONS_4[@]}"; do
		actions=$($PUSH_SWAP $combination | wc -l)
		total_actions=$((total_actions + actions))

	if (( actions > max_actions )); then
		max_actions=$actions
	fi

	if (( actions < min_actions )); then
		min_actions=$actions
	fi

	echo "Combination: $combination | Actions: $actions"
	done

	average_actions=$((total_actions / ${#COMBINATIONS_4[@]}))

	echo -e
	printf "\\033[1;31mMax Actions: $max_actions\\n"${RESET};
	printf "\\033[1;32mMin Actions: $min_actions\\n"${RESET};
	printf "\\033[1;33mAverage Actions:    $average_actions\n\n"${RESET};
}

test_combinations_4

#            Test Cases Of 5          #

printf ${GREEN}"\tAll The Test Cases Of 5 Numbers ...\n\n"${RESET};

COMBINATIONS_5=(
	"1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3" "1 3 2 4 5"
	"1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2" "1 4 2 3 5"
	"1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2" "1 5 2 3 4"
	"1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2" "2 1 3 4 5"
	"2 1 3 5 4" "2 1 4 3 5" "2 1 4 5 3" "2 1 5 3 4" "2 1 5 4 3" "2 3 1 4 5"
	"2 3 1 5 4" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 3 5 4 1" "2 4 1 3 5"
	"2 4 1 5 3" "2 4 3 1 5" "2 4 3 5 1" "2 4 5 1 3" "2 4 5 3 1" "2 5 1 3 4"
	"2 5 1 4 3" "2 5 3 1 4" "2 5 3 4 1" "2 5 4 1 3" "2 5 4 3 1" "3 1 2 4 5"
	"3 1 2 5 4" "3 1 4 2 5" "3 1 4 5 2" "3 1 5 2 4" "3 1 5 4 2" "3 2 1 4 5"
	"3 2 1 5 4" "3 2 4 1 5" "3 2 4 5 1" "3 2 5 1 4" "3 2 5 4 1" "3 4 1 2 5"
	"3 4 1 5 2" "3 4 2 1 5" "3 4 2 5 1" "3 4 5 1 2" "3 4 5 2 1" "3 5 1 2 4"
	"3 5 1 4 2" "3 5 2 1 4" "3 5 2 4 1" "3 5 4 1 2" "3 5 4 2 1" "4 1 2 3 5"
	"4 1 2 5 3" "4 1 3 2 5" "4 1 3 5 2" "4 1 5 2 3" "4 1 5 3 2" "4 2 1 3 5"
	"4 2 1 5 3" "4 2 3 1 5" "4 2 3 5 1" "4 2 5 1 3" "4 2 5 3 1" "4 3 1 2 5"
	"4 3 1 5 2" "4 3 2 1 5" "4 3 2 5 1" "4 3 5 1 2" "4 3 5 2 1" "4 5 1 2 3"
	"4 5 1 3 2" "4 5 2 1 3" "4 5 2 3 1" "4 5 3 1 2" "4 5 3 2 1" "5 1 2 3 4"
	"5 1 2 4 3" "5 1 3 2 4" "5 1 3 4 2" "5 1 4 2 3" "5 1 4 3 2" "5 2 1 3 4"
	"5 2 1 4 3" "5 2 3 1 4" "5 2 3 4 1" "5 2 4 1 3" "5 2 4 3 1" "5 3 1 2 4"
	"5 3 1 4 2" "5 3 2 1 4" "5 3 2 4 1" "5 3 4 1 2" "5 3 4 2 1" "5 4 1 2 3"
	"5 4 1 3 2" "5 4 2 1 3" "5 4 2 3 1" "5 4 3 1 2" "5 4 3 2 1"
)

test_combinations_5()
{
	max_actions=0
	min_actions=9999999
	total_actions=0

	for combination in "${COMBINATIONS_5[@]}"; do
		actions=$($PUSH_SWAP $combination | wc -l)
		total_actions=$((total_actions + actions))

	if (( actions > max_actions )); then
		max_actions=$actions
	fi

	if (( actions < min_actions )); then
		min_actions=$actions
	fi

	echo "Combination: $combination | Actions: $actions"
	done

	average_actions=$((total_actions / ${#COMBINATIONS_5[@]}))

	echo -e
	printf "\\033[1;31mMax Actions: $max_actions\\n"${RESET};
	printf "\\033[1;32mMin Actions: $min_actions\\n"${RESET};
	printf "\\033[1;33mAverage Actions:    $average_actions\\n"${RESET};
}

test_combinations_5

#            Visualizer          #

python3 python_visualizer.py `ruby -e "puts (-9..10).to_a.shuffle.join(' ')"`
