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

${PUSH_SWAP} `ruby -e "puts (-49..450).to_a.shuffle.join(' ')"`
	printf ${GREEN}"\t...\n\n"${RESET};
python3 visualizer.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`

# LOOP INF # ./push_swap 37 29 -14 35 -18 -5 25 46 41 54 48 82 17 75 -3 47 87 19 43 68 -1 -15 -12 77 60 28 34 49 30 65 89 8 10 64 74 -10 81 44 -2 63 69 16 59 6 3 42 50 5 -17 40 52 22 36 12 86 13 84 26 57 -9 51 67 85 78 23 83 27 -4 -6 0 70 -16 76 62 39 53 1 58 18 61 79 -13 11 -8 4 14 -11 33 32 45 31 9 56 80 66 7 24 73 21 71 15 -19 88 55 2 38 -7 20 72
