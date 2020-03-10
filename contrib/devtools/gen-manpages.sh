#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

PIGYCOIND=${PIGYCOIND:-$BINDIR/pigycoind}
PIGYCOINCLI=${PIGYCOINCLI:-$BINDIR/pigycoin-cli}
PIGYCOINTX=${PIGYCOINTX:-$BINDIR/pigycoin-tx}
PIGYCOINQT=${PIGYCOINQT:-$BINDIR/qt/pigycoin-qt}

[ ! -x $PIGYCOIND ] && echo "$PIGYCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
PIGYVER=($($PIGYCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for pigycoind if --version-string is not set,
# but has different outcomes for pigycoin-qt and pigycoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$PIGYCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $PIGYCOIND $PIGYCOINCLI $PIGYCOINTX $PIGYCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${PIGYVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${PIGYVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
