#!/bin/bash
#----------------------------------------------------------------------#
# cpScript: Handy automation scripts for Google Code Jam (for C++)
#               Written by Vivek Patel - 2017
# 
# Init           :  Initializes a contest round's folder with a
#                   brute-force, generator, and optimized(final)
#                   cpp program file for each problem using provided
#                   template.cpp file and gen.cpp file
#
# Stress-Test    :  Requires brute-force, generator, and optimized
#                   program to work. Keeps on generating inputs and
#                   testing brute outputs against optimized program's
#                   output until discrepancies are found. 
#
# Observe        :  Requires only brute-force and generator program.
#                   Generates input and shows brute-forced output at
#                   regular intervals(in seconds)
#----------------------------------------------------------------------#

CXX="g++"
CXXFLAGS="-std=c++11"
LDFLAGS=""
INTERVAL=30

function checkdiffs
{
  cmp -s output1 output2
}

function init
{
  local PROBS
  local DIRNAME
  local NAMES="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" 

  echo Enter no. of problems:
  read PROBS

  echo Enter new directory name:
  read DIRNAME

  mkdir "$DIRNAME"

  local CTR=0
  for i in $NAMES; do
    if [ $CTR -lt $PROBS ]; then
      cp template.cpp "$DIRNAME"/"$i".cpp
      cp gen.cpp "$DIRNAME"/"$i"_gen.cpp
      sed -i "s/A-small/"$i"-small/g" "$DIRNAME"/"$i".cpp
      sed -i "s/A-large/"$i"-large/g" "$DIRNAME"/"$i".cpp
      cp "$DIRNAME"/"$i".cpp "$DIRNAME"/"$i"_brute.cpp
      let CTR+=1
    else
      break
    fi
  done

  cp cpScript.sh "$DIRNAME/cpScript.sh" 
}

function stressTest
{
  local PNAME
  local feed
  local ctr=1

  echo Enter problem name:
  read PNAME

  "$CXX" "$PNAME"_gen.cpp -o "$PNAME"_gen "$CXXFLAGS"
  "$CXX" "$PNAME"_brute.cpp -o "$PNAME"_brute "$CXXFLAGS"
  "$CXX" "$PNAME".cpp -o "$PNAME" "$CXXFLAGS"

  while [ 1 ]; do
    feed="$( { cat input; md5sum output2; cat output1; echo $RANDOM; cat output2; md5sum output1; date; md5sum input;} | tr "\n" " " )"
    ./"$PNAME"_gen "${feed}" > input
    ./"$PNAME"_brute < input > output1
    ./"$PNAME" < input > output2
    checkdiffs
    if [ $? -gt 0 ]; then
      cat input > "$PNAME"_WAinput
      diff output1 output2 > "$PNAME"_WAdiff
      echo "WA test case found"
      break
    fi
    printf "\rTest passes: $ctr"
    let ctr+=1
  done
}

function observe
{
  local PNAME
  local feed
  local salt="Necroté"

  echo Enter problem name:
  read PNAME

  "$CXX" "$PNAME"_gen.cpp -o "$PNAME"_gen "$CXXFLAGS"
  "$CXX" "$PNAME"_brute.cpp -o "$PNAME"_brute "$CXXFLAGS"

  while [ 1 ]; do
    feed="$( { cat input;cat output1; echo "$salt"; echo $RANDOM; md5sum output1; date; md5sum input;} | tr "\n" " " )"
    ./"$PNAME"_gen "${feed}" > input
    ./"$PNAME"_brute < input > output1
    echo "input:"
    cat input
    echo "output:"
    cat output1
    echo "Press Esc to stop, 's' to input additional salt content."
    read -s -N 1 -t "$INTERVAL" key

    if [ "$key" = $'\e' ]; then
      echo -e "\nQuitting..."
      break
    elif [ "$key" = $'\x73' ]; then
      echo "Enter salt content: "
      read salt
    fi
  done
}

OPTIONS="Init Stress-Test Observe Exit"
select opt in $OPTIONS; do
 if [ "$opt" = "Init" ]; then
  init
  exit
elif [ "$opt" = "Stress-Test" ]; then
  stressTest
  exit
elif [ "$opt" = "Observe" ]; then
  observe
  exit
elif [ "$opt" = "Exit" ]; then
  exit
else
  clear
  echo bad option
fi
done