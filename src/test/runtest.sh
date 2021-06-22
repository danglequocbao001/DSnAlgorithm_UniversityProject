GRAY='\033[1;30m'; YELLOW='\033[1;33m'
BLUE='\033[0;34m'; NC='\033[0m'
BOLD='\e[1m'

stucked=()
total=0

selected_file=$1

test_files=$(find $(pwd) | grep "test.*.c")

printf "" > test_output

for test in $test_files; do
        
    total=$((total+1))
	
    cd $(dirname ${test})

    printf "> [ Run Test ${YELLOW}${test}${NC} ]\n"
	
    current_dict=$(cd -)
    bname=$(basename ${test})

    if [ "$bname" = "$selected_file" ]; then
	g++ $bname -o ./$bname.out && ./$bname.out && rm ./a.out
	return_code=$?
    else
	g++ $bname -o ./a.out && ./a.out >> $current_dict/test_output && rm ./a.out
	return_code=$?
    fi

    cd $current_dict

    if [[ $return_code -eq 0 ]]; then
	printf "${BLUE}${BOLD}\n\t◁ PASS ✔ ▷\n\n${NC}"
    else
	printf "${YELLOW}${BOLD}\n\t◁ STUCK ✘ ▷\n\n${NC}"
        stucked=( "${stucked[@]}" "$bname" )
    fi

done

printf "\n${BLUE}${BOLD}⚠ Stucked: ${YELLOW}${#stucked[@]}${NC}/${BLUE}$total${NC}\n"
for file in ${stucked[@]}; do
    printf "${YELLOW}\t➤  $file${NC}\n"
done
echo

if [ ${#stucked[@]} -ne "0" ]; then
	exit 1
fi
