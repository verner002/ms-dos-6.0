bins    =..\..\..\binaries
cprs    =..\..\..\compress
dest    =4208.cpi
cpr     =4208.cp_



!IFNDEF       BUILDER

all:

!ELSE

all:  $(bins)\$(dest) $(cprs)\$(cpr)

$(bins)\$(dest): $(dest)
            copy $(dest) $(bins)

$(cprs)\$(cpr):  $(cpr)
            copy $(cpr) $(cprs)

$(cpr):       $(dest)
              $(compress) $(dest) $(cpr)


!ENDIF
