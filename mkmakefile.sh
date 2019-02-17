#!/bin/sh

TARGETS=`ls *.c`
SRC="`echo \"${TARGETS}\" | fmt -60 | sed -e 's/^/	/' -e '$!s/$/ \\\/'`"
BIN=`echo "$SRC" | sed 's/\.c//g'`
echo "$TARGETS" | sed 's/\.c//'  >.gitignore

cat <<EOF
# XXX Autogenerated - do not edit
# Makefile for cs201 C examples

CC = gcc
CFLAGS = -Wall -g

SRC = $SRC

BIN = $BIN

all: \$(BIN)

EOF

for S in $TARGETS
do
    B=`echo $S | sed 's/\.c//'`
    D="$B: $S"
    M="	\$(CC) \$(CFLAGS) -o $B $S"
    if [ -f $B.mk ]
    then
        case "`wc -l <$B.mk`" in
            0)
                echo "error: empty $B.mk" >&2
                exit 1
                ;;
            1)
                echo "$D"
                echo -n '	'
                cat $B.mk
                ;;
            *)
                cat $B.mk
                ;;
        esac
    else
        echo "$D"
        echo "$M"
    fi
    echo ""
done

cat extra.mk
echo ""

cat <<EOF
clean:
	-rm -f *.o *.s \$(BIN)
EOF
