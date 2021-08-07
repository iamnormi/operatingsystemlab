# Biggest – big3.sh
echo -n "Give value for A B and C: "
read a b c
if [ $a -gt $b -a $a -gt $c ]
then
    echo "A is the Biggest number"
elif [ $b -gt $c ]
then
    echo "B is the Biggest number"
else
    echo "C is the Biggest number"
fi