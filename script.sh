echo "enter choice"
read choice
case $choice in
echo "ascending order"
echo "descending order"
echo "Exit"
1)
echo "enter a number"
read -a my_array
len=${#my_array[@]}

for(i=0;i<len-1;i++)
do
    for(j=1;i<len-1;j++)
    do
        if(my_array[j] -lt my_array[i])
        then
            temp=a[i]
            a[i]=a[j]
            a[j]=temp
        fi
    done
done
