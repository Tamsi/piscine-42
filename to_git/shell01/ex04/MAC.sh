ifconfig | grep ether | tr -d '\t' | cut -c 6- | tr -d ' '