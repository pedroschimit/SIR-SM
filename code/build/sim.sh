#!/bin/bash
function Simule() {
    echo -e "Simule(): SIR "
    printf 'Simule(): C \tmin=%-15d max=%-15d step=%-15d\n' $Cmin $Cmax $Cstep
    printf 'Simule(): SIM \tmin=%-15d max=%-15d step=%-15d\n' $SIMmin $SIMmax $SIMstep
    echo -e "Simule(): MAXCORES=$MAXCORES\n\n"

    for C in $(eval echo "{$Cmin..$Cmax..$Cstep}"); do 
        for SIM in $(eval echo "{$SIMmin..$SIMmax..$SIMstep}"); do
			CTRL=1
			while [ $CTRL -eq 1 ]; do
				PSOUT=$(echo $(ps o psr= -C sir))
				for PSR in $(eval echo "{2..$MAXCORES..1}"); do
					if [ -z "$(echo $PSOUT | grep $PSR)" ]; then
						/bin/echo -e "[$(date +%H:%M:%S)][SIR][CPU $PSR] \e[1;34m./sir --C $C \e[0m"
						taskset -c $PSR ./sir --C $C &>/dev/null &
						sleep 0.1s
						let "CTRL++"
						break
					fi
				done
				sleep 0.1s
			done
        done
    done
}

MAXCORES=$(($(grep -c ^processor /proc/cpuinfo)-2))

Cmin=1
Cmax=10
Cstep=1
SIMmin=1
SIMmax=10
SIMstep=1

Simule
