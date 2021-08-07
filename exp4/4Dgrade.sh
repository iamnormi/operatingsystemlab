# Grade – grade.sh
echo -n "Enter the mark : "
read mark
if [ $mark -gt 90 ]
then
    echo "S Grade"
elif [ $mark -gt 80 ]
then
    echo "A Grade"
elif [ $mark -gt 70 ]
then
    echo "B Grade"
elif [ $mark -gt 60 ]
then
    echo "C Grade"
elif [ $mark -gt 55 ]
then
    echo "D Grade"
elif [ $mark -ge 50 ]
then
    echo "E Grade"
else
    echo "U Grade"
fi