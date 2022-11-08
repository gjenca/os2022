#!/usr/bin/env bash
TITLE="Gallery"
PERC="15"
while true
do
if [ "$1" == "-t" ]
then
	TITLE="$2"
	shift 2
elif test "$1" == "-p"
then
	PERC="$2"
	shift 2
else
	break
fi
done

cat << THEEND
<html>
<body>
<h1>$TITLE</h1>
<ul>
THEEND

mkdir -p mini

while [ "$#" != 0 ]
do
MININAME=$(echo $1 | sed 's/\.jpg$/.png/')
convert -resize "$PERC%" "$1" "mini/$MININAME"
echo '<li>'
echo '<a href="'"$1"'">'
echo '<img src="'"mini/$MININAME"'">'
echo '</a>'
echo '</li>'
shift
done 
cat <<THEEND
</ul>
</body>
</html>
THEEND
