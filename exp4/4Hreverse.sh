# To reverse a number – reverse.sh
echo -n "Enter a number : "
read n
rd=0
while [ $n -gt 0 ]
do
    rem=`expr $n % 10`
    rd=`expr $rd \* 10 + $rem`
    n=`expr $n / 10`
done
echo "Reversed number is $rd"