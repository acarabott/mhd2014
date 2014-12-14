#!/bin/sh

rm out
for i in *
do
  if [ $i = "concat.sh" ]
  then
    continue
  fi
  echo $i >> out
  cat $i  >> out
done

