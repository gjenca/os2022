#!/usr/bin/env bash
MENO="$1 $2"

ldapsearch -h ldap.stuba.sk -b 'dc=stuba,dc=sk' -x gecos="$MENO" | grep '^telephoneNumber:' | sed 's/^[^ ]* //i'
