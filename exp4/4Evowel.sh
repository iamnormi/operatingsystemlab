# Vowel - vowel.sh
echo -n "Key in a lower case character : "
read choice
case $choice in
     a|e|i|o|u) echo "It's a Vowel";;
             *) echo "It's a Consonant"
esac