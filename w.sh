COLOR=30
while true
do
	echo -e "\033[0;${COLOR}m Je t'aime le GOAT !"
	sleep .2
	if (("$COLOR" == 37)) ; then
		COLOR=30
	else
		COLOR=$((COLOR+1))
	fi
done