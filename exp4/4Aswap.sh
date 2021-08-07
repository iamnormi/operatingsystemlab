# Swapping values – swap.sh
echo -n "Enter value for A : "
read a
echo -n "Enter value for B : "
read b
t=$a
a=$b
b=$t
echo "Values after Swapping"
echo "A Value is $a and B Value is $b"